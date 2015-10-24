/* 活动安排2
 * 有若干个活动，第i个开始时间和结束时间是[Si,Fi)，活动之间不能交叠，要把活动都
 * 安排完，至少需要几个教室？
 */
#ifndef __CLIB_B_SCHEDULEARRAGE2_C__
#define __CLIB_B_SCHEDULEARRAGE2_C__

#include <stdlib.h>
#include "../types/int/cmp_int.h"

int scheduleArrage2(int *s,int *f,int n)
{
    int max=0,count=0;
    qsort(s,n,sizeof(int),cmp_int);
    qsort(f,n,sizeof(int),cmp_int);
    int i=0,j=0;
    while(1){
        if(s[i]<f[j]) {
            count++;i++;
            max = max > count?max:count;
        }else{
            count--;j++;
        }
        if(i==n) { break; }
    }
    return max;
}

#endif
