#ifndef __CLIB_TYPES_TWOINTS_CMPTWOINTS_SUMR_H__
#define __CLIB_TYPES_TWOINTS_CMPTWOINTS_SUMR_H__

#include "../TwoInts.h"
int cmpTwoInts_sumR(const void *a,const void *b)
{ pTwoInts pa=(pTwoInts)a; pTwoInts pb=(pTwoInts)b; return (pb->x+pb->y) - (pa->x+pa->y); }

#endif
