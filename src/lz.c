/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
lz.c
用於處理壓縮格式

*/

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
// 選項

// 在壓縮和解壓縮的同時進行邊界檢查
#define LZ_CHECK

// 是不是當作軟體庫使用
// #define LZ_MODULE

// 如果邊界檢查出錯的話 印出錯誤訊息到 console
#define LZ_ERROR

// 印出壓縮和解壓縮進程中除錯資訊 只用於開發本軟體庫
// #define LZ_DEBUG

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <env.h>

#if defined(LZ_MODULE) || defined(LZ_ERROR) || defined(LZ_DEBUG)
#include <stdlib.h>
#include <stdio.h>
#endif // defined(LZ_ERROR) || defined(LZ_DEBUG)

#if !defined(LZ_MODULE)
#include <memory.h>
#endif // !defined(LZ_MODULE)

#ifdef LZ_ERROR
#define lz_error(...)  printf(__VA_ARGS__); fflush(stdout);
#else
#define lz_error(...)
#endif // LZ_ERROR

#ifdef LZ_DEBUG
#define lz_debug(...)  printf(__VA_ARGS__); fflush(stdout);
#else
#define lz_debug(...)
#endif // LZ_ERROR

// lz_win_size = 0x1u << lz_win_bits
// lz_win_mask = lz_win_size - 0x1
#define lz_win_bits 0x000aull
#define lz_win_size 0x0400ull
#define lz_win_mask 0x03ffull
#define lz_ref_init 0x03beull

// lz_cache_page = lz_win_size / bitsof(u64) = 0x1u << lz_cache_bits
// lz_cache_size = lz_cache_page * lz_max_size
// lz_max_size = 0x3f + 0x3 = 0x42
#define lz_cache_page 0x0010ull
#define lz_cache_mask 0x000full
#define lz_cache_bits 0x0004ull
#define lz_cache_size 0x0420ull

/*
lzDecode
@inputs:
    dst : 輸出地址 ** 重要 : 這個地址前面必須要跟著 lz_win_size 個 0x00 bytes **
    src : 輸入地址
    dcnt : 解壓後大小
    scnt : 壓縮檔大小
@output:
    結束時的 dst 指標
*/
static inline __attribute__((always_inline))
u8* lzDecode(u8 *dst, u8 *src, uptr dcnt, uptr scnt) {
    uptr ref_flag, ref_ctr;

    // 初始化
    ref_flag = 0x0;
    ref_ctr = lz_ref_init;
    dcnt = dcnt + (uptr)dst;
    scnt = scnt + (uptr)src;

    do {
        u8 c;

        // 讀取 1 byte
        c = *src;
        src++;

        // 判斷是不是已經讀取超過 8 次
        if ((ref_flag >> 0x8) == 0x0) {
            // 超過就把這個 byte 當作 flag
            ref_flag = 0x8000 | c;

            // 檔案有可能會在這裡結束
            if ((uptr)src >= scnt) {
                goto __lzDecode_finish;
            }

            // 重新讀取 1 byte
            c = *src;
            src++;
        }        

        // 判斷是不是參照模式
        // 1 : 明文
        // 0 : 參照
        if (ref_flag & 0x1) {

#ifdef LZ_CHECK
            if ((uptr)dst > dcnt) {
                lz_error("lzDecode : [Error] out of dst when writing byte.\n");
                return dst;
            }
#endif // LZ_CHECK

            // 明文模式
            *dst = c;

            // 更新計數器
            dst++;
            ref_ctr++;

        }
        else {
            // 參照模式
            uptr ref_off, ref_len;

            // 原始壓縮工具生成的檔案 可能會在這裡結束
            if ((uptr)src >= scnt) {
                lz_debug("lzDecode : [Debug] out of src when reading reference.\n");
                return dst;
            }

            // 參照紀錄
            ref_off = c;
            ref_len = *src;
            ref_off |= (ref_len & 0xC0) << 0x2;
            ref_len = (ref_len & 0x3F) + 0x3;
            src++;

            // 計算參考地址
            ref_off = (ref_ctr - ref_off) & lz_win_mask;
            if (ref_off == 0x0) {
                ref_off = lz_win_size;
            }

            lz_debug("ref : 0x%llX, 0x%llX, 0x%llX [0x%llX]\n", ref_len, ref_off, ref_ctr, dst[-ref_off]);

#ifdef LZ_CHECK
            if ((uptr)&dst[ref_len] > dcnt) {
                lz_error("lzDecode : [Error] out of dst when writing reference.\n");
                return dst;
            }
#endif // LZ_CHECK

            // 更新計數器
            ref_ctr = ref_ctr + ref_len;

            // 複製
            do {
                *dst = dst[-ref_off];
                dst++;
            } while (--ref_len);
        }

        // 更新參照標籤
        ref_flag >>= 0x1;

    } while ((uptr)src < scnt);

__lzDecode_finish:
    return dst;
}

/*
lzEncode
@inputs:
    dst : 輸出地址
    src : 輸入地址 ** 重要 : 這個地址前面必須要跟著 lz_win_size 個 0x00 bytes **
    dcnt : 輸出地址的空間大小
    scnt : 壓縮前大小
@output:
    結束時的 dst 指標
*/
static inline __attribute__((always_inline))
u8* lzEncode(u8 *dst, u8 *src, uptr dcnt, uptr scnt) {
    uptr ref_flag, ref_ctr;
    u8 *ref_flag_pos, *src_ref;
    u64 *ref_cache_write, *ref_cache_read, ref_cache[lz_cache_size];

    // 初始化
    ref_flag = 0x10000;
    ref_ctr = lz_ref_init - 0x1;
    dcnt = dcnt + (uptr)dst;
    scnt = scnt + (uptr)src;
    ref_flag_pos = dst;
    ref_cache_read = &ref_cache[lz_cache_size];
    ref_cache_write = &ref_cache[lz_cache_size];
    dst++;
    src_ref = src;

__lzEncode_main:
    // 寫入
    do {
        // 把 cache 填滿
        // O(n)
__lzEncode_main_refill:
        {
            // 將 src 回朔到原本的指針
            src = (u8*)((uptr)src ^ (uptr)src_ref);
            src_ref = (u8*)((uptr)src ^ (uptr)src_ref);
            src = (u8*)((uptr)src ^ (uptr)src_ref);

            // 如果讀端在寫端之上 則不需要填充到 stack 頂部
            if (ref_cache_write > ref_cache_read) {
                goto __lzEncode_main_refill_step2;
            }
            
            // 掃描直到碰到 stack 頂部
__lzEncode_main_refill_step1:
            do {
                u8 c, *p;

                // 讀取 1 byte
                c = *src;
                p = &src[-lz_win_size];
                lz_debug("refill step1 : r = 0x%llX, w = 0x%llX, 0x%llX\n", ref_cache_read, ref_cache_write, ref_cache);

                // 更新 cache
                do {
                    ref_cache_write--;
                    *ref_cache_write = ((*p++ == c) ? 0x0000000000000001 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000002 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000004 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000008 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000010 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000020 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000040 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000080 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000100 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000200 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000400 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000800 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000001000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000002000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000004000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000008000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000010000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000020000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000040000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000080000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000100000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000200000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000400000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000800000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000001000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000002000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000004000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000008000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000010000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000020000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000040000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000080000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000100000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000200000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000400000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000800000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000001000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000002000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000004000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000008000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000010000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000020000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000040000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000080000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000100000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000200000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000400000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000800000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0001000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0002000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0004000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0008000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0010000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0020000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0040000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0080000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0100000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0200000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0400000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0800000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x1000000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x2000000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x4000000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x8000000000000000 : 0x0000000000000000);
                } while (p < src);
                
                // 更新 src 地址
                src++;
                
                // 如果 src 用完了 就跳到最後的一次處理
                if ((uptr)src >= scnt) {
                    lz_debug("0x%llX, 0x%llX, 0x%llX\n", ref_cache_write, src, scnt);

                    // 將 src 回朔到原本的指針
                    src = src_ref;

                    // 因為這時候 寫端 < 讀端 所以消耗的時候跳過消耗到 stack 頂部的處理
                    // 原因是消耗 cache 是從讀端消耗
                    goto __lzEncode_cleanup_step2;
                }
                
            } while (ref_cache_write > ref_cache);

            // 指回 stack 底部
            ref_cache_write += lz_cache_size;

            // 如果讀端在寫端之前 (事實上應該要一致) 就結束補充 cache
            if (ref_cache_write <= ref_cache_read) {
                goto __lzEncode_main_refill_finish;
            }

            // 繼續填充直到讀端
__lzEncode_main_refill_step2:
            do {
                u8 c, *p;
                
                // 讀取 1 byte
                c = *src;
                p = &src[-lz_win_size];
                lz_debug("refill step2 : r = 0x%llX, w = 0x%llX, 0x%llX\n", ref_cache_read, ref_cache_write, ref_cache);

                // 更新 cache
                do {
                    ref_cache_write--;
                    *ref_cache_write = ((*p++ == c) ? 0x0000000000000001 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000002 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000004 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000008 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000010 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000020 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000040 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000080 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000100 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000200 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000400 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000000800 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000001000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000002000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000004000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000008000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000010000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000020000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000040000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000080000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000100000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000200000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000400000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000000800000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000001000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000002000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000004000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000008000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000010000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000020000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000040000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000080000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000100000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000200000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000400000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000000800000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000001000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000002000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000004000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000008000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000010000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000020000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000040000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000080000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000100000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000200000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000400000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0000800000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0001000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0002000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0004000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0008000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0010000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0020000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0040000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0080000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0100000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0200000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0400000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x0800000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x1000000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x2000000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x4000000000000000 : 0x0000000000000000) | ((*p++ == c) ? 0x8000000000000000 : 0x0000000000000000);
                } while (p < src);
                
                // 更新 src 地址
                src++;
                
                // 如果 src 用完了 就跳到最後的一次處理
                if ((uptr)src >= scnt) {
                    lz_debug("0x%llX, 0x%llX, 0x%llX\n", ref_cache_write, src, scnt);

                    // 將 src 回朔到原本的指針
                    src = src_ref;

                    // 因為這時候 寫端 < 讀端 所以消耗的時候跳過消耗到 stack 頂部的處理
                    // 原因是消耗 cache 是從讀端消耗
                    goto __lzEncode_cleanup_step1;
                }
            } while (ref_cache_write > ref_cache_read);

__lzEncode_main_refill_finish:
            // 將 src 回朔到原本的指針
            src = (u8*)((uptr)src ^ (uptr)src_ref);
            src_ref = (u8*)((uptr)src ^ (uptr)src_ref);
            src = (u8*)((uptr)src ^ (uptr)src_ref);
        }
        lz_debug("refill_finish : r = 0x%llX, s = 0x%llX / 0x%llX\n", ref_cache_read, src, scnt);
        
__lzEncode_main_scan:
        // 從 cache 中找出最長的連續 1
        // 最多 0x420 操作
        {
            sptr ref_offset, ref_size;
            u64 *ref_cache_scan;

            // 初始化
            ref_size = -0x1;

            // 從讀取端開始向上掃描
            ref_cache_scan = ref_cache_read;
            ref_cache_read -= lz_cache_page;

            // 掃描開始
            do {
                sptr scan_size;
                u64 scan_flag;
                            
                // 把掃描端上移一個 slot
                ref_cache_scan--;

                // 初始化
                scan_size = -0x3;
                scan_flag = -0x1;

                // 掃描整個 cahce 當中和 ref_cache_scan_base 的特定 slot
__lzEncode_main_scan_sub:
                do {
                    u64 scan_flag_next;

                    // 掃描這一頁
                    scan_flag_next = scan_flag & *ref_cache_scan;

                    // 如果已經沒有 1 的 bit 則說明接下來都不連續
                    // 這種情況就中斷掃描
                    if (!scan_flag_next) {
                        goto __lzEncode_main_scan_sub_next;
                    }
                    
                    // 往前一頁
                    ref_cache_scan -= lz_cache_page;

                    // 更新 scan_flag
                    scan_flag = scan_flag_next;

                    // 增加參照長度
                    scan_size++;

                    // 判斷是不是碰到 cache 頂部
                    // 修正 : 這裡等於是有可能的
                } while (ref_cache_scan >= ref_cache);
                
                // 將掃描端指回 stack 底部
                ref_cache_scan += lz_cache_size;
                
                // 如果掃描端在寫端之上就結束
                // 修正 : 等於時其實可以繼續往下找一次 因為掃描端是先取值才遞減 同時也表示掃描端不可能會碰到 cache 底部 因此若寫入端位於 cache 底部 則等號不可能成立
                if (ref_cache_scan < ref_cache_write) {
                    goto __lzEncode_main_scan_sub_next;
                }
                
                // lz_debug("scan continue : %02X, f = 0x%llX, t = 0x%llX, w = 0x%llX\n", scan_size, scan_flag, ref_cache_scan, ref_cache_write);

                // 繼續掃描
                do {
                    u64 scan_flag_next;

                    // 掃描這一頁
                    scan_flag_next = scan_flag & *ref_cache_scan;

                    // 如果已經沒有 1 的 bit 則說明接下來都不連續
                    // 這種情況就中斷掃描
                    if (!scan_flag_next) {
                        goto __lzEncode_main_scan_sub_next;
                    }
                    
                    // 往上一頁
                    ref_cache_scan -= lz_cache_page;

                    // 更新 scan_flag
                    scan_flag = scan_flag_next;

                    // 增加參照長度
                    scan_size++;

                    // 判斷是不是碰到 cache 頂部
                    // 修正 : 這裡等於是有可能的
                } while (ref_cache_scan >= ref_cache_write);

__lzEncode_main_scan_sub_next:
                {
                    uptr scan_slot;

                    // 計算這個 slot 的地址
                    scan_slot = ((uptr)ref_cache_scan - (uptr)ref_cache) & (lz_cache_mask << 0x3);

                    // 如果這次的長度比先前的長 則更新資訊
                    // 實際的 ref_offset 應該是 lz_win_size - ((scan_slot << 0x3) | clz64(scan_flag))
                    // 這個轉換延後到最後才執行
                    if (scan_size > ref_size) {
                        ref_size = scan_size;
                        ref_offset = (scan_slot << 0x3) | clz64(scan_flag);

                        lz_debug("scan update : 0x%llX, 0x%llX, 0x%llX\n", ref_size, ref_offset, scan_flag);
                    }

                    // 把掃描端移回原本的 page
                    ref_cache_scan = (u64*)((uptr)ref_cache_read + scan_slot);
                    // lz_debug("scan next : %02X, f = 0x%llX, t = 0x%llX, w = 0x%llX\n", scan_size, scan_flag, ref_cache_scan, ref_cache_write);
                }

            } while (ref_cache_scan > ref_cache_read);

__lzEncode_main_scan_finish:         

            // 接下來判斷長度夠不夠寫成參照紀錄
            if (ref_size >= 0x0) {
                // 參照模式
#ifdef LZ_CHECK
                if ((uptr)&dst[0x1] >= dcnt) {
                    lz_error("lzEncode : out of dst when writing reference.\n\n");
                    return dst;
                }
#endif // LZ_CHECK

                lz_debug("record : ");
#if LZ_DEBUG
                for (uptr i = 0x0; i < ref_size + 0x3; i++) {
                    lz_debug("%02X", src[i]);
                }
                lz_debug("\n0x%llX, 0x%llX, 0x%llX\n", ref_size, ref_offset, ref_ctr);
#endif // LZ_DEBUG

                // 在計算 ref_offset 的時候實際上值是
                //   (ref_ctr + lz_win_mask - ref_offset) & lz_win_mask = (ref_ctr - 0x1 - ref_offset) & lz_win_mask
                // 因此在初始化的時候 ref_ctr = ref_win_init - 0x1
                ref_offset = (ref_ctr - ref_offset) & lz_win_mask;
                dst[0x0] = ref_offset & 0xFF;
                dst[0x1] = ((ref_offset >> 0x2) & 0xC0) | ref_size;
                
                // 同時更新 src
                ref_size = ref_size + 0x2;
                ref_cache_read -= ref_size << lz_cache_bits;
                ref_ctr += ref_size;
                src += ref_size;
                dst++;
            }
            else {
                // 明文模式

#ifdef LZ_CHECK
                if ((uptr)dst >= dcnt) {
                    lz_error("lzEncode : out of dst when writing byte.\n\n");
                    return dst;
                }
#endif // LZ_CHECK

                lz_debug("plain : %02X\n", *src);
                
                // 現在 src 是指到明文位置
                *dst = *src;
                ref_flag |= 0x100;
            }
            // 參照模式下
            //   而 ref_ctr += ref_size + 0x3;
            // 明文模式
            //   ref_ctr++;
            // 因此把這個操作單獨提出來一起做
            // 同理 src 也在這裡更新
            ref_ctr++;
            src++;
            dst++;
            lz_debug("scan finish : s = 0x%llX / 0x%llX\n", src, scnt);

            // 如果讀端已經讀到 stack 頂部 則把它重新指回 stack 底部
            // 這個判斷必須放在參照模式寫入之後 因為減完 ref_size 之後 讀端有可能會指到 stack 頂端之上
            if (ref_cache_read <= ref_cache) {
                ref_cache_read += lz_cache_size;
            }
        }
        
        // 更新參照標籤
        ref_flag >>= 0x1;

        // 判斷 flag 是否用盡
        if (ref_flag >> 0x9 == 0x0) {

#ifdef LZ_CHECK
            if ((uptr)dst >= dcnt) {
                lz_error("lzEncode : out of dst when writing flag.\n\n");
                return dst;
            }
#endif // LZ_CHECK

            // 用完了就寫回 並且借一個新的
            *ref_flag_pos = ref_flag;
            ref_flag_pos = dst;
            ref_flag = 0x10000;
            dst++;
        }

    } while ((uptr)src < scnt);

    // 讀端和寫端一樣的話則表示現在 cache 是空的 (因為前面有消耗過)
    // 這時候跳過清理 cache 的步驟
    if (ref_cache_write == ref_cache_read) {
        goto __lzEncode_cleanup_step3;
    }

    // 接下來將剩下的 cache 消耗完畢就完成了 這個時候 cache 可能不是滿的
    // 如果讀端在寫端之下 則跳過消耗到 stack 頂部為止的部分
    if (ref_cache_write < ref_cache_read) {
        goto __lzEncode_cleanup_step2;
    }

__lzEncode_cleanup_step1:
    // 消耗到 stack 頂部為止
    // 除了以下修改外 基本上照抄 main 的部分:
    //   主迴圈不填充 cache
    //   scan_finish 時不判斷寫端是不是在 stack 頂端 
    lz_debug("Cleanup step1 : r = 0x%llX, w = 0x%llX\n", ref_cache_read, ref_cache_write);
    do {

        // 不填充 cahce

__lzEncode_cleanup_step1_scan:
        // 從 cache 中找出最長的連續 1
        // 最多 0x420 操作
        {
            sptr ref_offset, ref_size;
            u64 *ref_cache_scan;

            // 初始化
            ref_size = -0x1;

            // 從讀取端開始向上掃描
            ref_cache_scan = ref_cache_read;
            ref_cache_read -= lz_cache_page;

            // 掃描開始
            do {
                sptr scan_size;
                u64 scan_flag;
                            
                // 把掃描端上移一個 slot
                ref_cache_scan--;

                // 初始化
                scan_size = -0x3;
                scan_flag = -0x1;

                // 掃描整個 cahce 當中和 ref_cache_scan_base 的特定 slot
__lzEncode_cleanup_step1_scan_sub:
                do {
                    u64 scan_flag_next;

                    // 掃描這一頁
                    scan_flag_next = scan_flag & *ref_cache_scan;

                    // 如果已經沒有 1 的 bit 則說明接下來都不連續
                    // 這種情況就中斷掃描
                    if (!scan_flag_next) {
                        goto __lzEncode_cleanup_step1_scan_sub_next;
                    }
                    
                    // 往前一頁
                    ref_cache_scan -= lz_cache_page;

                    // 更新 scan_flag
                    scan_flag = scan_flag_next;

                    // 增加參照長度
                    scan_size++;

                    // 判斷是不是碰到 cache 頂部
                    // 修正 : 這裡等於是有可能的
                } while (ref_cache_scan >= ref_cache);
                
                // 將掃描端指回 stack 底部
                ref_cache_scan += lz_cache_size;
                
                // 如果掃描端在寫端之上就結束
                // 修正 : 等於時其實可以繼續往下找一次 因為掃描端是先取值才遞減 同時也表示掃描端不可能會碰到 cache 底部 因此若寫入端位於 cache 底部 則等號不可能成立
                if (ref_cache_scan < ref_cache_write) {
                    goto __lzEncode_cleanup_step1_scan_sub_next;
                }

                // 繼續掃描
                do {
                    u64 scan_flag_next;

                    // 掃描這一頁
                    scan_flag_next = scan_flag & *ref_cache_scan;

                    // 如果已經沒有 1 的 bit 則說明接下來都不連續
                    // 這種情況就中斷掃描
                    if (!scan_flag_next) {
                        goto __lzEncode_cleanup_step1_scan_sub_next;
                    }
                    
                    // 往上一頁
                    ref_cache_scan -= lz_cache_page;

                    // 更新 scan_flag
                    scan_flag = scan_flag_next;

                    // 增加參照長度
                    scan_size++;

                    // 判斷是不是碰到 cache 頂部
                    // 修正 : 這裡等於是有可能的
                } while (ref_cache_scan >= ref_cache_write);

__lzEncode_cleanup_step1_scan_sub_next:
                {
                    uptr scan_slot;

                    // 計算這個 slot 的地址
                    scan_slot = ((uptr)ref_cache_scan - (uptr)ref_cache) & (lz_cache_mask << 0x3);

                    // 如果這次的長度比先前的長 則更新資訊
                    // 實際的 ref_offset 應該是 lz_win_size - ((scan_slot << 0x3) | clz64(scan_flag))
                    // 這個轉換延後到最後才執行
                    if (scan_size > ref_size) {
                        ref_size = scan_size;
                        ref_offset = (scan_slot << 0x3) | clz64(scan_flag);
                    }

                    // 把掃描端移回原本的 page
                    ref_cache_scan = (u64*)((uptr)ref_cache_read + scan_slot);
                    // lz_debug("scan sub next : 0x%llX\n", ref_cache_scan);
                }

            } while (ref_cache_scan > ref_cache_read);

__lzEncode_cleanup_step1_scan_finish:         

            // 接下來判斷長度夠不夠寫成參照紀錄
            if (ref_size >= 0x0) {
                // 參照模式
#ifdef LZ_CHECK
                if ((uptr)&dst[0x1] >= dcnt) {
                    lz_error("lzEncode : out of dst when writing reference.\n\n");
                    return dst;
                }
#endif // LZ_CHECK

                lz_debug("scan finish : 0x%llX, 0x%llX, 0x%llX\n", ref_size, ref_offset, ref_ctr);

                // 在計算 ref_offset 的時候實際上值是
                //   (ref_ctr + lz_win_mask - ref_offset) & lz_win_mask = (ref_ctr - 0x1 - ref_offset) & lz_win_mask
                // 因此在初始化的時候 ref_ctr = ref_win_init - 0x1
                ref_offset = (ref_ctr - ref_offset) & lz_win_mask;
                dst[0x0] = ref_offset & 0xFF;
                dst[0x1] = ((ref_offset >> 0x2) & 0xC0) | ref_size;

                // 同時更新 src
                ref_size = ref_size + 0x2;
                ref_cache_read -= ref_size << lz_cache_bits;
                ref_ctr += ref_size;
                src += ref_size;
                dst++;
            }
            else {
                // 明文模式
#ifdef LZ_CHECK
                if ((uptr)dst >= dcnt) {
                    lz_error("lzEncode : out of dst when writing byte.\n\n");
                    return dst;
                }
#endif // LZ_CHECK
                
                // 現在 src 是指到明文位置
                *dst = *src;
                ref_flag |= 0x100;
            }
            // 參照模式下
            //   而 ref_ctr += ref_size + 0x3;
            // 明文模式
            //   ref_ctr++;
            // 因此把這個操作單獨提出來一起做
            // 同理 src 也在這裡更新
            ref_ctr++;
            src++;
            dst++;
            lz_debug("scan finish : s = 0x%llX / 0x%llX\n", src, scnt);
            
            // 這裡不判斷讀端在不在寫端之下 移動到迴圈結束時判斷
        }
        
        // 更新參照標籤
        ref_flag >>= 0x1;

        // 判斷 flag 是否用盡
        if (ref_flag >> 0x9 == 0x0) {

#ifdef LZ_CHECK
            if ((uptr)dst >= dcnt) {
                lz_error("lzEncode : out of dst when writing flag.\n\n");
                return dst;
            }
#endif // LZ_CHECK

            // 用完了就寫回 並且借一個新的
            *ref_flag_pos = ref_flag;
            ref_flag_pos = dst;
            ref_flag = 0x10000;
            dst++;
        }
        
    } while (ref_cache_read > ref_cache);

    // 把讀端移回 stack 底端
    ref_cache_read += lz_cache_size;
    
    // 如果讀端在寫端之下 (事實上只有可能相等) 則表示 cache 已經空了
    // 這時候就跳過消耗到讀端的動作
    if (ref_cache_write >= ref_cache_read) {
        goto __lzEncode_cleanup_step3;
    }

__lzEncode_cleanup_step2:
    // 消耗到寫端為止
    // 除了以下修改外 基本上照抄 step2 的部分:
    //   scan_sub 只有一個迴圈 (因為不可能碰到 stack 頂端)
    lz_debug("Cleanup step2 : r = 0x%llX, w = 0x%llX\n", ref_cache_read, ref_cache_write);
    do {
        // 不填充 cahce

__lzEncode_cleanup_step2_scan:
        // 從 cache 中找出最長的連續 1
        // 最多 0x420 操作
        {
            sptr ref_offset, ref_size;
            u64 *ref_cache_scan;

            // 初始化
            ref_size = -0x1;

            // 從讀取端開始向上掃描
            ref_cache_scan = ref_cache_read;
            ref_cache_read -= lz_cache_page;

            // 掃描開始
            do {
                sptr scan_size;
                u64 scan_flag;
                            
                // 把掃描端上移一個 slot
                ref_cache_scan--;

                // 初始化
                scan_size = -0x3;
                scan_flag = -0x1;

                // 掃描整個 cahce 當中和 ref_cache_scan_base 的特定 slot
__lzEncode_cleanup_step2_scan_sub:
                do {
                    u64 scan_flag_next;

                    // 掃描這一頁
                    scan_flag_next = scan_flag & *ref_cache_scan;

                    // 如果已經沒有 1 的 bit 則說明接下來都不連續
                    // 這種情況就中斷掃描
                    if (!scan_flag_next) {
                        goto __lzEncode_cleanup_step2_scan_sub_next;
                    }
                    
                    // 往前一頁
                    ref_cache_scan -= lz_cache_page;

                    // 更新 scan_flag
                    scan_flag = scan_flag_next;

                    // 增加參照長度
                    scan_size++;

                    // 判斷是不是碰到 cache 頂部
                    // 這裡等於是有可能的
                } while (ref_cache_scan >= ref_cache_write);

__lzEncode_cleanup_step2_scan_sub_next:
                {
                    uptr scan_slot;

                    // 計算這個 slot 的地址
                    scan_slot = ((uptr)ref_cache_scan - (uptr)ref_cache) & (lz_cache_mask << 0x3);

                    // 如果這次的長度比先前的長 則更新資訊
                    // 實際的 ref_offset 應該是 lz_win_size - ((scan_slot << 0x3) | clz64(scan_flag))
                    // 這個轉換延後到最後才執行
                    if (scan_size > ref_size) {
                        ref_size = scan_size;
                        ref_offset = (scan_slot << 0x3) | clz64(scan_flag);
                    }

                    // 把掃描端移回原本的 page
                    ref_cache_scan = (u64*)((uptr)ref_cache_read + scan_slot);
                    // lz_debug("scan sub next : 0x%llX\n", ref_cache_scan);
                }

            } while (ref_cache_scan > ref_cache_read);

__lzEncode_cleanup_step2_scan_finish:         

            // 接下來判斷長度夠不夠寫成參照紀錄
            if (ref_size >= 0x0) {
                // 參照模式
#ifdef LZ_CHECK
                if ((uptr)&dst[0x1] >= dcnt) {
                    lz_error("lzEncode : out of dst when writing reference.\n\n");
                    return dst;
                }
#endif // LZ_CHECK

                lz_debug("scan finish : 0x%llX, 0x%llX, 0x%llX\n", ref_size, ref_offset, ref_ctr);

                // 在計算 ref_offset 的時候實際上值是
                //   (ref_ctr + lz_win_mask - ref_offset) & lz_win_mask = (ref_ctr - 0x1 - ref_offset) & lz_win_mask
                // 因此在初始化的時候 ref_ctr = ref_win_init - 0x1
                ref_offset = (ref_ctr - ref_offset) & lz_win_mask;
                dst[0x0] = ref_offset & 0xFF;
                dst[0x1] = ((ref_offset >> 0x2) & 0xC0) | ref_size;
                
                // 同時更新 src
                ref_size = ref_size + 0x2;
                ref_cache_read -= ref_size << lz_cache_bits;
                ref_ctr += ref_size;
                src += ref_size;
                dst++;
            }
            else {
                // 明文模式
#ifdef LZ_CHECK
                if ((uptr)dst >= dcnt) {
                    lz_error("lzEncode : out of dst when writing byte.\n\n");
                    return dst;
                }
#endif // LZ_CHECK
                
                // 現在 src 是指到明文位置
                *dst = *src;
                ref_flag |= 0x100;
            }
            // 參照模式下
            //   而 ref_ctr += ref_size + 0x3;
            // 明文模式
            //   ref_ctr++;
            // 因此把這個操作單獨提出來一起做
            // 同理 src 也在這裡更新
            ref_ctr++;
            src++;
            dst++;
            lz_debug("scan finish : s = 0x%llX / 0x%llX\n", src, scnt);
            
            // 這裡不判斷讀端在不在寫端之下 移動到迴圈結束時判斷
        }
        
        // 更新參照標籤
        ref_flag >>= 0x1;

        // 判斷 flag 是否用盡
        if (ref_flag >> 0x9 == 0x0) {

#ifdef LZ_CHECK
            if ((uptr)dst >= dcnt) {
                lz_error("lzEncode : out of dst when writing flag.\n\n");
                return dst;
            }
#endif // LZ_CHECK

            // 用完了就寫回 並且借一個新的
            *ref_flag_pos = ref_flag;
            ref_flag_pos = dst;
            ref_flag = 0x10000;
            dst++;
        }

    } while (ref_cache_read > ref_cache_write);

__lzEncode_cleanup_step3:
    // 判斷需不需要寫回 ref_flag
    if (dst != ref_flag_pos) {
        *ref_flag_pos = ref_flag >> (0x37 - clz(ref_flag));
        lz_debug("cleanup step 3 : 0x%llX, 0x%llX, 0x%llX\n", ref_flag_pos, dst, ref_flag);
    }
    else {
        dst--;
    }

__lzEncode_finish:
    return dst;
}

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
測試用 code
如果是當成 library 使用的時候不加入這段 code
*/

#ifndef LZ_MODULE

int main(sptr argc, u8 **argv) {
    if (argc != 0x4) {
        printf("main : Usage %s [src] [dst].\n", argv[0x0]);
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

            csize -= 0x8;
            dsize = *(u32*)cdata;
            dsize = bswap32(dsize);
            
            {
                u8 *p;
                
                p = (u8*)malloc(dsize + lz_win_size);
                ddata = &p[lz_win_size];
                do {
                    *p = 0x0;
                    p++;
                } while (p < ddata);
            }

            lzDecode(ddata, &cdata[0x8], dsize, csize);

            fp = fopen(argv[0x3], "wb");
            fwrite(ddata, dsize, 0x1, fp);
            fclose(fp);

            free(ddata - lz_win_size);
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
            {
                u8 *p;
                
                p = (u8*)malloc(dsize + lz_win_size);
                ddata = &p[lz_win_size];
                do {
                    *p = 0x0;
                    p++;
                } while (p < ddata);
            }
            fseek(fp, 0x0, SEEK_SET);
            fread(ddata, dsize, 0x1, fp);
            fclose(fp);

            csize = (uptr)lzEncode(&cdata[0x8], ddata, 0x100000, dsize);
            csize -= (uptr)cdata;
            lz_debug("Encode success : 0x%llX\n", csize);

            fp = fopen(argv[0x3], "wb");
            *(u32*)cdata = bswap32(dsize);
            fwrite(cdata, csize, 0x1, fp);
            fclose(fp);
            lz_debug("Write success.\n");

            free(ddata - lz_win_size);
        }
    }

    return 0x0;
}

#endif // LZ_MODULE
