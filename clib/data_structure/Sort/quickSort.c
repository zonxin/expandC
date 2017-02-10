#ifndef __CLIB_DATA_STRUCTURE_SORT_QUICKSORT_C__
#define __CLIB_DATA_STRUCTURE_SORT_QUICKSORT_C__

int _partition_(Ord *a,int lo,int hi)
{
    Ord v = a[lo]; hi++;
    while(lo < hi){
        while(lo<hi && lt(v,a[--hi]));
        a[lo] = a[hi];
        while(lo<hi && lt(a[++lo],v));
        a[hi] = a[lo];
    }
    a[lo] = v;
    return lo;
}

int _quickSort_(Ord *a,int lo,int hi)
{
    if(lo >= hi) { return 0; };
    int pivotloc = _partition_(a,lo,hi);
    _quickSort_(a,lo,pivotloc-1);
    _quickSort_(a,pivotloc+1,hi);
    return 0;
}

int quickSort(Ord *a,int n)
{
    _quickSort_(a,0,n-1);
    return 0;
}

#endif
