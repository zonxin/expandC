#include <string.h>
void _Graph_DFSTraverse_(Graph g,int v,Bool *mark)
{
    mark[v] = True; 
    // visit v
    int in,w;
    BagForG_foreach(w,in,g->adj[v]) {
        if(!mark[w]) {
            _Graph_DFSTraverse_(g,w,visit,mark);
        }
    }
    // return OK;
}
void Graph_DFSTraverse(Graph g)
{
   Bool *mark = (Bool *)malloc(sizeof(int)*(g->V));
   memset(mark,0,sizeof(Bool));
   for(int i=0;i< g->V;i++) { 
       if(!mark[i]) { _Graph_DFSTraverse_(g,i,visit,mark); }
    }
}
