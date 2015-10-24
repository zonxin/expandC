#ifndef __CLIB_TYPES_TWOINTS_CMPTWOINTS_XR_H__
#define __CLIB_TYPES_TWOINTS_CMPTWOINTS_XR_H__

#include "../TwoInts.h"
int cmpTwoInts_xR(const void *a,const void *b)
{ pTwoInts pa=(pTwoInts)a; pTwoInts pb=(pTwoInts)b; return (pb->x) - (pa->x); }

#endif

