/* 任务安排
 * 有N个任务需要执行，第i个任务计算时占Ri个空间，而后会释放一部分，最后储存计算
 * 结果需要占据Oi个空间（Oi < Ri）。例如：执行需要5个空间，最后储存需要2个空间
 * 。给出N个任务执行和存储所需的空间，问执行所有任务最少需要多少空间。
 * Tips: 两者差越大者优先
 * */
#ifndef __CLIB_B_TASKARRAGE_C__
#define __CLIB_B_TASKARRAGE_C__

#include<stdlib.h>
#include "../types/TwoInts.h"
#include "../types/TwoInts/cmpTwoInts_subR.h"
typedef TwoInts Task,*pTask;
int taskArrage(pTask ptsk,int n)
{
   int i,cur=0,max=0;;
   qsort(ptsk,n,sizeof(Task),cmpTwoInts_subR);
   for(i=0;i<n;i++){
       if(cur + ptsk[i].x > max){
           max = cur + ptsk[i].x;
       }
       cur += ptsk[i].y;
   }
   return max; 
}
#endif
