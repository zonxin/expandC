#ifndef __CLIB_B_FINDMAXPLDRMSUBSTR_C__
#define __CLIB_B_FINDMAXPLDRMSUBSTR_C__
#include <malloc.h>
#include <string.h>

#include "../../clib/a/Math_max.h"
#include "../../clib/a/Math_min.h"

int findMaxPldrmSubstr(char *str)
{
/* 将原始字符串中间插入特殊字符 # ,不是真的插入
 * str        :  0   1   2   3   4    5    length = 6
 * str ins sym:# 0 # 1 # 2 # 3 # 4 #  5  #   length = 13
 * index      :0 1 2 3 4 5 6 7 8 9 10 11 12
 */
    int length = strlen(str)*2 + 1;
    int *f = (int *)malloc(sizeof(int)*length);
    int i,k,t,
        position = 1,
        j = 0,
        maxIcalcedByJ = 0, // 当前可以使用 J 计算的最大 I 值
        maxPldrmStrLength = 1; // 目前最大的回文子字符
    // if(length <= 0) { return 0; }
    f[0] = 1;
    for( i = 1;str[i/2];i++){
        /* f(i) >= min { f(2j-i),f(j)-2(i-j) } ,for j<=i<= j+f(j)/2 */
        k = i%2?3:1; t= 0;
        if(i<maxIcalcedByJ) { 
            t = Math_min(f[2*j-i],f[j]-2*(i-j)); 
        }
        k =Math_max(k,t);
        k = i%2?(k+3)/4*2:(k+1)/4*2+1;

        while(i-k>=0&&str[(i+k)/2]&&str[(i-k)/2] == str[(i+k)/2]) k+=2; 
        f[i] = k*2 -1;
        if(maxPldrmStrLength< f[i]) {
            position = i;
            maxPldrmStrLength = f[i];
        }
        if(i+f[i]/2 > maxIcalcedByJ){
            j = i;
            maxIcalcedByJ = i+f[i]/2;
        }
    }
    free(f);
    // return (position-(maxPldrmStrLength-1)/2)/2; // 计算起始位置,多个相同的返回最小的
    return (maxPldrmStrLength-1)/2; // 返回长度
}

#endif
