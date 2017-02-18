#include <string.h>
void _Graph_BFSTraverse_(Graph g,int v,Bool *mark)
{
    int u,w,in;
    mark[v] = True; 
    // visit v
    QueueForG queue = newQueueForG(8);
    QueueForG_enqueue(queue,v);
    while(!QueueForG_isEmpty(queue)){
        QueueForG_dequeue(queue,&u);
        BagForG_foreach(w,in,g->adj[u]) {
            if(!mark[w]) { 
                mark[w] = True; 
                // visit W
                QueueForG_enqueue(queue,w);
            }
        } // for each adj node
    }
    freeQueueForG(queue);
    // return;
}
void Graph_BFSTraverse(Graph g)
{
    Bool *mark = (Bool *)malloc(sizeof(int)*(g->V));
    memset(mark,0,sizeof(Bool));
    for(int v=0;v < g->V;v++){ 
        if(!mark[v]){ // 每个连通分量
           _Graph_BFSTraverse_(g,v,mark);
        }
    }
    // return;
}
