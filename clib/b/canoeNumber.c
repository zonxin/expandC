/* 独木舟问题
 * n 个人，已知每个人体重，独木舟承重 m，每只独木舟最多坐两个人，总重量不超过独
 * 木舟承重，假设每个人体重也不超过独木舟承重，问最少需要几只独木舟
 */

#ifndef __CLIB_B_CANOENUMBER_C__
#define __CLIB_B_CANOENUMBER_C__

#include<stdlib.h>
#include "../types/int/cmp_int.h"
int canoeNumber(int *weight,int n,int m){
    int i=0,j=n-1;
    int count=0;
    qsort(weight,n,sizeof(int),cmp_int);
    while(j>=i){
        if( weight[j]+weight[i] <= m ) {
            j--;i++;count++;
        }else{
            j--;count++;
        }
    }
    return count;
}

#endif
