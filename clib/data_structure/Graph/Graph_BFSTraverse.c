#ifndef __CLIB_DATA_STRUCTURE_GRAPH_GRAPH_BFSTRAVERSE_C__
#define __CLIB_DATA_STRUCTURE_GRAPH_GRAPH_BFSTRAVERSE_C__

#include "Graph.h"
#include "common/QueueForG.h"
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
