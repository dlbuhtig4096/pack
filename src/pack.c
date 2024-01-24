/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
pack.c
用於 Baku Bomberman 系列中檔案系統的工具組

*/

// 選項

#define BAKU_DEBUG
#define BAKU_ERROR

// 緩存參數

#define BAKU_ROM_SIZE      0x01000000
#define BAKU_BUF_SIZE      0x00100000
#define BAKU_CFG_SIZE      0x00100000

// 組合參數

#define BAKU_PACK_FAT_BASE             0x00008008
#define BAKU_PACK_FAT_BASE_NUS         0x08800000
#define BAKU_PACK_FAT_SIZE             0x00001000
#define BAKU_PACK_FAT_SIZE_NUS         0x00100000

// 功能

#define PACK_LZX
#define PACK_LZY
#define PACK_YAY

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
#include <pack.h>

// 加入 lz library
#if defined(PACK_LZX) || defined(PACK_LZY)
#define LZ_MODULE
#include <lz.c>
#endif

// 加入 yay0 library
#if defined(PACK_YAY)
#define YAY0_MODULE
#include <yay0.c>
#endif

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/
sptr main(sptr argc, u8 **argv) {
    u8 rom[BAKU_ROM_SIZE], buf[BAKU_BUF_SIZE];
    u8 *out;
    union {
        u8 raw[BAKU_CFG_SIZE];
        pack info;
    } cfg;

    if (argc != 0x5) {
        printf("main : Usage %s [d|e] [cfg] [src] [dst].\n", argv[0x0]);
        return 0x1;
    }

    // 讀取 cfg
    {
        FILE *fp;

        fp = fopen(argv[0x2], "rb");
        if (!fp) {
            baku_log_error("unpack : cannot open %s for reading\n", argv[0x2]);
            return 0x1;
        }
        fread(&cfg.raw[0x0], BAKU_CFG_SIZE, 0x1, fp);
        cfg.info.eof = ftell(fp);
        fclose(fp);
    }

    out = &rom[cfg.info.rom];
    while (out > &rom[0x0]) { *--out = 0x0; };

    out = &buf[lz_win_size];
    do { *--out = 0x0; } while (out < &buf[0x0]);

    // -------------------------------------------------------------------------------- unpack --------------------------------------------------------------------------------
    switch (argv[0x1][0x0]) {
        case 0x44:
        case 0x64:
        {
            pack_info *pc, *pd;
            u8 path[0x100];
            u8 *path_arg;

            // 讀取 rom
            {
                FILE *fp;

                fp = fopen(argv[0x3], "rb");
                if (!fp) {
                    baku_log_error("unpack : cannot open %s for reading\n", argv[0x3]);
                    return 0x1;
                }
                fread(rom, BAKU_ROM_SIZE, 0x1, fp);
                fclose(fp);
            }

            // 計算輸出路徑
            path_arg = &path[-0x1];
            {
                u8 *p;
                u8 c;

                p = argv[0x4];
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
            pc = cfg.info.fs;
            pd = (pack_info*)(((uptr)&cfg.raw[0x0]) + cfg.info.eof);
            while (pc < pd) {
                switch (pc->raw.type) {
                
                case BAKU_RAW:
                    {
                        FILE *fp;
                        uptr strn;

                        // 計算輸出檔案路徑
                        {
                            u8 *p0, *p1, *p2;
                            u8 c;

                            p0 = pc->raw.name;
                            p1 = path_arg;
                            p2 = &p0[pack_info_raw_name_size];
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
                            baku_log_error("unpack : cannot open %s for writing\n", path);
                            pc++;
                            break;
                        }

                        // 直接寫入到輸出檔案
                        strn = pc->raw.size;
                        baku_log_debug("file = %s, d = %X\n", path, strn);
                        fwrite(&rom[pc->raw.addr], strn, 0x1, fp);
                        fclose(fp);

                        pc++;
                    }
                    break;

                case BAKU_FAT:
                    {
                        baku_fat *fat;
                        baku_fat_entry *tbl;
                        uptr num, base;
                        u8 *path_fat;
                        
                        // 讀取檔案借用表
                        fat = (baku_fat*)&rom[pc->fat.addr];
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
                                    *path_fat = 0x0; mkdir(path);
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
                                p2 = &p0[pack_info_arc_name_size];
                                do {
                                    c = *p0;

                                    // 如果遇到資料夾就嘗試建立它 失敗也無所謂
                                    if (c == '/' || c == '\\') {
                                        *p1 = 0x0; mkdir(path);
                                    }

                                    *p1 = c;
                                    // \0 表示檔名到此結束
                                    if (!c) { break; }

                                    p0++;
                                    p1++;
                                } while (p0 < p2);
                            }

                            // 嘗試開啟輸出檔案
                            fp = fopen(path, "wb");
                            if (!fp) {
                                baku_log_error("unpack : cannot open %s for writing\n", path);
                                pc++; num--;
                                continue;
                            }

                            // 取得資料流指針及大小
                            strm = (u8*)(base + tbl->offset);
                            strn = tbl->size;

                            // 根據類別讀取並輸出檔案
                            switch (pc->arc.type) {
                            case BAKU_FS_RAW:
#ifndef PACK_LZX
                            case BAKU_FS_LZX:
#endif
#ifndef PACK_LZY
                            case BAKU_FS_LZY:
#endif
#ifndef PACK_YAY
                            case BAKU_FS_YAY:
#endif
                                // 直接寫入到輸出檔案
                                baku_log_debug("file = %s, d = %X\n", path, strn);
                                fwrite(strm, strn, 0x1, fp);
                                break;

#ifdef PACK_LZX
                            case BAKU_FS_LZX:
                                {
                                    uptr dsize;

                                    // 壓縮檔格式 : | 解壓大小 (4) | 壓縮資料 (*) |
                                    dsize = (strm[0x0] << 0x18) | (strm[0x1] << 0x10) | (strm[0x2] << 0x08) | (strm[0x3] << 0x00);
                                    
                                    // 壓縮的檔案至少要有 4 byte
                                    baku_log_debug("file = %s, c = %X, d = %X\n", path, strn, dsize);
                                    if (strn <= 0x4) {
                                        baku_log_error("unpack : invaild lz archive %s\n", path);
                                        break;
                                    }

                                    // 解壓縮
                                    lzDecode(out, &strm[0x4], dsize, strn - 0x4);

                                    // 寫入結果到輸出檔案
                                    fwrite(out, dsize, 0x1, fp);
                                }
                                break;
#endif // PACK_LZX
#ifdef PACK_LZY
                            case BAKU_FS_LZY:
                                {
                                    uptr dsize;

                                    // 壓縮檔格式 : | 解壓大小 (4) | BSS 大小 (4) | 壓縮資料 (*) |
                                    dsize = (strm[0x0] << 0x18) | (strm[0x1] << 0x10) | (strm[0x2] << 0x08) | (strm[0x3] << 0x00);
                                    
                                    // 壓縮的檔案至少要有 8 byte
                                    baku_log_debug("file = %s, c = %X, d = %X\n", path, strn, dsize);
                                    if (strn <= 0x8) {
                                        baku_log_error("unpack : invaild lz archive %s\n", path);
                                        break;
                                    }

                                    // 解壓縮
                                    lzDecode(out, &strm[0x8], dsize, strn - 0x8);

                                    // 寫入結果到輸出檔案
                                    fwrite(&strm[0x4], 0x4, 0x1, fp);
                                    fwrite(out, dsize, 0x1, fp);
                                }
                                break;
#endif // PACK_LZY                     
#ifdef PACK_YAY      
                            case BAKU_FS_YAY:
                                {
                                    uptr dsize;

                                    // 壓縮檔格式 : | 解壓大小 (4) | 壓縮資料 (*) |
                                    dsize = (strm[0x0] << 0x18) | (strm[0x1] << 0x10) | (strm[0x2] << 0x08) | (strm[0x3] << 0x00);
                                    
                                    // 壓縮的檔案至少要有 4 byte
                                    baku_log_debug("file = %s, c = %X, d = %X\n", path, strn, dsize);
                                    if (strn <= 0x4) {
                                        baku_log_error("unpack : invaild lz archive %s\n", path);
                                        break;
                                    }

                                    // 解壓縮
                                    yay0Decode(out, &strm[0x4], dsize, strn - 0x4);

                                    // 寫入結果到輸出檔案
                                    fwrite(out, dsize, 0x1, fp);
                                }
                                break;
#endif // PACK_YAY
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
            pack_info *pc, *pd;
            u8 path[0x100];
            u8 *path_arg;

            // 計算輸出路徑
            path_arg = &path[-0x1];
            {
                u8 *p;
                u8 c;

                p = argv[0x4];
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
            pc = cfg.info.fs;
            pd = (pack_info*)(((uptr)&cfg.raw[0x0]) + cfg.info.eof);
            while (pc < pd) {
                switch (pc->raw.type) {
                
                case BAKU_RAW:
                    {
                        FILE *fp;
                        uptr strn;

                        // 計算輸入檔案路徑
                        {
                            u8 *p0, *p1, *p2;
                            u8 c;

                            p0 = pc->raw.name;
                            p1 = path_arg;
                            p2 = &p0[pack_info_raw_name_size];
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
                            baku_log_error("repack : cannot open %s for reading\n", path);
                            pc++;
                            break;
                        }

                        // 直接寫入到輸出檔案
                        strn = fread(&rom[pc->raw.addr], 0x1, pc->raw.size, fp);
                        baku_log_debug("file = %s, d = %X\n", path, strn);
                        fclose(fp);

                        pc++;
                    }
                    break;

                case BAKU_FAT:
                    {
                        baku_fat *fat;
                        baku_fat_entry *tbl;
                        uptr num, base;
                        u8 *path_fat, *strm;
                        
                        // 寫入檔案借用表
                        fat = (baku_fat*)&rom[pc->fat.addr];
                        base = ((uptr)fat) + BAKU_PACK_FAT_BASE;
                        num = BAKU_PACK_FAT_SIZE;
                        tbl = (baku_fat_entry*)base;
                        fat->data_offset = BAKU_PACK_FAT_BASE_NUS;
                        fat->entry_num = BAKU_PACK_FAT_SIZE_NUS;
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
                                p2 = &p0[pack_info_arc_name_size];
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
                                baku_log_error("repack : cannot open %s for reading\n", path);
                                pc++;
                                continue;
                            }

                            // 根據類別讀取並輸出檔案
                            switch (pc->arc.type) {
                            case BAKU_FS_RAW:
#ifndef PACK_LZX
                            case BAKU_FS_LZX:
#endif // PACK_LZX
#ifndef PACK_LZY
                            case BAKU_FS_LZY:
#endif // PACK_LZY
#ifndef PACK_YAY
                            case BAKU_FS_YAY:
#endif // PACK_YAY
                                // 直接寫入到輸出檔案
                                strn = fread(strm, 0x1, (uptr)&rom[BAKU_ROM_SIZE] - (uptr)strm, fp);
                                baku_log_debug("file = %s, d = %X\n", path, strn);
                                break;
#ifdef PACK_LZX
                            case BAKU_FS_LZX:
                                {
                                    uptr dsize;

                                    // 從輸入檔案讀取
                                    dsize = fread(&out[lz_win_size], 0x1, BAKU_ROM_SIZE, fp);

                                    // 壓縮 & 大小加上檔頭 4 byte
                                    strn = (uptr)lzEncode(&strm[0x4], &out[lz_win_size], (uptr)&rom[BAKU_ROM_SIZE] - (uptr)strm, dsize) - (uptr)strm;
                                    baku_log_debug("file = %s, c = %X, d = %X\n", path, strn, dsize);

                                    // 壓縮檔格式 : | 解壓大小 (4) | 壓縮資料 (*) |
                                    strm[0x0] = (u8)(dsize >> 0x18);
                                    strm[0x1] = (u8)(dsize >> 0x10);
                                    strm[0x2] = (u8)(dsize >> 0x08);
                                    strm[0x3] = (u8)(dsize >> 0x00);
                                }
                                break;
#endif // PACK_LZX
#ifdef PACK_LZY
                            case BAKU_FS_LZY:
                                {
                                    uptr dsize;

                                    // 從輸入檔案讀取
                                    fread(&strm[0x4], 0x4, 0x1, fp);
                                    dsize = fread(&out[lz_win_size], 0x1, BAKU_ROM_SIZE, fp);

                                    // 壓縮 & 大小加上檔頭 8 byte
                                    strn = (uptr)lzEncode(&strm[0x8], &out[lz_win_size], (uptr)&rom[BAKU_ROM_SIZE] - (uptr)strm, dsize) - (uptr)strm;
                                    baku_log_debug("file = %s, c = %X, d = %X\n", path, strn, dsize);

                                    // 壓縮檔格式 : | 解壓大小 (4) | BSS 大小 (4) | 壓縮資料 (*) |
                                    strm[0x0] = (u8)(dsize >> 0x18);
                                    strm[0x1] = (u8)(dsize >> 0x10);
                                    strm[0x2] = (u8)(dsize >> 0x08);
                                    strm[0x3] = (u8)(dsize >> 0x00);
                                }
                                break;
#endif // PACK_LZY
#ifdef PACK_YAY
                            case BAKU_FS_YAY:
                                {
                                    uptr dsize;

                                    // 從輸入檔案讀取
                                    dsize = fread(&out[lz_win_size], 0x1, BAKU_ROM_SIZE, fp);

                                    // 壓縮 & 大小加上檔頭 4 byte
                                    strn = (uptr)yay0Encode(&strm[0x4], &out[lz_win_size], (uptr)&rom[BAKU_ROM_SIZE] - (uptr)strm, dsize) - (uptr)strm;
                                    baku_log_debug("file = %s, c = %X, d = %X\n", path, strn, dsize);

                                    // 壓縮檔格式 : | 解壓大小 (4) | 壓縮資料 (*) |
                                    strm[0x0] = (u8)(dsize >> 0x18);
                                    strm[0x1] = (u8)(dsize >> 0x10);
                                    strm[0x2] = (u8)(dsize >> 0x08);
                                    strm[0x3] = (u8)(dsize >> 0x00);
                                }
                                break;
#endif // PACK_YAY
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

                fp = fopen(argv[0x3], "wb");
                if (!fp) {
                    baku_log_error("repack : cannot open %s for writing\n", argv[0x3]);
                    return 0x1;
                }
                fwrite(rom, cfg.info.rom, 0x1, fp);
                fclose(fp);
            }
        }
        break;
    }

    return 0x0;
}

