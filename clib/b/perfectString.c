/* 完美字符串
 * 约翰认为字符串的完美度等于它里面所有字母的完美度之和。每个字母的完美度可以由
 * 你来分配，不同字母的完美度不同，分别对应一个1-26之间的整数。约翰不在乎字母大
 * 小写。（也就是说字母F和f）的完美度相同。给定一个字符串，输出它的最大可能的完
 * 美度。例如：dad，你可以将26分配给d，25分配给a，这样整个字符串完美度为77。
 */
#ifndef __CLIB_B_PERFECTSTRING_C__
#define __CLIB_B_PERFECTSTRING_C__

#include <string.h>
#include <stdlib.h>
#include "../types/int/cmp_int.h"

int perfectString(char *s)
{
    int count[26],i,j,t;
    char c;
    int sum =0;
    memset(count,0,26*sizeof(int));
    i=0;
    while( c=s[i] ){
        if( c >= 'a' ) c-= 32;
        count[c-'A']++;
        i++;
    }
    qsort(count,26,sizeof(int),cmp_int);
    for(i=0;i<26;i++)
    {
        sum += count[i]*(i+1);
    }
    return sum;
}

#endif
