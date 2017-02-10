#ifndef __CLIB_DATA_STRUCTURE_SORT_SELECTIONSORT_C__
#define __CLIB_DATA_STRUCTURE_SORT_SELECTIONSORT_C__

int selectionSort(Ord *a,int n)
{
    int i,j,min;
    Ord t;
    for(i=0;i<n;i++){
        min = i;
        for(j=i+1;j<n;j++){
            if(lt(a[j],a[min])){ min = j; }
        }
        // 交换 i 和 最小值
        t = a[i];a[i] = a[min]; a[min] = t;
    }
    return 0;
}

#endif
