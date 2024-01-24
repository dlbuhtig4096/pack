
#ifndef __BAKU__
#define __BAKU__

#include <pack.h>

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

#endif
