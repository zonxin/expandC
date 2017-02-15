#ifndef __CLIB_DATA_STRUCTURE_HEAP_INDEXMINPQ_C__
#define __CLIB_DATA_STRUCTURE_HEAP_INDEXMINPQ_C__

#include <malloc.h>
#include <string.h>
// typedef char Ord;
// #define gt(a,b) (a)>(b)?1:0
typedef struct _IndexMinPQ_ {
    int *pq,*qp,size;
    Ord *keys;
    // int capacity;
} *IndexMinPQ;
IndexMinPQ newIndexMinPQ(int n)
{
    IndexMinPQ p = (IndexMinPQ)malloc(sizeof(struct _IndexMinPQ_));
    p->pq = (int *)malloc(sizeof(int)*(n+1));
    p->qp = (int *)malloc(sizeof(int)*n);
    p->keys = (Ord *)malloc(sizeof(Ord)*n);
    p->size = 0;
    memset(p->qp,-1,sizeof(int)*n);
    // p-> capacity = n;
    return p;
}
void freeIndexMinPQ(IndexMinPQ p)
{
    free(p->pq);free(p->qp);free(p->keys);
    free(p);
}

void _IndexMinPQ_exch_(IndexMinPQ p,int m,int n)
{
    int t = p->pq[m];
    p->pq[m] = p->pq[n];
    p->pq[n] = t;
    
    p->qp[p->pq[m]] = m;
    p->qp[p->pq[n]] = n;
}

#define _gt_(p,i,j)  gt((p)->keys[(p)->pq[(i)]],(p)->keys[(p)->pq[(j)]])
int IndexMinPQ_swim(IndexMinPQ p,int k)
{
    while(k>1 && _gt_(p,k/2,k)){
        _IndexMinPQ_exch_(p,k/2,k);
        k/=2;
    }
    return 0;
}
int IndexMinPQ_sink(IndexMinPQ p,int k)
{
    int N = p->size,j;
    while(2*k <= N){
        j = 2*k;
        if(j<N && _gt_(p,j,j+1)) { j++; }
        if(!_gt_(p,k,j)) { break; }
        _IndexMinPQ_exch_(p,k,j);
        k = j;
    }
    return 0;
}
#undef _gt_

int IndexMinPQ_insert(IndexMinPQ p,int k,Ord v){
    (p->size)++;
    p->qp[k] = p->size;
    p->pq[p->size] = k;
    p->keys[k] = v;
    IndexMinPQ_swim(p,p->size);
    return 0;
}
int IndexMinPQ_min(IndexMinPQ p,Ord *m){
    *m = p->keys[p->pq[1]];
    return 1;
}
int IndexMinPQ_delMin(IndexMinPQ p){
    int index = p->pq[1],n=p->size;
    // 把最后一个放到堆顶
    p->pq[1] = p->pq[n];
    p->qp[p->pq[1]] = 1;
    p->qp[index] = -1;
    (p->size)--;
    IndexMinPQ_sink(p,1);
    return index;
}

#define IndexMinPQ_contains(p,k) ((p)->qp[(k)] != -1)
#define IndexMinPQ_minIndex(p) ((p)->pq[1])

int IndexMinPQ_change(IndexMinPQ p,int k,Ord v)
{
    // ASSERT(IndexMinPQ_contains(p,k));
    p->keys[k] = v;
    IndexMinPQ_swim(p,p->qp[k]);
    IndexMinPQ_sink(p,p->qp[k]);
    return 0;
}

#endif
