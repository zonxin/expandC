#ifndef __CLIB_DATA_STRUCTURE_GRAPH_GRAPH_BFSTRAVERSE_C__
#define __CLIB_DATA_STRUCTURE_GRAPH_GRAPH_BFSTRAVERSE_C__

#include "../../types/Boolean.h"
#include "../../types/Status.h"
#include "Graph.h"
#include <string.h>
typedef struct {
    int *base;
    int font,rear;
    int capacity;
}_QueueForG_,*QueueForG;

QueueForG newQueueForG(int n)
{
    QueueForG p = (QueueForG) malloc(sizeof(_QueueForG_));
    p->base = (int *) malloc(sizeof(int)*(n+1));
    p->font = 0; p->rear = 0;
    p->capacity = n+1;
    return p;
}
void freeQueueForG(QueueForG p) { free(p->base); free(p); }

Status QueueForG_enqueue(QueueForG p,int e)
{
    int nums;
    if((p->rear+1)%(p->capacity) == p->font) { // 队满 重新分配空间
        p->base = (int *)realloc(p->base,p->capacity*2*sizeof(int));
        if(p->font == 1) {
            p->rear = p->capacity;
        }else if( p->font > 1 ) {
            nums = p->capacity - p->font;
            memcpy(p->base+(p->capacity*2-nums),
                    p->base + p->font,
                    sizeof(int)*nums);
            p->font = p->capacity*2-nums;
        }
        p->capacity *= 2;
    }
    // 写入
    p->base[p->rear] = e;
    p->rear = (p->rear+1)%(p->capacity);
    return OK;
}
Status QueueForG_dequeue(QueueForG p,int *e)
{
    // 队空
    if(p->rear == p->font) { return ERROR;}
    *e = p->base[p->font];
    p->font = (p->font+1)%(p->capacity);
    return OK;
}

#define QueueForG_foreach(elem,index,q) \
    for(index=(q)->font,elem=(q)->base[index]; \
        index != (q)->rear; \
        index = (index+1)%((q)->capacity),elem=(q)->base[index]) 

#define QueueForG_isEmpty(q) ((q)->font == (q)->rear)
Status Graph_BFSTraverse(Graph g,Status(*visit)(int) )
{
    Bool *mark = (Bool *)malloc(sizeof(int)*(g->V));
    memset(mark,0,sizeof(Bool));
    QueueForG queue = newQueueForG(8);
    int v,w,u,in;
    for(v=0;v < g->V;v++){ if(!mark[v]){ // 每个连通分量
        // Visit v
        mark[v] = True; if(!visit(v)) { return ERROR; }
        QueueForG_enqueue(queue,v);
        while(!QueueForG_isEmpty(queue)){
            QueueForG_dequeue(queue,&u);
            BagForG_foreach(w,in,g->adj[u]) {
                if(!mark[w]) { 
                    mark[w] = True; if(!visit(w)) { return ERROR; }
                    QueueForG_enqueue(queue,w);
                }
            }
        }
    }}
    freeQueueForG(queue);
    return OK;
}

#endif
