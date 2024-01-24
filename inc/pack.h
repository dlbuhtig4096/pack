
#ifndef __PACK__
#include <env.h>

// 型態

#define pack_info_raw_name_size    0x17
struct pack_info_raw {
    u32 addr;
    u32 size;
    u8 name[pack_info_raw_name_size];
    u8 type;
};
typedef struct pack_info_raw pack_info_raw;

#define pack_info_fat_name_size    0x17
struct pack_info_fat {
    u32 addr;
    u32 size;
    u8 name[pack_info_fat_name_size];
    u8 type;
};
typedef struct pack_info_fat pack_info_fat;

#define pack_info_arc_name_size    0x1F
struct pack_info_arc {
    u8 name[pack_info_arc_name_size];
    u8 type;
};
typedef struct pack_info_arc pack_info_arc;

union pack_info {
    pack_info_raw raw;
    pack_info_fat fat;
    pack_info_arc arc;
};
typedef union pack_info pack_info;

struct pack {
    u8 id[0x18];
    u32 rom;
    u32 eof;
    pack_info fs[];
};
typedef struct pack pack;

enum pack_fs_type {
    BAKU_RAW,
    BAKU_FAT,
    BAKU_NONE
};

enum pack_arc_type {
    BAKU_FS_RAW,
    BAKU_FS_LZX,
    BAKU_FS_LZY,
    BAKU_FS_YAY,
    BAKU_FS_NONE
};

struct baku_fat_entry {
    u32 offset;
    u32 size;
};
typedef struct baku_fat_entry baku_fat_entry;

struct baku_fat {
    u32 data_offset;                            // Always 0x8008
    u32 entry_num;                              // Always 0x1000
    baku_fat_entry table[];                    
};
typedef struct baku_fat baku_fat;

#ifdef BAKU_DEBUG
#define baku_log_debug(...)        printf(__VA_ARGS__); fflush(stdout);
#else
#define baku_log_debug(...)
#endif // BAKU_DEBUG

#ifdef BAKU_ERROR
#define baku_log_error(...)        printf(__VA_ARGS__); fflush(stdout);
#else
#define baku_log_error(...)
#endif // BAKU_ERROR

/*
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>

#endif
