#ifndef __CLIB_TYPES_TWOINTS_CMPTWOINTS_X_H__
#define __CLIB_TYPES_TWOINTS_CMPTWOINTS_X_H__

#include "../TwoInts.h"
int cmpTwoInts_x(const void *a,const void *b)
{ pTwoInts pa=(pTwoInts)a; pTwoInts pb=(pTwoInts)b; return (pa->x) - (pb->x); }

#endif

