#ifndef __CLIB_DATA_STRUCTURE_GRAPH_GRAPH_C__
#define __CLIB_DATA_STRUCTURE_GRAPH_GRAPH_C__

#include <malloc.h>
#include "../../types/Status.h"
typedef struct {
    int *base;
    int size,capacity;
}_BagForG_,*BagForG;

BagForG newBagForG(int n){
    BagForG b = (BagForG)malloc(sizeof(_BagForG_));
    b->base =(int *)malloc(sizeof(int)*n);
    b->size = 0;
    b->capacity = n;
    return b;
}
void freeBagForG(BagForG b) { free(b->base);free(b); }

Status BagForG_add(BagForG b,int e)
{
    if(b->size == b->capacity) {
        b->capacity *= 2;
        b->base = (int *)realloc(b->base,b->capacity*sizeof(int));
        // if(b->base == NULL) { exit(0); }
    }
    b->base[b->size++] = e;
    return OK;
}

#define BagForG_foreach(elem,in,bag) \
    for(in=0,elem=(bag)->base[in]; \
        in < (bag)->size; \
        in +=1,elem=(bag)->base[in])

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
