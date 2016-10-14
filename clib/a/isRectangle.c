/*
 * 给出平面上4条线段，判断这4条线段是否恰好围成一个面积大于0的矩形。
 */

#ifndef __CLIB_A_ISRECTANGLE_C__
#define __CLIB_A_ISRECTANGLE_C__

#include "../../clib/types/Point.h"
#include "../../clib/types/TwoInts/isEqualTwoInts.h"
typedef struct _segment {
    Point p1,p2;
}Segment,*pSegment;
int getDistanceSquare(Point *p1,Point *p2)
{
    int dx = p1 -> x - p2 -> x,
        dy = p1 -> y - p2 -> y;
    return dx*dx + dy*dy;
}
int isRectangle(pSegment segs)
{
    int i,j,arr[] = {1,2,3,-1}; Point p[4];
    p[0].x = segs[0].p1.x; p[0].y = segs[0].p1.y;
    p[1].x = segs[0].p2.x; p[1].y = segs[0].p2.y;
    for(j=3;j>0;j--){
        for(i = 0;i<j ;i++){
            if(isEqualTwoInts(&p[4-j],&segs[arr[i]].p1)) { 
                p[5-j].x = segs[arr[i]].p2.x; 
                p[5-j].y = segs[arr[i]].p2.y; 
                break;
            }
            if(isEqualTwoInts(&p[4-j],&segs[arr[i]].p2)) { 
                p[5-j].x = segs[arr[i]].p1.x; 
                p[5-j].y = segs[arr[i]].p1.y; 
                break;
            }
        }
        if(i == j) { return 0; }
        for(;i<j;i++) { arr[i] = arr[i+1]; }
    }
    // 对角线等长且相互平分的四边形是矩形
    if( p[0].x + p[2].x == p[1].x + p[3].x &&
        p[0].y + p[2].y == p[1].y + p[3].y &&
        getDistanceSquare(&p[0],&p[2]) == getDistanceSquare(&p[1],&p[3])
    ){ return 1; }
    return 0;
}

#endif
