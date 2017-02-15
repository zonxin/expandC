#ifndef __CLIB_DATA_STRUCTURE_MAXPQ_C__
#define __CLIB_DATA_STRUCTURE_MAXPQ_C__

// #define Ord int
// #define lt(a,b) ((a)-(b)<0?1:0)
#include <malloc.h>
typedef struct _MaxPQ_ {
    Ord *pq;// 为了计算方便不使用下标 0
    int size;
    // int capacity;
} *MaxPQ;
MaxPQ newMaxPQ(int n)
{
    MaxPQ h = (MaxPQ)malloc(sizeof(struct _MaxPQ_));
    h -> pq = (Ord *)malloc(sizeof(Ord)*(n+1));
    h -> size = 0;
    // h -> capacity = n;
    return h;
}
void freeMaxPQ(MaxPQ h)
{
    free(h->pq);
    free(h);
}

int MaxPQ_sink(MaxPQ h,int k)
{
    int N = h->size,j;
    Ord t;
    while(2*k <= N){
        j = 2*k;
        if(j<N && lt(h->pq[j],h->pq[j+1])) { j++; }
        if(!lt(h->pq[k],h->pq[j])) { break; }
        t = h->pq[k];
        h->pq[k] = h->pq[j]; 
        h->pq[j] = t;
        k = j;
    }
    return 0;
}
int MaxPQ_swim(MaxPQ h,int k)
{
    Ord t;
    while(k>1 && lt(h->pq[k/2],h->pq[k])) {
       t = h->pq[k/2]; 
       h->pq[k/2] = h->pq[k]; 
       h->pq[k] = t;
       k /= 2;
    }
    return 0;
}

int MaxPQ_insert(MaxPQ h,Ord v)
{
    (h->size)++;
    h->pq[h->size] = v;
    MaxPQ_swim(h,h->size);
    return 0;
}
int MaxPQ_delMax(MaxPQ h,Ord *m)
{
    if(h->size <=0) { return 0; }
    *m = h->pq[1];
    h->pq[1] = h->pq[(h->size)--];
    MaxPQ_sink(h,1);
    return 1;
}

#endif
