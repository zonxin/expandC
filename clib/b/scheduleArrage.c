/* 活动安排
 * 有若干个活动，第i个开始时间和结束时间是[Si,fi)，只有一个教室，活动之间不能交
 * 叠，求最多安排多少个活动？ 
 * Tips:最先结束的优先
 */
#ifndef __CLIB_B_SCHEDULEARRAGE_C__
#define __CLIB_B_SCHEDULEARRAGE_C__

#include <stdlib.h>
#include "../types/TwoInts/cmpTwoInts_y.h"
#include "../types/TwoInts.h"
typedef  TwoInts Act,*pAct;
int scheduleArrage(pAct pA,int n )
{
    int i,j;
    int start,end;
    
    qsort(pA,n,sizeof(Act),cmpTwoInts_y);
    j=1;
    end = pA[0].y;
    for(i=1;i<n;i++){
        if(pA[i].x >= end){
            j++;
            end = pA[i].y;
        }
    }
    return j;
}

#endif

