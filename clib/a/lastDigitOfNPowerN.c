/* 给出一个整数n,求 n^n （n 的 n 次方）十进制表示的最后一位数字*/

#ifndef __CLIB_A_LASTDIGITOFNPOWERN_C__
#define __CLIB_A_LASTDIGITOFNPOWERN_C__

int lastDigitOfNPowerN(int n)
{
    int ret[20] = {0,1,4,7,6,5,6,3,6,9,0,1,6,3,6,5,6,7,4,9};
    if(n==0) return 1;
    return ret[n%20];
}

#endif

