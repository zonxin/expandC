#ifndef __CLIB_DATA_STRUCTURE_SORT_INSECTIONSORT_C__
#define __CLIB_DATA_STRUCTURE_SORT_INSECTIONSORT_C__

int insectionSort(Ord *a,int n)
{
    int i,j;
    Ord t;
    for(i=1;i<n;i++){
        for(j=i;j>0&&lt(a[j],a[j-1]);j--){
            t = a[j];a[j]=a[j-1];a[j-1]=t;
        }
    }
    return 0;
}

#endif
