#ifndef __CLIB_DATA_STRUCTURE_SORT_HEAPSORT_C__
#define __CLIB_DATA_STRUCTURE_SORT_HEAPSORT_C__

int _sinkForSort_(Ord *pq,int k,int N)
{
    Ord t;
    int j;
    while(2*k <=N){
        j=2*k;
        if(j<N && lt(pq[j],pq[j+1])) { j++; }
        if(!lt(pq[k],pq[j])) { break; }
        t = pq[k];
        pq[k] = pq[j];
        pq[j] = t;
        k = j;
    }
    return 0;
}
int heapSort(Ord *a,int n)
{
    int k;
    Ord t,*pq = a-1;
    for(k=n/2;k>=1;k--){ _sinkForSort_(pq,k,n); }
    while(n>1){
        t = pq[1];
        pq[1] = pq[n];
        pq[n] = t;
        n--;
        _sinkForSort_(pq,1,n);
    }
    return 0;
}

#endif
