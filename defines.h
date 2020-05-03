#ifndef DEFINES
#define DEFINES

#include <stdint.h>
#include <float.h>

enum Types{UINT8 = 0,UINT16,UINT32,UINT64,INT8,INT16,INT32,INT64,CHAR,UCHAR,FLOAT,DOUBLE,LONGDOUBLE};

typedef enum Types Types;

#define DFT_CERO_U64 (uint64_t) 0
#define DFT_CERO_U32 (uint32_t) 0
#define DFT_CERO_U16 (uint16_t) 0
#define DFT_CERO_U8  (uint8_t)  0

#define DFT_UNO_U64 (uint64_t) 1
#define DFT_UNO_U32 (uint32_t) 1
#define DFT_UNO_U16 (uint16_t) 1
#define DFT_UNO_U8  (uint8_t)  1

#define DFT_MAX_U64 (uint64_t) 0xFFFFFFFFFFFFFFFF
#define DFT_MAX_U32 (uint64_t) 0xFFFFFFFF
#define DFT_MAX_U16 (uint64_t) 0xFFFF
#define DFT_MAX_U8  (uint64_t) 0xFF

#define DFT_MAX_64 (uint64_t) 0x7FFFFFFFFFFFFFFF
#define DFT_MAX_32 (uint64_t) 0x7FFFFFFF
#define DFT_MAX_16 (uint64_t) 0x7FFF
#define DFT_MAX_8  (uint64_t) 0x7F

#define DFT_MAX_FLOAT		(float)			FLT_MAX
#define DFT_MAX_DOUBLE		(double) 		DBL_MAX
#define DFT_MAX_LONGDOUBLE	(long double)	LDBL_MAX

#define DFT_MIN_FLOAT		(float)			FLT_MIN
#define DFT_MIN_DOUBLE		(double) 		DBL_MIN
#define DFT_MIN_LONGDOUBLE	(long double)	LDBL_MIN

#define TRUE  DFT_UNO_U8
#define FALSE DFT_CERO_U8
#define OK    DFT_UNO_U8
#define ERR   DFT_CERO_U8

typedef uint8_t bool;




#endif