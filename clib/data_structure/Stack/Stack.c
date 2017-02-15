#ifndef __CLIB_DATA_STRUCTURE_STACK_STACK_C__
#define __CLIB_DATA_STRUCTURE_STACK_STACK_C__

// #define SElem int

#include "../../types/Status.h"
#include <malloc.h>
typedef struct {
    SElem *base,*top;
    int capacity;
}_Stack_,*Stack;

Stack newStack(int n)
{
    Stack s = (Stack)malloc(sizeof(_Stack_));
    s->base = (SElem *)malloc(sizeof(SElem)*n);
    s->top = s->base;
    s->capacity = n;
}
void freeStack(Stack s) { free(s->base); free(s); }

#define Stack_size(s) ((s)->top - (s)->base)
Status Stack_push(Stack s,SElem elem)
{   
    if(s->top - s->base >= s->capacity) { // 增大空间
        s->base = (SElem *)realloc(s->base,s->capacity*2*sizeof(SElem));
        s->top = s->base + s->capacity;
        s->capacity *= 2;
    }
    *(s->top++) = elem;
    return OK;
}
Status Stack_pop(Stack s,SElem *elem)
{
    if(s->top == s->base) { return ERROR; }
    *elem = *(--s->top);
    return OK;
}

#define Stack_foreach(elem,in,s) \
    for(in=(s)->top-(s)->base-1,elem = (s)->base[in]; \
        in >= 0;   \
        in -= 1,elem = (s)->base[in]) 
#endif
