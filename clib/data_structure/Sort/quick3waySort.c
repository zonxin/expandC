#ifndef __CLIB_DATA_STRUCTURE_SORT_QUICK3WAYSORT_C__
#define __CLIB_DATA_STRUCTURE_SORT_QUICK3WAYSORT_C__

int _quick3waySort_(Ord *a,int lo,int hi)
{
    if(lo >= hi) { return 0; }
    int i=lo+1,cmp,nlt=lo,ngt=hi;
    Ord v = a[lo],t;
    while(i<=ngt){
        cmp = compare(a[i],v);
        if(cmp < 0) {
            t = a[nlt]; a[nlt]=a[i]; a[i]=t;
            nlt++;i++;
        }else if(cmp > 0) {
            t = a[i];a[i]=a[ngt];a[ngt]=t;
            ngt--;
        }else { i++;}
    }
    _quick3waySort_(a,lo,nlt-1);
    _quick3waySort_(a,ngt+1,hi);
    return 0;
}

int quick3waySort(Ord *array,int n)
{
    _quick3waySort_(array,0,n-1);
    return 0;
}

#endif
