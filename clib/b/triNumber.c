/* 数字三角形
 * 一个迷宫有 n 层，第i层有i个房间，只能往下走，第j个房间通往下层的第j和第j+1个
 * 房间，每个房间有 value[i][j] 张奖券，求可以获得的最多奖券数。
 * 详见：http://hihocoder.com/problemset/problem/1037
 * */
#ifndef __CLIB_B_TRINUMBER_C__
#define __CLIB_B_TRINUMBER_C__

#include <malloc.h>
#include "../a/Math_max.h"
#define MAXLEVEL 500
int triNumber(int value[][MAXLEVEL+1],int level)
{
    if(level <= 0) return 0;
    if(level == 1) return value[0][0];

    int *pre = (int*)malloc((MAXLEVEL+1)*sizeof(int));
    int *cur = (int*)malloc((MAXLEVEL+1)*sizeof(int));
    int *tmp,i,j;

    pre[0] = value[0][0];
    for(i=1;i<level;i++){
        cur[0] = pre[0]+value[i][0];
        for(j=1;j<i;j++){
            cur[j] = value[i][j] +(max(pre[j-1],pre[j]));
        }
        cur[j] = value[i][j] + pre[j-1];
        tmp = cur ; cur = pre ; pre = tmp ;
    }

    i = 0;
    for(j = 0; j < level; j++){
        if(pre[j]>i) i =pre[j];
    }
    free(pre);
    free(cur);
    return i;
}

#endif
