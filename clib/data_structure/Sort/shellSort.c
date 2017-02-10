#ifndef __CLIB_DATA_STRUCTURE_SORT_SHELLSORT_C__
#define __CLIB_DATA_STRUCTURE_SORT_SHELLSORT_C__

int shellSort(Ord *a,int n)
{
    int i,j;
    int h = 1;
    Ord t;
    while(h < n/3) { h = 3*h+1; } // 1, 4, 13, 40, 121 ...
    while(h >=1){
        for(i=h;i<n;i++){
            for(j=i;j>=h&&lt(a[j],a[j-h]);j-=h){
                t=a[j];a[j]=a[j-h];a[j-h]=t;
            }
        }
        h /=3;
    }
    return 0;
}

#endif
