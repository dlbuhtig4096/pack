/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
pack1.c
用於 Baku Bomberman 1 檔案系統的工具組

*/

#include <env.h>
/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
// 選項

#define BAKU2_DEBUG
#define BAKU2_ERROR

// 緩存參數

#define BAKU2_ROM_SIZE      0x01000000
#define BAKU2_BUF_SIZE      0x00100000

// 組合參數

#define BAKU2_PACK_FAT_BASE              0x00002008
#define BAKU2_PACK_FAT_BASE_NUS          0x08200000
#define BAKU2_PACK_FAT_SIZE             0x00000400
#define BAKU2_PACK_FAT_SIZE_NUS         0x00040000

// 型態

#define baku2_info_raw_name_size    0x17
struct baku2_info_raw {
    u32 addr;
    u32 size;
    u8 name[baku2_info_raw_name_size];
    u8 type;
};
typedef struct baku2_info_raw baku2_info_raw;

#define baku2_info_fat_name_size    0x17
struct baku2_info_fat {
    u32 addr;
    u32 size;
    u8 name[baku2_info_fat_name_size];
    u8 type;
};
typedef struct baku2_info_fat baku2_info_fat;

#define baku2_info_arc_name_size    0x1F
struct baku2_info_arc {
    u8 name[baku2_info_arc_name_size];
    u8 type;
};
typedef struct baku2_info_arc baku2_info_arc;

union baku2_info {
    baku2_info_raw raw;
    baku2_info_fat fat;
    baku2_info_arc arc;
};
typedef union baku2_info baku2_info;

enum baku2_fs_type {
    BAKU2_RAW,
    BAKU2_FAT,
    BAKU2_NONE
};

enum baku2_arc_type {
    BAKU2_FS_RAW,
    BAKU2_FS_LZX,
    BAKU2_FS_NONE
};

#define RAW(raw_addr, raw_size, raw_name)                                                       \
    {.fat = {.addr = raw_addr, .size = raw_size, .name = raw_name, .type = BAKU2_RAW }}

#define FAT(fat_addr, fat_size, fat_name)                                                       \
    {.fat = {.addr = fat_addr, .size = fat_size, .name = fat_name, .type = BAKU2_FAT }}

#define FS_RAW(arc_name)                                                                        \
    {.arc = {.name = arc_name, .type = BAKU2_FS_RAW }}

#define FS_LZX(arc_name)                                                                         \
    {.arc = {.name = arc_name, .type = BAKU2_FS_LZX }}

baku2_info baku2_fat_info[] = {
    RAW(0x00000000, 0x00001000, "boot.bin"),
    RAW(0x00001000, 0x000FF000, "app.bin"),

    FAT(0x00120000, 0x4, ""), // 0x00020000
    FS_RAW("1.info"),
    FS_LZX("1.0.bin"),
    FS_LZX("1.1.bin"),
    FS_LZX("1.2.bin"),
    FS_LZX("1.3.bin"),

    FAT(0x00140000, 0x6, ""), // 0x00020000
    FS_RAW("2.info"),
    FS_LZX("2.0.bin"),
    FS_LZX("2.1.bin"),
    FS_LZX("2.2.bin"),
    FS_LZX("2.3.bin"),
    FS_LZX("2.4.bin"),
    FS_LZX("2.5.bin"),

    FAT(0x00160000, 0x6, ""), // 0x00020000
    FS_RAW("3.info"),
    FS_LZX("3.0.bin"),
    FS_LZX("3.1.bin"),
    FS_LZX("3.2.bin"),
    FS_LZX("3.3.bin"),
    FS_LZX("3.4.bin"),
    FS_LZX("3.5.bin"),

    FAT(0x00180000, 0xa, ""), // 0x00020000
    FS_RAW("4.info"),
    FS_LZX("4.0.bin"),
    FS_LZX("4.1.bin"),
    FS_LZX("4.2.bin"),
    FS_LZX("4.3.bin"),
    FS_LZX("4.4.bin"),
    FS_LZX("4.5.bin"),
    FS_LZX("4.6.bin"),
    FS_LZX("4.7.bin"),
    FS_LZX("4.8.bin"),
    FS_LZX("4.9.bin"),

    FAT(0x001a0000, 0x6, ""), // 0x00020000
    FS_RAW("5.info"),
    FS_LZX("5.0.bin"),
    FS_LZX("5.1.bin"),
    FS_LZX("5.2.bin"),
    FS_LZX("5.3.bin"),
    FS_LZX("5.4.bin"),
    FS_LZX("5.5.bin"),

    FAT(0x001c0000, 0xf, ""), // 0x00020000
    FS_RAW("6.info"),
    FS_LZX("6.0.bin"),
    FS_LZX("6.1.bin"),
    FS_LZX("6.2.bin"),
    FS_LZX("6.3.bin"),
    FS_LZX("6.4.bin"),
    FS_LZX("6.5.bin"),
    FS_LZX("6.6.bin"),
    FS_LZX("6.7.bin"),
    FS_LZX("6.8.bin"),
    FS_LZX("6.9.bin"),
    FS_LZX("6.a.bin"),
    FS_LZX("6.b.bin"),
    FS_LZX("6.c.bin"),
    FS_LZX("6.d.bin"),
    FS_LZX("6.e.bin"),

    FAT(0x001e0000, 0xa, ""), // 0x00020000
    FS_RAW("7.info"),
    FS_LZX("7.0.bin"),
    FS_LZX("7.1.bin"),
    FS_LZX("7.2.bin"),
    FS_LZX("7.3.bin"),
    FS_LZX("7.4.bin"),
    FS_LZX("7.5.bin"),
    FS_LZX("7.6.bin"),
    FS_LZX("7.7.bin"),
    FS_LZX("7.8.bin"),
    FS_LZX("7.9.bin"),

    FAT(0x00200000, 0xd, ""), // 0x00040000
    FS_RAW("8.info"),
    FS_LZX("8.0.bin"),
    FS_LZX("8.1.bin"),
    FS_LZX("8.2.bin"),
    FS_LZX("8.3.bin"),
    FS_LZX("8.4.bin"),
    FS_LZX("8.5.bin"),
    FS_LZX("8.6.bin"),
    FS_LZX("8.7.bin"),
    FS_LZX("8.8.bin"),
    FS_LZX("8.9.bin"),
    FS_LZX("8.a.bin"),
    FS_LZX("8.b.bin"),
    FS_LZX("8.c.bin"),

    FAT(0x00240000, 0x6, ""), // 0x00020000
    FS_RAW("8.info"),
    FS_LZX("8.0.bin"),
    FS_LZX("8.1.bin"),
    FS_LZX("8.2.bin"),
    FS_LZX("8.3.bin"),
    FS_LZX("8.4.bin"),
    FS_LZX("8.5.bin"),

    FAT(0x00260000, 0x2, ""), // 0x00020000
    FS_RAW("9.info"),
    FS_LZX("9.0.bin"),
    FS_LZX("9.1.bin"),

    FAT(0x00280000, 0x2, ""), // 0x00020000
    FS_RAW("9.info"),
    FS_LZX("9.0.bin"),
    FS_LZX("9.1.bin"),

    FAT(0x002a0000, 0x2, ""), // 0x00020000
    FS_RAW("a.info"),
    FS_LZX("a.0.bin"),
    FS_LZX("a.1.bin"),

    FAT(0x002c0000, 0x1, ""), // 0x00020000
    FS_RAW("b.info"),
    FS_LZX("b.0.bin"),

    FAT(0x002e0000, 0xa, ""), // 0x00020000
    FS_RAW("c.info"),
    FS_LZX("c.0.bin"),
    FS_LZX("c.1.bin"),
    FS_LZX("c.2.bin"),
    FS_LZX("c.3.bin"),
    FS_LZX("c.4.bin"),
    FS_LZX("c.5.bin"),
    FS_LZX("c.6.bin"),
    FS_LZX("c.7.bin"),
    FS_LZX("c.8.bin"),
    FS_LZX("c.9.bin"),

    RAW(0x00300000, 0x00500000, "asset.bin"),
};

#undef RAW
#undef FAT
#undef FS_RAW
#undef FS_LZX

struct baku2_fat_entry {
    u32 offset;
    u32 size;
};
typedef struct baku2_fat_entry baku2_fat_entry;

struct baku2_fat {
    u32 data_offset;                            // Always 0x8008
    u32 entry_num;                              // Always 0x1000
    baku2_fat_entry table[];                    
};
typedef struct baku2_fat baku2_fat;

#ifdef BAKU2_DEBUG
#define baku2_log_debug(...)        printf(__VA_ARGS__); fflush(stdout);
#else
#define baku2_log_debug(...)
#endif // BAKU2_DEBUG

#ifdef BAKU2_ERROR
#define baku2_log_error(...)        printf(__VA_ARGS__); fflush(stdout);
#else
#define baku2_log_error(...)
#endif // BAKU2_ERROR

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

// 加入 lz library
#define LZ_MODULE
#include <lz.c>

sptr main(sptr argc, u8 **argv) {
    u8 rom[BAKU2_ROM_SIZE];
    u8 buf[BAKU2_BUF_SIZE];
    u8 *out;

    if (argc != 0x4) {
        printf("main : Usage %s [d|e] [src] [dst].\n", argv[0x0]);
        return 0x1;
    }

    out = buf;
    do {
        *out = 0x0;
        out++;
    } while (out < &buf[lz_win_size]);

    // -------------------------------------------------------------------------------- unpack --------------------------------------------------------------------------------
    switch (argv[0x1][0x0]) {
        case 0x44:
		case 0x64:
        {
            baku2_info *pc, *pd;
            u8 path[0x100];
            u8 *path_arg;

            // 讀取 rom
            {
                FILE *fp;

                fp = fopen(argv[0x2], "rb");
                if (!fp) {
                    baku2_log_error("unpack : cannot open %s for reading\n", argv[0x2]);
                    return 0x1;
                }
                fread(rom, BAKU2_ROM_SIZE, 0x1, fp);
                fclose(fp);
            }

            // 計算輸出路徑
            path_arg = &path[-0x1];
            {
                u8 *p;
                u8 c;

                p = argv[0x3];
                do {
                    path_arg++;
                    c = *p;

                    // 如果遇到資料夾就嘗試建立它 失敗也無所謂
                    if (c == '/' || c == '\\') {
                        *path_arg = 0x0; mkdir(path);
                    }

                    *path_arg = c;
                    p++;
                } while (c);

                // 如果最後一個字元不是資料夾 加上一個斜線
                c = path_arg[-0x1];
                if (c != '/' && c != '\\') {
                    *path_arg = '/';
                    path_arg++;
                }
            }

            // 根據資訊解包檔案
            pc = &baku2_fat_info[0x0];
            pd = (baku2_info*)(((uptr)baku2_fat_info) + sizeof(baku2_fat_info));
            while (pc < pd) {
                switch (pc->raw.type) {
                
                case BAKU2_RAW:
                    {
                        FILE *fp;
                        uptr strn;

                        // 計算輸出檔案路徑
                        {
                            u8 *p0, *p1, *p2;
                            u8 c;

                            p0 = pc->raw.name;
                            p1 = path_arg;
                            p2 = &p0[baku2_info_raw_name_size];
                            do {
                                c = *p0;
                                *p1 = c;

                                // \0 表示檔名到此結束
                                if (!c) { break; }

                                // 如果遇到資料夾就嘗試建立它 失敗也無所謂
                                if (c == '/' || c == '\\') {
                                    *path_arg = 0x0; mkdir(path);
                                }

                                p0++;
                                p1++;
                            } while (p0 < p2);
                        }

                        // 嘗試開啟輸出檔案
                        fp = fopen(path, "wb");
                        if (!fp) {
                            baku2_log_error("unpack : cannot open %s for writing\n", path);
                            pc++;
                            break;
                        }

                        // 直接寫入到輸出檔案
                        strn = pc->raw.size;
                        baku2_log_debug("file = %s, d = %X\n", path, strn);
                        fwrite(&rom[pc->raw.addr], strn, 0x1, fp);
                        fclose(fp);

                        pc++;
                    }
                    break;

                case BAKU2_FAT:
                    {
                        baku2_fat *fat;
                        baku2_fat_entry *tbl;
                        uptr num, base;
                        u8 *path_fat;
                        
                        // 讀取檔案借用表
                        fat = (baku2_fat*)&rom[pc->fat.addr];
                        base = bswap32(fat->data_offset);
                        num = bswap32(fat->entry_num);
                        tbl = &fat->table[num];
                        // fat->data_offset = base;
                        // fat->entry_num = num;
                        base = ((uptr)fat) + base;
                        do {
                            tbl--;
                            tbl->offset = bswap32(tbl->offset);
                            tbl->size = bswap32(tbl->size);
                        } while (--num);

                        // 檔案總數
                        num = pc->fat.size;

                        // 更新計數器
                        pc++;

                        // 計算檔頭路徑
                        path_fat = path_arg;
                        {
                            u8 *p;
                            u8 c;

                            p = pc[-0x1].fat.name;
                            do {
                                c = *p;
                                
                                // \0 表示檔名到此結束
                                if (!c) { break; }

                                // 如果遇到資料夾就嘗試建立它 失敗也無所謂
                                if (c == '/' || c == '\\') {
                                    *path_arg = 0x0; mkdir(path);
                                }

                                p++;
                                *path_fat = c;
                                path_fat++;
                            } while (p < (u8*)pc);
                        }

                        // 輸出檔案
                        do {
                            FILE *fp;
                            u8 *strm;
                            u32 strn;

                            // 計算輸出檔案路徑
                            {
                                u8 *p0, *p1, *p2;
                                u8 c;

                                p0 = pc->arc.name;
                                p1 = path_fat;
                                p2 = &p0[baku2_info_arc_name_size];
                                do {
                                    c = *p0;
                                    *p1 = c;
                                    if (!c) { break; }
                                    p0++;
                                    p1++;
                                } while (p0 < p2);
                            }

                            // 嘗試開啟輸出檔案
                            fp = fopen(path, "wb");
                            if (!fp) {
                                baku2_log_error("unpack : cannot open %s for writing\n", path);
                                pc++;
                                continue;
                            }

                            // 取得資料流指針及大小
                            strm = (u8*)(base + tbl->offset);
                            strn = tbl->size;

                            // 根據類別讀取並輸出檔案
                            switch (pc->arc.type) {
                            case BAKU2_FS_RAW:

                                // 直接寫入到輸出檔案
                                fwrite(strm, strn, 0x1, fp);
                                break;

                            case BAKU2_FS_LZX:
                                {
                                    uptr dsize;

                                    // 壓縮檔格式 : | 解壓大小 (4) | 壓縮資料 (*) |
                                    dsize = (strm[0x0] << 0x18) | (strm[0x1] << 0x10) | (strm[0x2] << 0x08) | (strm[0x3] << 0x00);
                                    
                                    // 壓縮的檔案至少要有 8 byte
                                    baku2_log_debug("file = %s, c = %X, d = %X\n", path, strn, dsize);
                                    if (strn <= 0x8) {
                                        baku2_log_error("unpack : invaild lz archive %s\n", path);
                                        break;
                                    }

                                    // 解壓縮
                                    lzDecode(out, &strm[0x4], dsize, strn - 0x4);

                                    // 寫入結果到輸出檔案
                                    // fwrite(&strm[0x4], 0x4, 0x1, fp);
                                    fwrite(out, dsize, 0x1, fp);
                                }
                                break;
                            }

                            // 關閉輸出檔案
                            fclose(fp);

                            // 指到下一個檔案並更新計數器
                        } while (tbl++, pc++, num--);
                    }
                    break;
                
                }
            }
        }
        break;

    // -------------------------------------------------------------------------------- repack --------------------------------------------------------------------------------
    case 0x45:
    case 0x65:
        {
            baku2_info *pc, *pd;
            u8 path[0x100];
            u8 *path_arg;

            // 計算輸出路徑
            path_arg = &path[-0x1];
            {
                u8 *p;
                u8 c;

                p = argv[0x3];
                do {
                    path_arg++;
                    c = *p;
                    
                    // 如果遇到資料夾就嘗試建立它 失敗也無所謂
                    if (c == '/' || c == '\\') {
                        *path_arg = 0x0; mkdir(path);
                    }

                    *path_arg = c;
                    p++;
                } while (c);

                // 如果最後一個字元不是資料夾 加上一個斜線
                c = path_arg[-0x1];
                if (c != '/' && c != '\\') {
                    *path_arg = '/';
                    path_arg++;
                }
            }

            // 根據資訊組合檔案
            pc = &baku2_fat_info[0x0];
            pd = (baku2_info*)(((uptr)baku2_fat_info) + sizeof(baku2_fat_info));
            while (pc < pd) {
                switch (pc->raw.type) {
                
                case BAKU2_RAW:
                    {
                        FILE *fp;
                        uptr strn;

                        // 計算輸入檔案路徑
                        {
                            u8 *p0, *p1, *p2;
                            u8 c;

                            p0 = pc->raw.name;
                            p1 = path_arg;
                            p2 = &p0[baku2_info_raw_name_size];
                            do {
                                c = *p0;
                                *p1 = c;
                                if (!c) { break; }
                                p0++;
                                p1++;
                            } while (p0 < p2);
                        }

                        // 嘗試開啟輸出檔案
                        fp = fopen(path, "rb");
                        if (!fp) {
                            baku2_log_error("repack : cannot open %s for reading\n", path);
                            pc++;
                            break;
                        }

                        // 直接寫入到輸出檔案
                        strn = fread(&rom[pc->raw.addr], 0x1, pc->raw.size, fp);
                        baku2_log_debug("file = %s, d = %X\n", path, strn);
                        fclose(fp);

                        pc++;
                    }
                    break;

                case BAKU2_FAT:
                    {
                        baku2_fat *fat;
                        baku2_fat_entry *tbl;
                        uptr num, base;
                        u8 *path_fat, *strm;
                        
                        // 寫入檔案借用表
                        fat = (baku2_fat*)&rom[pc->fat.addr];
                        base = ((uptr)fat) + BAKU2_PACK_FAT_BASE;
                        num = BAKU2_PACK_FAT_SIZE;
                        tbl = (baku2_fat_entry*)base;
                        fat->data_offset = BAKU2_PACK_FAT_BASE_NUS;
                        fat->entry_num = BAKU2_PACK_FAT_SIZE_NUS;
                        do {
                            tbl--;
                            tbl->offset = 0xFFFFFFFF;
                            tbl->size = 0xFFFFFFFF;
                        } while (--num);

                        // 檔案總數
                        num = pc->fat.size;

                        // 更新計數器
                        pc++;

                        // 計算檔頭路徑
                        path_fat = path_arg;
                        {
                            u8 *p;
                            u8 c;

                            p = pc[-0x1].fat.name;
                            do {
                                c = *p;
                                if (!c) { break; }
                                p++;
                                *path_fat = c;
                                path_fat++;
                            } while (p < (u8*)pc);
                        }

                        // 寫入檔案
                        strm = (u8*)base;
                        do {
                            FILE *fp;
                            u32 strn;

                            // 計算輸出檔案路徑
                            {
                                u8 *p0, *p1, *p2;
                                u8 c;

                                p0 = pc->arc.name;
                                p1 = path_fat;
                                p2 = &p0[baku2_info_arc_name_size];
                                do {
                                    c = *p0;
                                    *p1 = c;
                                    if (!c) { break; }
                                    p0++;
                                    p1++;
                                } while (p0 < p2);
                            }

                            // 嘗試開啟輸入檔案
                            fp = fopen(path, "rb");
                            if (!fp) {
                                baku2_log_error("repack : cannot open %s for reading\n", path);
                                pc++;
                                continue;
                            }

                            // 根據類別讀取並輸出檔案
                            switch (pc->arc.type) {
                            case BAKU2_FS_RAW:

                                // 直接寫入到輸出檔案
                                strn = fread(strm, 0x1, (uptr)&rom[BAKU2_ROM_SIZE] - (uptr)strm, fp);
                                baku2_log_debug("file = %s, d = %X\n", path, strn);
                                break;

                            case BAKU2_FS_LZX:
                                {
                                    uptr dsize;

                                    // 從輸入檔案讀取
                                    // fread(&strm[0x4], 0x4, 0x1, fp);
                                    dsize = fread(&out[lz_win_size], 0x1, BAKU2_ROM_SIZE, fp);

                                    // 壓縮 & 大小加上檔頭 8 byte
                                    strn = (uptr)lzEncode(&strm[0x4], &out[lz_win_size], (uptr)&rom[BAKU2_ROM_SIZE] - (uptr)strm, dsize) - (uptr)strm;
                                    baku2_log_debug("file = %s, c = %X, d = %X\n", path, strn, dsize);

                                    // 壓縮檔格式 : | 解壓大小 (4) | 壓縮資料 (*) |
                                    strm[0x0] = (u8)(dsize >> 0x18);
                                    strm[0x1] = (u8)(dsize >> 0x10);
                                    strm[0x2] = (u8)(dsize >> 0x08);
                                    strm[0x3] = (u8)(dsize >> 0x00);
                                }
                                break;
                            }

                            // 關閉輸入檔案
                            fclose(fp);

                            // 遊戲要求資料必須是 2bytes aligned
                            strn = strn + (strn & 0x1);

                            // 寫入資料流指針及大小
                            tbl->offset = bswap32((u32)((uptr)strm - base));
                            tbl->size = bswap32(strn);

                            // 更新輸出指針
                            strm += strn;

                            // 指到下一個檔案並更新計數器
                        } while (tbl++, pc++, num--);
                    }
                    break;
                
                }
            }
            

            // 寫入 rom
            {
                FILE *fp;

                fp = fopen(argv[0x2], "wb");
                if (!fp) {
                    baku2_log_error("repack : cannot open %s for writing\n", argv[0x2]);
                    return 0x1;
                }
                fwrite(rom, BAKU2_ROM_SIZE, 0x1, fp);
                fclose(fp);
            }
        }
        break;
    }

    return 0x0;
}

