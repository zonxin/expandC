#ifndef __CLIB_DATA_STRUCTURE_GRAPH_GRAPH_DFSTRAVERSE_C__
#define __CLIB_DATA_STRUCTURE_GRAPH_GRAPH_DFSTRAVERSE_C__

#include "Graph.h"
#include "../../types/Boolean.h"
#include <string.h>
Status _Graph_DFSTraverse_(Graph g,int v,Status(*visit)(int),Bool *mark)
{
    mark[v] = True; if(!visit(v)) {return ERROR;};
    int in,w;
    BagForG_foreach(w,in,g->adj[v]) {
        if(!mark[w]) {
            if(!_Graph_DFSTraverse_(g,w,visit,mark)) { return ERROR; };
        }
    }
    return OK;
}
Status Graph_DFSTraverse(Graph g,Status(*visit)(int))
{
   Bool *mark = (Bool *)malloc(sizeof(int)*(g->V));
   memset(mark,0,sizeof(Bool));
   for(int i=0;i< g->V;i++)
   {
       if(!mark[i]) {
           if(!_Graph_DFSTraverse_(g,i,visit,mark)){
               return ERROR;
           };
       }
   }
   return OK;
}

#endif
