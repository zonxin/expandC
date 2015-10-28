/* 质数判断
 * 判断一个数是否为质数
 * */
#ifndef __CLIB_A_ISPRIME_C__
#define __CLIB_A_ISPRIME_C__

// CFLAGS 需要添加 -lm
#include <math.h>
int isPrime(int n)
{
    int i,s=(int)sqrt(n);
    for(i=2;i<=s;i++){
        if(n%i==0) return 0;
    }
    return 1;
}

#endif
