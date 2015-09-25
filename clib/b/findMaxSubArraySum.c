/*
 * 有一个具有 n 个元素的向量 ar，求任何连续子向量的最大和。
 * 例如，ar = [31,-41,59,26,-53,58,97,-93,-23,-84]
 * 则有，ar[2..6] 和最大，为 187
 * 《编程珠玑》第二版，P77-81
 */


#ifndef __CLIB_B_FINDSUBARRAYSUM_C__
#define __CLIB_B_FINDSUBARRAYSUM_C__

#include "../a/Math_max.h"
typedef int ELEMTYPE;

ELEMTYPE findMaxSubArraySum(ELEMTYPE *ar,int n)
{
    ELEMTYPE maxsofar=0,maxendinghere=0;
    int i=0;
    for(i=0;i<n;i++){
        maxendinghere = max(maxendinghere+ar[i],0);
        maxsofar = max(maxsofar,maxendinghere);
    }
    return maxsofar;
}

#endif
