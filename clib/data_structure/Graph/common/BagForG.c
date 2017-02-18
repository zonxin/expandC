#ifndef __CLIB_DATA_STRUCTURE_GRAPH_COMMON_BAGFORG_C__
#define __CLIB_DATA_STRUCTURE_GRAPH_COMMON_BAGFORG_C__

#include <malloc.h>
#include "../../../types/Status.h"
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

#endif
