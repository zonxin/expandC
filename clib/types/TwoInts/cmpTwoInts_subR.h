#ifndef __CLIB_TYPES_TWOINTS_CMPTWOINTS_SUBR_H__
#define __CLIB_TYPES_TWOINTS_CMPTWOINTS_SUBR_H__

#include "../TwoInts.h"
int cmpTwoInts_subR(const void *a,const void *b)
{ pTwoInts pa=(pTwoInts)a; pTwoInts pb=(pTwoInts)b; return (pb->x-pb->y) - (pa->x-pa->y); }

#endif
