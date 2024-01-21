
#ifndef __ENV__
#define __ENV__


#include <stdint.h>

typedef int8_t s8;
typedef uint8_t u8;
typedef int16_t s16;
typedef uint16_t u16;
typedef int32_t s32;
typedef uint32_t u32;
typedef int64_t s64;
typedef uint64_t u64;
typedef float f32;
typedef double f64;
typedef s64 sptr;
typedef u64 uptr;
typedef union any {
    s8 s8;
    u8 u8;
    s16 s16;
    u16 u16;
    s32 s32;
    u32 u32;
    s64 s64;
    u64 u64;
    f32 f32;
    f64 f64;
} any;

#endif
