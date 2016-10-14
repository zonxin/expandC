#ifndef __CLIB_TYPES_TWOINTS_CMPTWOINTS_YR_H__
#define __CLIB_TYPES_TWOINTS_CMPTWOINTS_YR_H__

#include "../TwoInts.h"
int isEqualTwoInts(const void *a,const void *b)
{ pTwoInts pa=(pTwoInts)a; pTwoInts pb=(pTwoInts)b; return pa->x==pb->x && pa->y==pb->y; }

#endif
