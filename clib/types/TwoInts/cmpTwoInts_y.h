#ifndef __CLIB_TYPES_TWOINTS_CMPTWOINTS_Y_H__
#define __CLIB_TYPES_TWOINTS_CMPTWOINTS_Y_H__

#include "../TwoInts.h"
int cmpTwoInts_y(const void *a,const void *b)
{ pTwoInts pa=(pTwoInts)a; pTwoInts pb=(pTwoInts)b; return (pa->y) - (pb->y); }

#endif

