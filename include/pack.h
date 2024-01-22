
#ifndef __PACK__
#include <env.h>

// 型態

#define baku_info_raw_name_size    0x17
struct baku_info_raw {
    u32 addr;
    u32 size;
    u8 name[baku_info_raw_name_size];
    u8 type;
};
typedef struct baku_info_raw baku_info_raw;

#define baku_info_fat_name_size    0x17
struct baku_info_fat {
    u32 addr;
    u32 size;
    u8 name[baku_info_fat_name_size];
    u8 type;
};
typedef struct baku_info_fat baku_info_fat;

#define baku_info_arc_name_size    0x1F
struct baku_info_arc {
    u8 name[baku_info_arc_name_size];
    u8 type;
};
typedef struct baku_info_arc baku_info_arc;

union baku_info {
    baku_info_raw raw;
    baku_info_fat fat;
    baku_info_arc arc;
};
typedef union baku_info baku_info;

enum baku_fs_type {
    BAKU_RAW,
    BAKU_FAT,
    BAKU_NONE
};

enum baku_arc_type {
    BAKU_FS_RAW,
    BAKU_FS_LZX,
    BAKU_FS_LZY,
    BAKU_FS_YAY,
    BAKU_FS_NONE
};

#define RAW(raw_addr, raw_size, raw_name)                                                       \
    {.fat = {.addr = raw_addr, .size = raw_size, .name = raw_name, .type = BAKU_RAW }}

#define FAT(fat_addr, fat_size, fat_name)                                                       \
    {.fat = {.addr = fat_addr, .size = fat_size, .name = fat_name, .type = BAKU_FAT }}

#define FS_RAW(arc_name)                                                                        \
    {.arc = {.name = arc_name, .type = BAKU_FS_RAW }}

#define FS_LZX(arc_name)                                                                         \
    {.arc = {.name = arc_name, .type = BAKU_FS_LZX }}

#define FS_LZY(arc_name)                                                                         \
    {.arc = {.name = arc_name, .type = BAKU_FS_LZY }}

#define FS_YAY(arc_name)                                                                         \
    {.arc = {.name = arc_name, .type = BAKU_FS_YAY }}

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
