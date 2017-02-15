#ifndef __CLIB_DATA_STRUCTURE_MINPQ_C__
#define __CLIB_DATA_STRUCTURE_MINPQ_C__

#include <malloc.h>
typedef struct _MinPQ_ {
    Ord *pq;
    int size;
    // int capacity;
} *MinPQ;
MinPQ newMinPQ(int n)
{
    MinPQ h = (MinPQ)malloc(sizeof(struct _MinPQ_));
    h -> pq = (Ord *)malloc(sizeof(Ord)*(n+1));
    h -> size = 0;
    // h -> capacity = n;
    return h;
}
void freeMinPQ(MinPQ h)
{
    free(h->pq);
    free(h);
}

int MinPQ_sink(MinPQ h,int k)
{
    int N = h->size,j;
    Ord t;
    while(2*k <= N){
        j = 2*k;
        if(j<N && gt(h->pq[j],h->pq[j+1])) { j++; }
        if(!gt(h->pq[k],h->pq[j])) { break; }
        t = h->pq[k];
        h->pq[k] = h->pq[j]; 
        h->pq[j] = t;
        k = j;
    }
    return 0;
}
int MinPQ_swim(MinPQ h,int k)
{
    Ord t;
    while(k>1 && gt(h->pq[k/2],h->pq[k])) {
       t = h->pq[k/2]; 
       h->pq[k/2] = h->pq[k]; 
       h->pq[k] = t;
       k /= 2;
    }
    return 0;
}

int MinPQ_insert(MinPQ h,Ord v)
{
    (h->size)++;
    h->pq[h->size] = v;
    MinPQ_swim(h,h->size);
    return 0;
}
int MinPQ_delMin(MinPQ h,Ord *m)
{
    // 为了计算方便不使用下标 0
    if(h->size<=0) { return 0; }
    *m = h->pq[1];
    h->pq[1] = h->pq[(h->size)--];
    MinPQ_sink(h,1);
    return 1;
}

#endif
