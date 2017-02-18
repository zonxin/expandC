#ifndef __CLIB_DATA_STRUCTURE_GRAPH_GRAPH_C__
#define __CLIB_DATA_STRUCTURE_GRAPH_GRAPH_C__

#include "common/BagForG.h"

typedef struct {
    int V; // 顶点数
    int E; // 边数
    BagForG *adj; // 临接表
}_Graph_,*Graph;

Graph newGraph(int n)
{
    int i;
    Graph g = (Graph)malloc(sizeof(_Graph_));
    g->V = n; g->E = 0;
    g->adj = (BagForG *)malloc(sizeof(BagForG)*n);
    for(i=0;i<n;i++){
        g->adj[i] = newBagForG(8);
    }
    return g;
}
void freeGraph(Graph g)
{
    for(int i=0;i< g->V;i++){
        freeBagForG(g->adj[i]);
    }
    free(g);
}

Status Graph_addEdge(Graph g,int v,int w)
{
    BagForG_add(g->adj[v],w);
    BagForG_add(g->adj[w],v);
    g->E++;
    return OK;
}

#endif
