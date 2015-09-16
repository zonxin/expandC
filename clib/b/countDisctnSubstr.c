/*
 * 小Z一直是网易的粉丝，从网易97年6月成立开始他就一直关注着它的发展，并且玩过几
 * 乎所有的网易游戏。同时他也是一名数学爱好者，经常沉迷于研究一些游戏数值的特点
 * 。他觉得这些数字的设计和网易本身或许有千丝万缕的关系。

 * 有一天，他在游戏中获得了一串数字，直觉告诉他这不是一串普通的数字串，或许可以
 * 破解一些关于网易的秘密。破解的第一步，他很想知道，在这串数字中，最多可以挑出
 * 多少个'9706'串。挑选的规则为：

 *（1）挑出的数字'9','7','0','6'在原串中可以不连续，但是数字的先后顺序不能改变
 *（2）使用过的数字不能被再次使用
 * 如'123901370997606'可以最多挑出2个'9706'，而'6079'则无法挑出任何一个'9706'。
 *
 * 输入
 * 第一行是整数T(T <= 100)，表示下面有T组数据。之后T行，每行为一组数据，每组数
 * 据为一个字符串。每个字符串的长度L <= 50000。每个字符串只会包含数字
 * ['0'...'9']。
 *
 * 输出
 * 输出T行，每行对应一个数据的输出结果，表示字符串最多能挑出多少个'9706'。
 *
 * 样例输入
 * 4
 * 6097
 * 97069706
 * 997776600069
 * 123901370997606
 *
 * 样例输出
 * 0
 * 2
 * 1
 * 2
 */

#ifndef __CLIB_B_COUNTDISCTNSUBSTR_C__
#define __CLIB_B_COUNTDISCTNSUBSTR_C__

#include <string.h>
#include <malloc.h>
// 要求 sub 中没有重复的字符
int countDisctnSubstr(char *s, char *sub)
{
    int sublength = strlen(sub);
    int i=0;
    int *statusCount = (int *) malloc(sublength*sizeof(int));
    // if (satusCount == NULL) { return -1; }
    memset(statusCount,0,sublength*sizeof(int));
    while( *s ){
        i = 0;
        while(sub[i]){
            if(sub[i] == *s){
                if(i==0) { statusCount[0]++;break; }
                else if(statusCount[i-1] > 0){
                    statusCount[i-1]--;
                    statusCount[i]++;
                    break;
                }
            }
            i++;
        }
        s++;
    }
    i = statusCount[sublength-1];
    free(statusCount);
    return i;
}

#endif
