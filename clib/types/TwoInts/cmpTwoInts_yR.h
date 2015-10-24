#ifndef __CLIB_TYPES_TWOINTS_CMPTWOINTS_YR_H__
#define __CLIB_TYPES_TWOINTS_CMPTWOINTS_YR_H__

#include "../TwoInts.h"
int cmpTwoInts_yR(const void *a,const void *b)
{ pTwoInts pa=(pTwoInts)a; pTwoInts pb=(pTwoInts)b; return (pb->y) - (pa->y); }

#endif
