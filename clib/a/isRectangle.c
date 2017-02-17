/*
 * 给出平面上4条线段，判断这4条线段是否恰好围成一个面积大于0的矩形。
 */

#ifndef __CLIB_A_ISRECTANGLE_C__
#define __CLIB_A_ISRECTANGLE_C__

#include <string.h>
#include "../../clib/types/Point.h"
#include "../../clib/types/TwoInts/isEqualTwoInts.h"
typedef struct _segment {
    Point p1,p2;
}Segment,*pSegment;

typedef Point* Key;
typedef int Value;
#define equal(p1,p2) ((p1)->x==(p2)->x && (p1)->y==(p2)->y)
#include "../../clib/data_structure/SymbolTable/SymbolTable.h"

int getDistanceSquare(Point *p1,Point *p2)
{
    int dx = p1 -> x - p2 -> x,
        dy = p1 -> y - p2 -> y;
    return dx*dx + dy*dy;
}
int isRectangle(pSegment segs)
{
    int i,j,index1,index2,count=0;
    Point points[8];
    int adj[4][4],mark[4],ord[4];  // 图
    memset(adj,0,4*4*sizeof(int));
    memset(mark,0,4*sizeof(int));
    SymbolTable st = newSymbolTable(8);

    for(i=0;i<4;i++){
        if(!SymbolTable_get(st,&(segs[i].p1),&index1)){
            index1 = count++;
            points[index1].x = segs[i].p1.x;
            points[index1].y = segs[i].p1.y;
            SymbolTable_put(st,points+index1,index1);
        }
        if(!SymbolTable_get(st,&(segs[i].p2),&index2)){
            index2 = count++;
            points[index2].x = segs[i].p2.x;
            points[index2].y = segs[i].p2.y;
            SymbolTable_put(st,points+index2,index2);
        }
        if(count>4) { freeSymbolTable(st); return 0; }
        adj[index1][index2] = 1;
        adj[index2][index1] = 1;
    }
    freeSymbolTable(st);
    // 深度优先遍历
    int current=0;
    for(i=0;i<3;i++){
        ord[i] = current; mark[current] = 1;
        for(j=0;j<4 && (!adj[current][j] || mark[j]);j++){ }
        if(j>=4) { return 0; }
        current = j;
    }
    ord[i] = current; mark[current] = 1;
    if(!adj[current][0]) { return 0; }

    if(points[ord[0]].x +points[ord[2]].x == points[ord[1]].x + points[ord[3]].x &&
       points[ord[0]].y +points[ord[2]].y == points[ord[1]].y + points[ord[3]].y &&
        getDistanceSquare(&points[ord[0]],&points[ord[2]]) == getDistanceSquare(&points[ord[1]],&points[ord[3]]) 
        ) { return 1; }
    return 0;

    // 对角线等长且相互平分的四边形是矩形
    return 1;
}

#endif
