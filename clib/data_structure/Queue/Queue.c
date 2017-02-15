#ifndef __CLIB_DATA_STRUCTURE_QUEUE_QUEUE_C__
#define __CLIB_DATA_STRUCTURE_QUEUE_QUEUE_C__

// 队列的顺序表示和实现

//#define QElem int

#include "../../types/Status.h"
#include <malloc.h>
#include <string.h>
typedef struct {
    QElem *base;
    int font,rear;
    int capacity;
}_Queue_,*Queue;

Queue newQueue(int n)
{
    Queue p = (Queue) malloc(sizeof(_Queue_));
    p->base = (QElem *) malloc(sizeof(QElem)*(n+1));
    p->font = 0; p->rear = 0;
    p->capacity = n+1;
    return p;
}
void freeQueue(Queue p) { free(p->base); free(p); }
#define Queue_size(p) (((p)->rear - (p)->front + (p)->capacity) % ((p)->capacity))

Status Queue_enqueue(Queue p,QElem e)
{
    int nums;
    if((p->rear+1)%(p->capacity) == p->font) { // 队满 重新分配空间
/*
 *  M = capacity
 *  1. 不需要处理     2. 需要重置rear       3.需要将[font...M-1]拷贝到数组最后
 *        ┌───────┐           ┌───────┐           ┌───────┐
 *        │  2M-1 │           │  2M-1 │           │  2M-1 │
 *        ├───────┤           ├───────┤           ├───────┤
 *        │  ...  │           │  ...  │           │  ...  │
 *        ├───────┤           ├───────┤           ├───────┤
 *        │   M   │           │   M   │           │   M   │
 * ───────├───────┤───────────├───────┤───────────├───────┤───────────────原始数组
 * rear-->│  M-1  │           │  M-1  │           │  M-1  │
 *        ├───────┤           ├───────┤           ├───────┤
 *        │  ...  │           │  ...  │           │  ...  │
 *        ├───────┤           ├───────┤           ├───────┤
 *        │   2   │           │   2   │    font-->│   2   │
 *        ├───────┤           ├───────┤           ├───────┤
 *        │   1   │    font-->│   1   │    rear-->│   1   │
 *        ├───────┤           ├───────┤           ├───────┤
 * font-->│   0   │    rear-->│   0   │           │   0   │
 *        └───────┘           └───────┘           └───────┘
 * */
        p->base = (QElem *)realloc(p->base,p->capacity*2*sizeof(QElem));
        if(p->font == 1) {
            p->rear = p->capacity;
        }else if( p->font > 1 ) {
            nums = p->capacity - p->font;
            memcpy(p->base+(p->capacity*2-nums),
                    p->base + p->font,
                    sizeof(QElem)*nums);
            p->font = p->capacity*2-nums;
        }
        p->capacity *= 2;
    }
    // 写入
    p->base[p->rear] = e;
    p->rear = (p->rear+1)%(p->capacity);
    return OK;
}
Status Queue_dequeue(Queue p,QElem *e)
{
    // 队空
    if(p->rear == p->font) { return ERROR;}
    *e = p->base[p->font];
    p->font = (p->font+1)%(p->capacity);
    return OK;
}

#define Queue_foreach(elem,index,q) \
    for(index=(q)->font,elem=(q)->base[index]; \
        index != (q)->rear; \
        index = (index+1)%((q)->capacity),elem=(q)->base[index]) 

#endif
