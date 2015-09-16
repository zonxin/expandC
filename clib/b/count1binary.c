/*
 * 计算二进制数中 1 的个数
 */

#ifndef __CLIB_B_COUNT1BINARY_C__
#define __CLIB_B_COUNT1BINARY_C__

typedef unsigned int ELEMTYPE;
int count1binary(ELEMTYPE v)
{
    int num = 0;
    while(v){
        v &= (v-1);
        num++;
    }
    return num;
}

#endif
