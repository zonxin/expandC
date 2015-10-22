/*
 * 给一个整数 n，求n的阶乘末尾 0 的个数 
 * 《编程之美》，不要被阶乘吓到,P125
 */

#ifndef __CLIB_B_ZEROSINFACTORIAL_C__
#define __CLIB_B_ZEROSINFACTORIAL_C__

int zerosInFactorial(int n)
{
    int ret = 0;
    while(n)
    {
        ret += n/5;
        n /= 5;
    }
    return ret;
}

#endif
