#ifndef __CLIB_DATA_STRUCTURE_BAG_BAG_C__
#define __CLIB_DATA_STRUCTURE_BAG_BAG_C__

//#define BagElem int

#include <malloc.h>
#include "../../types/Status.h"
typedef struct {
    BagElem *base;
    int size,capacity;
}_Bag_,*Bag;

Bag newBag(int n){
    Bag b = (Bag)malloc(sizeof(_Bag_));
    b->base =(BagElem *)malloc(sizeof(BagElem)*n);
    b->size = 0;
    b->capacity = n;
    return b;
}
void freeBag(Bag b) { free(b->base);free(b); }

Status Bag_add(Bag b,BagElem e)
{
    if(b->size == b->capacity) {
        b->capacity *= 2;
        b->base = (BagElem *)realloc(b->base,b->capacity*sizeof(BagElem));
        // if(b->base == NULL) { exit(0); }
    }
    b->base[b->size++] = e;
    return OK;
}

#define Bag_foreach(elem,in,bag) \
    for(in=0,elem=(bag)->base[in]; \
        in < (bag)->size; \
        in +=1,elem=(bag)->base[in])


#endif
