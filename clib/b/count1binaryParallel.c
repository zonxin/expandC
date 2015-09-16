/*
 * 并行计算二进制数中 1 的个数
 */

#ifndef __CLIB_B_COUNT1BINARYPARALLEL_C__
#define __CLIB_B_COUNT1BINARYPARALLEL_C__


typedef unsigned int ELEMTYPE;
#define POW(c) (1<<(c))
#define MASK(c) (((unsigned long)-1)/(POW(POW(c))+1))
#define ROUND(n,c) (((n)& MASK(c))+((n)>>POW(c) & MASK(c)))

int count1binaryParallel(ELEMTYPE n)
{
    n = ROUND(n,0);
    n = ROUND(n,1);
    n = ROUND(n,2);
    n = ROUND(n,3);
    n = ROUND(n,4);
    return n;
}

#endif
