/* 冒泡排序
 * 与C语言库函数 qsort 使用方法相同
 */

#ifndef __CLIB_DATA_STRUCTURE_BUBBLESORT_C__
#define __CLIB_DATA_STRUCTURE_BUBBLESORT_C__

#include "swp.h"
int compare_int(const void *a,const void *b)
{ return *(int *)a - *(int *)b; }
void bubbleSort(void *base,size_t n,size_t size,
        int (*compare)(const void *,const void *))
{
    int i,j;
    for(i=0;i<n-1;i++){
    for(j=0;j<n-1-j;j++){
        if(compare(base+j*size,base+(j+1)*size)>0) {
            swp(base+j*size,base+(j+1)*size,size);
        }
    } }
}

#endif
