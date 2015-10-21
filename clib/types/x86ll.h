/* Fixed-size types, underlying types depend on word size and compiler.  */
#ifndef __CLIB_TYPES_X86LL_H__
#define __CLIB_TYPES_X86LL_H__
/*不是所有的编译器都支持 long long*/
typedef signed char int8;
typedef unsigned char uint8;
typedef signed short int int16;
typedef unsigned short int uint16;
typedef signed int int32;
typedef unsigned int uint32;
typedef signed long long int int64;
typedef unsigned long long int uint64;

#endif

