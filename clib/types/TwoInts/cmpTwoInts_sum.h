#ifndef __CLIB_TYPES_TWOINTS_CMPTWOINTS_SUM_H__
#define __CLIB_TYPES_TWOINTS_CMPTWOINTS_SUM_H__

#include "../TwoInts.h"
int cmpTwoInts_sum(const void *a,const void *b)
{ pTwoInts pa=(pTwoInts)a; pTwoInts pb=(pTwoInts)b; return (pa->x+pa->y) - (pb->x+pb->y); }

#endif
