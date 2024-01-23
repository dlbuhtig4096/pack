/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
yay0.c
用於處理壓縮格式

*/

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
// 選項

// 在壓縮和解壓縮的同時進行邊界檢查
#define YAY0_CHECK

// 是不是當作軟體庫使用
// #define YAY0_MODULE

// 如果邊界檢查出錯的話 印出錯誤訊息到 console
#define YAY0_ERROR

// 印出壓縮和解壓縮進程中除錯資訊 只用於開發本軟體庫
// #define YAY0_DEBUG

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <env.h>

#if defined(YAY0_MODULE) || defined(YAY0_ERROR) || defined(YAY0_DEBUG)
#include <stdlib.h>
#include <stdio.h>
#endif // defined(YAY0_ERROR) || defined(YAY0_DEBUG)

#if !defined(YAY0_MODULE)
#include <memory.h>
#endif // !defined(YAY0_MODULE)

#ifdef YAY0_ERROR
#define yay0_error(...)  printf(__VA_ARGS__); fflush(stdout);
#else
#define yay0_error(...)
#endif // YAY0_ERROR

#ifdef YAY0_DEBUG
#define yay0_debug(...)  printf(__VA_ARGS__); fflush(stdout);
#else
#define yay0_debug(...)
#endif // YAY0_ERROR

// yay0_win_size = 0x1u << yay0_win_bits
// yay0_win_mask = yay0_win_size - 0x1
#define yay0_win_bits 0x000cull
#define yay0_win_size 0x1000ull
#define yay0_win_mask 0x0fffull
#define yay0_ref_init 0x0000ull

// lz_cache_page = lz_win_size / bitsof(u64) = 0x1u << yay0_cache_bits
// lz_cache_size = lz_cache_page * yay0_max_size
// yay0_max_size = 0xff + 0x12 = 0x111
#define yay0_cache_page 0x0040ull
#define yay0_cache_mask 0x003full
#define yay0_cache_bits 0x0006ull
#define yay0_cache_size 0x4440ull

//
#define yay0_lnk_size   0x10000ull
#define yay0_ctr_size   0x10000ull

/*
yay0Decode
@inputs:
    dst : 輸出地址
    src : 輸入地址
    dcnt: 輸出地址的空間大小
    scnt: 輸入大小
@output:
    結束時的 dst 指標
*/
static inline __attribute__((always_inline))
u8* yay0Decode(u8 *dst, u8 *src, uptr dcnt, uptr scnt) {
    uptr ref_lnk, ref_ctr, ref_flag, ref_mask;

    // 初始化
    scnt = (uptr)src + scnt;
    dcnt = (uptr)dst + bswap32(*(u32*)&src[0x4]);
    ref_lnk = (uptr)src + bswap32(*(u32*)&src[0x8]);
    ref_ctr = (uptr)src + bswap32(*(u32*)&src[0xc]);
    ref_flag = 0x0; ref_mask = 0x0;
    src += 0x10;

    do {

        // 判斷是不是已經讀取超過 32 次
        if (!ref_mask) {
            ref_flag = bswap32(*(u32*)src);
            ref_mask = 0x1u << 0x1f;
            src += 0x4;
            yay0_debug("[flg] r = 0x%llx, flag = 0x%llx, mask = 0x%llx\n", scnt - (uptr)src, ref_flag, ref_mask);
        }        

        // 判斷是不是參照模式
        // 1 : 明文
        // 0 : 參照
        if (ref_flag & ref_mask) {
            // 明文模式
            yay0_debug("[ctr] r = 0x%llx, c = 0x%llx\n", dcnt - (uptr)dst, *(u8*)ref_ctr);
            *dst = *(u8*)ref_ctr;
            dst++; ref_ctr++;
        }
        else {
            // 參照模式
            uptr ref_off, ref_len;

            // 參照紀錄
            ref_off = bswap16(*(u16*)ref_lnk); ref_lnk += 0x2;
            ref_len = ref_off >> yay0_win_bits;
            ref_off &= yay0_win_mask;

            // 從 counter table 取得參照長度
            if (!ref_len) {
                ref_len = *(u8*)ref_ctr + 0x10; // 0x12 - 0x2;
                ref_ctr++;
            }
            yay0_debug("[ref] r = 0x%llx, o = 0x%llx, l = 0x%llx\n", dcnt - (uptr)dst, ref_off, ref_len);
            ref_off++; ref_len += 0x2;

            // 複製
            do {
                *dst = dst[-ref_off]; dst++;
            } while (--ref_len);
        }

        // 更新參照標籤
        ref_mask >>= 0x1;

    } while ((uptr)dst < dcnt);

__yay0Decode_finish:
    return dst;
}

/*
yay0Encode
@inputs:
    dst : 輸出地址
    src : 輸入地址
    dcnt: 輸出地址的空間大小
    scnt: 壓縮前大小
@output:
    結束時的 dst 指標
*/
static inline __attribute__((always_inline))
u8* yay0Encode(u8 *dst, u8 *src, uptr dcnt, uptr scnt) {
    uptr ref_flag, ref_mask;
    u8 *pLdr, *pDat, *pCtr, ref_ctr[yay0_ctr_size];
    u16 *pLnk, ref_lnk[yay0_lnk_size]; 
    u32 *pRef;
    u64 *pWriter, *pReader, ref_cache[yay0_cache_size];

    // 初始化
    ref_flag = 0x0;
    ref_mask = 0x1u << 0x1f;
    dcnt = dcnt + (uptr)dst;
    scnt = scnt + (uptr)src;
    pReader = &ref_cache[yay0_cache_size];
    pWriter = &ref_cache[yay0_cache_size];
    pRef = (u32*)(dst + 0x10);
    pLnk = &ref_lnk[0x0];
    pCtr = &ref_ctr[0x0];
    pLdr = src;
    pDat = src;

/* 
@inputs:
    pDst: Cache 指針
    pSrc: 輸入資料指針
    pTof: 輸入偏移
    pEof: 輸入資料頂端
    pTop: Cache 頂部指針
    __lbOnFinish: 如果 pSrc 超出 pEnd 時應該要跳到哪裡

填充 cache
*/
#define _YayE_FillLoop(pDst, pSrc, pTof, pEof, pTop, __lbOnFinish)             \
                                                                                \
do {                                                                            \
    u8 c = *pSrc, *p = &pSrc[-yay0_win_size];                                   \
    sptr nSrc = (u8*)pTof - p;                                                  \
                                                                                \
    /* Remainder */                                                             \
    /* yay0_debug("fill1: w = 0x%llX (0x%llX)\n", pDst - pTop, nSrc); */         \
    if (nSrc > 0) {                                                             \
        p += nSrc;                                                              \
        while (nSrc >= 0x40) { nSrc -= 0x40; pDst--; *pDst = 0x0; }             \
        if (p < pSrc) {                                                         \
            u64 out = 0x0;                                                      \
            switch (-nSrc & 0x3f) {                                             \
            case 0x3f: out |= (u64)(*p++ == c) << 0x01;                         \
            case 0x3e: out |= (u64)(*p++ == c) << 0x02;                         \
            case 0x3d: out |= (u64)(*p++ == c) << 0x03;                         \
            case 0x3c: out |= (u64)(*p++ == c) << 0x04;                         \
            case 0x3b: out |= (u64)(*p++ == c) << 0x05;                         \
            case 0x3a: out |= (u64)(*p++ == c) << 0x06;                         \
            case 0x39: out |= (u64)(*p++ == c) << 0x07;                         \
            case 0x38: out |= (u64)(*p++ == c) << 0x08;                         \
            case 0x37: out |= (u64)(*p++ == c) << 0x09;                         \
            case 0x36: out |= (u64)(*p++ == c) << 0x0a;                         \
            case 0x35: out |= (u64)(*p++ == c) << 0x0b;                         \
            case 0x34: out |= (u64)(*p++ == c) << 0x0c;                         \
            case 0x33: out |= (u64)(*p++ == c) << 0x0d;                         \
            case 0x32: out |= (u64)(*p++ == c) << 0x0e;                         \
            case 0x31: out |= (u64)(*p++ == c) << 0x0f;                         \
            case 0x30: out |= (u64)(*p++ == c) << 0x10;                         \
            case 0x2f: out |= (u64)(*p++ == c) << 0x11;                         \
            case 0x2e: out |= (u64)(*p++ == c) << 0x12;                         \
            case 0x2d: out |= (u64)(*p++ == c) << 0x13;                         \
            case 0x2c: out |= (u64)(*p++ == c) << 0x14;                         \
            case 0x2b: out |= (u64)(*p++ == c) << 0x15;                         \
            case 0x2a: out |= (u64)(*p++ == c) << 0x16;                         \
            case 0x29: out |= (u64)(*p++ == c) << 0x17;                         \
            case 0x28: out |= (u64)(*p++ == c) << 0x18;                         \
            case 0x27: out |= (u64)(*p++ == c) << 0x19;                         \
            case 0x26: out |= (u64)(*p++ == c) << 0x1a;                         \
            case 0x25: out |= (u64)(*p++ == c) << 0x1b;                         \
            case 0x24: out |= (u64)(*p++ == c) << 0x1c;                         \
            case 0x23: out |= (u64)(*p++ == c) << 0x1d;                         \
            case 0x22: out |= (u64)(*p++ == c) << 0x1e;                         \
            case 0x21: out |= (u64)(*p++ == c) << 0x1f;                         \
            case 0x20: out |= (u64)(*p++ == c) << 0x20;                         \
            case 0x1f: out |= (u64)(*p++ == c) << 0x21;                         \
            case 0x1e: out |= (u64)(*p++ == c) << 0x22;                         \
            case 0x1d: out |= (u64)(*p++ == c) << 0x23;                         \
            case 0x1c: out |= (u64)(*p++ == c) << 0x24;                         \
            case 0x1b: out |= (u64)(*p++ == c) << 0x25;                         \
            case 0x1a: out |= (u64)(*p++ == c) << 0x26;                         \
            case 0x19: out |= (u64)(*p++ == c) << 0x27;                         \
            case 0x18: out |= (u64)(*p++ == c) << 0x28;                         \
            case 0x17: out |= (u64)(*p++ == c) << 0x29;                         \
            case 0x16: out |= (u64)(*p++ == c) << 0x2a;                         \
            case 0x15: out |= (u64)(*p++ == c) << 0x2b;                         \
            case 0x14: out |= (u64)(*p++ == c) << 0x2c;                         \
            case 0x13: out |= (u64)(*p++ == c) << 0x2d;                         \
            case 0x12: out |= (u64)(*p++ == c) << 0x2e;                         \
            case 0x11: out |= (u64)(*p++ == c) << 0x2f;                         \
            case 0x10: out |= (u64)(*p++ == c) << 0x30;                         \
            case 0x0f: out |= (u64)(*p++ == c) << 0x31;                         \
            case 0x0e: out |= (u64)(*p++ == c) << 0x32;                         \
            case 0x0d: out |= (u64)(*p++ == c) << 0x33;                         \
            case 0x0c: out |= (u64)(*p++ == c) << 0x34;                         \
            case 0x0b: out |= (u64)(*p++ == c) << 0x35;                         \
            case 0x0a: out |= (u64)(*p++ == c) << 0x36;                         \
            case 0x09: out |= (u64)(*p++ == c) << 0x37;                         \
            case 0x08: out |= (u64)(*p++ == c) << 0x38;                         \
            case 0x07: out |= (u64)(*p++ == c) << 0x39;                         \
            case 0x06: out |= (u64)(*p++ == c) << 0x3a;                         \
            case 0x05: out |= (u64)(*p++ == c) << 0x3b;                         \
            case 0x04: out |= (u64)(*p++ == c) << 0x3c;                         \
            case 0x03: out |= (u64)(*p++ == c) << 0x3d;                         \
            case 0x02: out |= (u64)(*p++ == c) << 0x3e;                         \
            case 0x01: out |= (u64)(*p++ == c) << 0x3f;                         \
                pDst--; *pDst = out;                                            \
            }                                                                   \
            /* yay0_debug("%llx: %llx %llx\n", pDst - pTop, c, out); */          \
        }                                                                       \
    }                                                                           \
                                                                                \
    /* 更新 cache */                                                            \
    /* yay0_debug("fill2 : w = 0x%llX (0x%llx)\n", pDst - pTop, pSrc - p); */    \
    while (p < pSrc) {                                                          \
        pDst--;                                                                 \
        *pWriter =                                                              \
            ((*p++ == c) ? 0x0000000000000001ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000000002ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000000004ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000000008ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000000010ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000000020ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000000040ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000000080ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000000100ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000000200ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000000400ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000000800ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000001000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000002000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000004000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000008000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000010000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000020000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000040000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000080000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000100000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000200000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000400000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000000800000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000001000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000002000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000004000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000008000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000010000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000020000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000040000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000080000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000100000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000200000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000400000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000000800000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000001000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000002000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000004000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000008000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000010000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000020000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000040000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000080000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000100000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000200000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000400000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0000800000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0001000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0002000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0004000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0008000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0010000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0020000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0040000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0080000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0100000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0200000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0400000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x0800000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x1000000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x2000000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x4000000000000000ull : 0x0000000000000000ull) |     \
            ((*p++ == c) ? 0x8000000000000000ull : 0x0000000000000000ull)       \
        ;                                                                       \
    };                                                                          \
                                                                                \
    /* 更新 src 地址 */                                                          \
    pSrc++;                                                                     \
                                                                                \
    /* 如果 src 用完了就跳到最後的一次處理 */                                      \
    if ((uptr)pSrc >= pEof) {                                                   \
        /* 因為這時候寫端 < 讀端 所以消耗的時候跳過消耗到 stack 頂部的處理 */        \
        goto __lbOnFinish;                                                      \
    }                                                                           \
} while (pDst > pTop)

/*
@inputs:
    pDst: 最長的連續 1 指針
    nDst: 目前的長度
    nFlag: 目前的 mask
    pTop: Cache 頂端
    __lbNext: 掃描結束時要跳到哪裡

掃描 cache
*/
#define _YayE_ScanLoop(pDst, nDst, nFlag, pTop, __lbNext)                        \
                                                                                \
/*yay0_debug("scan_sub: 0x%llX / 0x%llX, n = 0x%llX\n", pDst, pTop, nDst);*/     \
                                                                                \
do {                                                                            \
    u64 nNext;                                                                  \
                                                                                \
    /* 掃描這一頁 */                                                             \
    nNext = nFlag & *pDst;                                                      \
                                                                                \
    /* 如果已經沒有 1 的 bit 則說明接下來都不連續 */                               \
    /* 這種情況就中斷掃描 */                                                      \
    if (!nNext) { goto __lbNext; }                                              \
                                                                                \
    /* 往前一頁 */                                                               \
    pDst -= yay0_cache_page;                                                    \
                                                                                \
    /* 更新 scan_flag */                                                        \
    nFlag = nNext;                                                              \
                                                                                \
    /* 增加參照長度 */                                                           \
    nDst++;                                                                     \
                                                                                \
    /* 判斷是不是碰到 cache 頂部 */                                               \
    /* 修正 : 這裡等於是有可能的 */                                               \
} while (pDst >= pTop);

/*

*/
#define _YayE_ScanNext(mOffset, mSize, nFlag, nSize, pDst, pSrc, pTop)          \
                                                                                \
{                                                                               \
    uptr nSlot = ((uptr)pDst - (uptr)(pTop)) & (yay0_cache_mask << 0x3);        \
                                                                                \
    /* 如果這次的長度比先前的長 則更新資訊 */                                      \
    if (nSize > mSize) {                                                        \
        mSize = nSize;                                                          \
        mOffset = (nSlot << 0x3) | clz64(nFlag);                                \
        /* for (sptr i = -3; i < mSize; i++) { */                                               \
            /* pDst += yay0_cache_page; */                                                      \
            /* yay0_debug("%llx (%llx): 0x%llx\n", pDst - pTop, pSrc - pTop, *pDst); */          \
        /* } */                                                                                 \
    }                                                                           \
                                                                                \
    /* 把掃描端移回原本的 page */                                                 \
    pDst = (u64*)((uptr)pSrc + nSlot);                                          \
}

/*

*/
#define _YayE_EmitRef(pDst, pSrc, pLnk, pCtr, mOffset, mSize)                   \
                                                                                \
{                                                                               \
    u32 n = mSize + 0x2;                                                        \
    pDst -= n << yay0_cache_bits;                                               \
    pSrc += n;                                                                  \
    mSize++;                                                                    \
                                                                                \
    yay0_debug("emit_ref: o = 0x%llX, l = 0x%llX\n", mOffset, mSize);            \
    if (mSize > 0xf) {                                                          \
        *pCtr = mSize - 0x10; pCtr++;                                           \
        mSize = 0x0;                                                            \
    }                                                                           \
    *pLnk = bswap16(mOffset | (mSize << 0xc)); pLnk++;                          \
                                                                                \
}


/*

*/
#define _YayE_EmitCtr(pDst, pSrc, nFlag, nMask)                                 \
                                                                                \
{                                                                               \
    yay0_debug("emit_ctr: c = 0x%llX\n", *pSrc);                                 \
    *pDst++ = *pSrc; /* pSrc++ 的操作在外面做 */                                 \
    nFlag |= nMask;                                                             \
}

#define _YayE_EmitNext(pDst, nFlag, nMask)                                          \
                                                                                \
{                                                                               \
    /* 更新參照標籤 */                                                           \
    nMask >>= 0x1;                                                              \
                                                                                \
    /* 判斷 flag 是否用盡 */                                                     \
    /* 用完了就寫回 並且借一個新的 */                                             \
    if (!nMask) {                                                               \
    yay0_debug("emit_flag: c = 0x%llX\n", nFlag);                                \
        *pDst = bswap32(nFlag); pDst++;                                         \
        nFlag = 0x0;                                                            \
        nMask = 0x1u << 0x1f;                                                   \
    }                                                                           \
}

__YayE_main:
    do {
        
        // 填滿 cache
        {
            // 如果讀端在寫端之上 則不需要填充到 stack 頂部
            // 否則填充直到碰到 stack 頂部
            // yay0_debug("refill1 : r = 0x%llX, w = 0x%llX, 0x%llx\n", pReader - ref_cache, pWriter - ref_cache, pWriter <= pReader);
            if (pWriter <= pReader) {
                _YayE_FillLoop(pWriter, pLdr, src, scnt, &ref_cache[0x0], __YayE_clean2);

                // 指回 stack 底部
                pWriter += yay0_cache_size;
            }

            // 如果讀端在寫端之前 (事實上應該要一致) 就結束補充 cache
            // 繼續填充直到讀端
            // yay0_debug("refill2 : r = 0x%llX, w = 0x%llX, 0x%llx\n", pReader - ref_cache, pWriter - ref_cache, pWriter > pReader);
            if (pWriter > pReader) { 
                _YayE_FillLoop(pWriter, pLdr, src, scnt, pReader, __YayE_clean1);
            }
        }
        // yay0_debug("refill_end : r = 0x%llX, w = 0x%llX\n", pReader - ref_cache, pWriter - ref_cache);
        
__YayE_main_scan:
        // 從 cache 中找出最長的連續 1
        {
            sptr mOffset, mSize = -0x1;
            u64 *pScan;

            // 從讀取端開始向上掃描
            pScan = pReader;
            pReader -= yay0_cache_page;
            do {
                sptr nSize = -0x3;
                u64 nFlag = -0x1;
                            
                // 把掃描端上移一個 slot
                pScan--;

                // 掃描整個 cahce 當中和 pScan 的特定 slot
                _YayE_ScanLoop(pScan, nSize, nFlag, &ref_cache[0x0], __YayE_main_scan_next);
                
                // 將掃描端指回 stack 底部
                pScan += yay0_cache_size;
                
                // 如果掃描端在寫端之上就結束
                // 修正 : 等於時其實可以繼續往下找一次 因為掃描端是先取值才遞減 同時也表示掃描端不可能會碰到 cache 底部 因此若寫入端位於 cache 底部 則等號不可能成立
                if (pScan >= pWriter) { _YayE_ScanLoop(pScan, nSize, nFlag, pWriter, __YayE_main_scan_next); }

__YayE_main_scan_next:
                _YayE_ScanNext(mOffset, mSize, nFlag, nSize, pScan, pReader, &ref_cache[0x0]);
            } while (pScan > pReader);

__YayE_main_scan_end:         

            // 接下來判斷長度夠不夠寫成參照紀錄
            // yay0_debug("scan_end: s = 0x%llX / 0x%llX\n", pDat, scnt);
            if (mSize >= 0x0) {
                // 參照模式
                _YayE_EmitRef(pReader, pDat, pLnk, pCtr, mOffset, mSize);
            }
            else {
                // 明文模式
                _YayE_EmitCtr(pCtr, pDat, ref_flag, ref_mask);
            }
            pDat++;
            // yay0_debug("write: s = 0x%llX / 0x%llX\n", pDat, scnt);

            // 如果讀端已經讀到 stack 頂部 則把它重新指回 stack 底部
            // 這個判斷必須放在參照模式寫入之後 因為減完 ref_size 之後 讀端有可能會指到 stack 頂端之上
            if (pReader <= ref_cache) { pReader += yay0_cache_size; }
        }

        // 更新參照標籤
        _YayE_EmitNext(pRef, ref_flag, ref_mask);

    } while ((uptr)src < scnt);

    // 讀端和寫端一樣的話則表示現在 cache 是空的 (因為前面有消耗過)
    // 這時候跳過清理 cache 的步驟
    if (pWriter == pReader) {
        goto __YayE_clean3;
    }

    // 接下來將剩下的 cache 消耗完畢就完成了 這個時候 cache 可能不是滿的
    // 如果讀端在寫端之下 則跳過消耗到 stack 頂部為止的部分
    if (pWriter < pReader) {
        goto __YayE_clean2;
    }

__YayE_clean1:
    // 消耗到 stack 頂部為止
    // 除了以下修改外 基本上照抄 main 的部分:
    //   主迴圈不填充 cache
    //   scan_finish 時不判斷寫端是不是在 stack 頂端 
    yay0_debug("clean1: r = 0x%llX, w = 0x%llX\n", pReader - ref_cache, pWriter - ref_cache);
    do {
        // 從 cache 中找出最長的連續 1
        {
            sptr mOffset, mSize = -0x1;
            u64 *pScan;

            // 從讀取端開始向上掃描
            pScan = pReader;
            pReader -= yay0_cache_page;
            do {
                sptr nSize = -0x3;
                u64 nFlag = -0x1;
                            
                // 把掃描端上移一個 slot
                pScan--;

                // 掃描整個 cahce 當中和 pScan 的特定 slot
                _YayE_ScanLoop(pScan, nSize, nFlag, &ref_cache[0x0], __YayE_clean1_scan_next);
                
                // 將掃描端指回 stack 底部
                pScan += yay0_cache_size;
                
                // 如果掃描端在寫端之上就結束
                // 修正 : 等於時其實可以繼續往下找一次 因為掃描端是先取值才遞減 同時也表示掃描端不可能會碰到 cache 底部 因此若寫入端位於 cache 底部 則等號不可能成立
                if (pScan >= pWriter) { _YayE_ScanLoop(pScan, nSize, nFlag, &pWriter[0x0], __YayE_clean1_scan_next); }

__YayE_clean1_scan_next:
                _YayE_ScanNext(mOffset, mSize, nFlag, nSize, pScan, pReader, &ref_cache[0x0]);
            } while (pScan > pReader);

            // 接下來判斷長度夠不夠寫成參照紀錄
            // yay0_debug("scan_end: s = 0x%llX / 0x%llX\n", pDat, scnt);
            if (mSize >= 0x0) {
                // 參照模式
                _YayE_EmitRef(pReader, pDat, pLnk, pCtr, mOffset, mSize);
            }
            else {
                // 明文模式
                _YayE_EmitCtr(pCtr, pDat, ref_flag, ref_mask);
            }
            pDat++;
            // yay0_debug("write: s = 0x%llX / 0x%llX\n", pDat, scnt);

            // 這裡不判斷讀端在不在寫端之下 移動到迴圈結束時判斷
        }
        
        // 更新參照標籤
        _YayE_EmitNext(pRef, ref_flag, ref_mask);
        
    } while (pReader > ref_cache);

    // 把讀端移回 stack 底端
    pReader += yay0_cache_size;
    
    // 如果讀端在寫端之下 (事實上只有可能相等) 則表示 cache 已經空了
    // 這時候就跳過消耗到讀端的動作
    yay0_debug("clean1: r = 0x%llX, w = 0x%llX\n", pReader - ref_cache, pWriter - ref_cache);
    if (pWriter >= pReader) {
        goto __YayE_clean3;
    }

__YayE_clean2:
    // 消耗到寫端為止
    // 除了以下修改外 基本上照抄 step2 的部分:
    //   scan_sub 只有一個迴圈 (因為不可能碰到 stack 頂端)
    yay0_debug("clean2: r = 0x%llX, w = 0x%llX\n", pReader - ref_cache, pWriter - ref_cache);
    do {
        // 從 cache 中找出最長的連續 1
        {
            sptr mOffset, mSize = -0x1;
            u64 *pScan;

            // 從讀取端開始向上掃描
            pScan = pReader;
            pReader -= yay0_cache_page;
            do {
                sptr nSize = -0x3;
                u64 nFlag = -0x1;
                            
                // 把掃描端上移一個 slot
                pScan--;

                // 掃描整個 cahce 當中和 pScan_base 的特定 slot
                _YayE_ScanLoop(pScan, nSize, nFlag, &pWriter[0x0], __YayE_clean2_scan_next);

__YayE_clean2_scan_next:
                _YayE_ScanNext(mOffset, mSize, nFlag, nSize, pScan, pReader, &ref_cache[0x0]);
            } while (pScan > pReader);      

            // 接下來判斷長度夠不夠寫成參照紀錄
            // yay0_debug("scan_end: s = 0x%llX / 0x%llX\n", pDat, scnt);
            if (mSize >= 0x0) {
                // 參照模式
                _YayE_EmitRef(pReader, pDat, pLnk, pCtr, mOffset, mSize);
            }
            else {
                // 明文模式
                _YayE_EmitCtr(pCtr, pDat, ref_flag, ref_mask);
            }
            pDat++;
            // yay0_debug("write: s = 0x%llX / 0x%llX\n", pDat, scnt);
            
            // 這裡不判斷讀端在不在寫端之下 移動到迴圈結束時判斷
        }
        
        // 更新參照標籤
        _YayE_EmitNext(pRef, ref_flag, ref_mask);

    } while (pReader > pWriter);

__YayE_clean3:
    // 判斷需不需要寫回 ref_flag
    if (ref_mask << 0x1 & 0xffffffff) { *pRef = bswap32(ref_flag); pRef++; }

__YayE_finish:
    // 計算各個 table 的位置
    {
        uptr d = (uptr)pRef;
        u8 *s;

        *(u32*)&dst[0x0] = 0x30796159; // Yay0
        *(u32*)&dst[0x4] = bswap32(scnt - (uptr)src);

        yay0_debug(
            "finish: msk = 0x%llx, lnk = 0x%llx, ctr = 0x%llx\n",
            (uptr)pRef - (uptr)&dst[0x10],
            (uptr)pLnk - (uptr)&ref_lnk[0x0],
            (uptr)pCtr - (uptr)&ref_ctr[0x0]
        );

        // Link Table
        s = (u8*)&ref_lnk[0x0];
        *(u32*)&dst[0x8] = bswap32((u32)(d - (uptr)dst));
        while (s < (u8*)pLnk) { *(u8*)d++ = *s++; }

        // Count Table
        s = (u8*)&ref_ctr[0x0];
        *(u32*)&dst[0xc] = bswap32((u32)(d - (uptr)dst));
        while (s < pCtr) { *(u8*)d++ = *s++; }

        return (u8*)d;
    }

#undef _YayE_FillLoop
#undef _YayE_ScanLoop
#undef _YayE_ScanNext
#undef _YayE_EmitRef
#undef _YayE_EmitCtr
#undef _YayE_EmitNext

}

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
測試用 code
如果是當成 library 使用的時候不加入這段 code
*/

#ifndef YAY0_MODULE

int main(sptr argc, u8 **argv) {
    if (argc != 0x4) {
        printf("main : Usage %s [d|e] [src] [dst].\n", argv[0x0]);
        return 0x1;
    }

    switch (argv[0x1][0x0]) {
        case 0x44:
        case 0x64:
        // 解壓測試
        {
            FILE *fp;
            uptr csize, dsize;
            u8 cdata[0x100000];
            u8 *ddata;

            fp = fopen(argv[0x2], "rb");
            fseek(fp, 0x0, SEEK_END);
            csize = ftell(fp);
            fseek(fp, 0x0, SEEK_SET);
            fread(cdata, csize, 0x1, fp);
            fclose(fp);

            csize -= 0x4;
            dsize = *(u32*)cdata;
            dsize = bswap32(dsize);
            ddata = (u8*)malloc(dsize);
            yay0Decode(ddata, &cdata[0x4], dsize, csize);

            fp = fopen(argv[0x3], "wb");
            fwrite(ddata, dsize, 0x1, fp);
            fclose(fp);

            free(ddata - yay0_win_size);
        }
        break;
    case 0x45:
    case 0x65:
        // 壓縮測試
        {
            FILE *fp;
            uptr csize, dsize;
            u8 cdata[0x100000];
            u8 *ddata;
            
            fp = fopen(argv[0x2], "rb");
            fseek(fp, 0x0, SEEK_END);
            dsize = ftell(fp);
            ddata = (u8*)malloc(dsize);
            fseek(fp, 0x0, SEEK_SET);
            fread(ddata, dsize, 0x1, fp);
            fclose(fp);

            csize = (uptr)yay0Encode(&cdata[0x4], ddata, 0x100000, dsize);
            csize -= (uptr)cdata;
            yay0_debug("Encode success : 0x%llX\n", csize);

            fp = fopen(argv[0x3], "wb");
            *(u32*)cdata = bswap32(dsize);
            fwrite(cdata, csize, 0x1, fp);
            fclose(fp);
            yay0_debug("Write success.\n");

            free(ddata - yay0_win_size);
        }
    }

    return 0x0;
}

#endif // YAY0_MODULE
