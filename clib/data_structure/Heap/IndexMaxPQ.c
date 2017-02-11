#ifndef __CLIB_DATA_STRUCTURE_HEAP_INDEXMAXPQ_C__
#define __CLIB_DATA_STRUCTURE_HEAP_INDEXMAXPQ_C__

#include <malloc.h>
#include <string.h>
// typedef char Ord;
// #define lt(a,b) (a)>(b)?1:0
typedef struct _IndexMaxPQ_ {
    int *pq,*qp,size;
    Ord *keys;
    // int capacity;
} *IndexMaxPQ;
IndexMaxPQ newIndexMaxPQ(int n)
{
    IndexMaxPQ p = (IndexMaxPQ)malloc(sizeof(struct _IndexMaxPQ_));
    p->pq = (int *)malloc(sizeof(int)*(n+1));
    p->qp = (int *)malloc(sizeof(int)*n);
    p->keys = (Ord *)malloc(sizeof(Ord)*n);
    p->size = 0;
    memset(p->qp,-1,sizeof(int)*n);
    // p-> capacity = n;
    return p;
}
void freeIndexMaxPQ(IndexMaxPQ p)
{
    free(p->pq);free(p->qp);free(p->keys);
    free(p);
}

void _IndexMaxPQ_exch_(IndexMaxPQ p,int m,int n)
{
    int t = p->pq[m];
    p->pq[m] = p->pq[n];
    p->pq[n] = t;
    
    p->qp[p->pq[m]] = m;
    p->qp[p->pq[n]] = n;
}

#define _lt_(p,i,j)  lt((p)->keys[(p)->pq[(i)]],(p)->keys[(p)->pq[(j)]])
int IndexMaxPQ_swim(IndexMaxPQ p,int k)
{
    while(k>1 && _lt_(p,k/2,k)){
        _IndexMaxPQ_exch_(p,k/2,k);
        k/=2;
    }
    return 0;
}
int IndexMaxPQ_sink(IndexMaxPQ p,int k)
{
    int N = p->size,j;
    while(2*k <= N){
        j = 2*k;
        if(j<N && _lt_(p,j,j+1)) { j++; }
        if(!_lt_(p,k,j)) { break; }
        _IndexMaxPQ_exch_(p,k,j);
        k = j;
    }
    return 0;
}
#undef _lt_

int IndexMaxPQ_insert(IndexMaxPQ p,int k,Ord v){
    (p->size)++;
    p->qp[k] = p->size;
    p->pq[p->size] = k;
    p->keys[k] = v;
    IndexMaxPQ_swim(p,p->size);
    return 0;
}
Ord IndexMaxPQ_max(IndexMaxPQ p){
    return p->keys[p->pq[1]];
}
int IndexMaxPQ_delMax(IndexMaxPQ p){
    int index = p->pq[1],n=p->size;
    // 把最后一个放到堆顶
    p->pq[1] = p->pq[n];
    p->qp[p->pq[1]] = 1;
    p->qp[index] = -1;
    (p->size)--;
    IndexMaxPQ_sink(p,1);
    return index;
}

#define IndexMaxPQ_contains(p,k) ((p)->qp[(k)] != -1)
#define IndexMaxPQ_maxIndex(p) ((p)->pq[1])

int IndexMaxPQ_change(IndexMaxPQ p,int k,Ord v)
{
    // ASSERT(IndexMaxPQ_contains(p,k));
    p->keys[k] = v;
    IndexMaxPQ_swim(p,p->qp[k]);
    IndexMaxPQ_sink(p,p->qp[k]);
    return 0;
}

#endif
