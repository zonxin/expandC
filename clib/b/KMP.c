/*
 * KMP 算法
 * 参见: http://hihocoder.com/problemset/problem/1015
 */
#ifndef __CLIB_B_KMP_C__
#define __CLIB_B_KMP_C__

/* find next*/
void getNext(char *pattern,int next[])
{
    next[0] = -1;
    int k=-1,j=0;
    while(pattern[j]){
        while(k!=-1 && pattern[k] != pattern[j]) k = next[k];
        j++;k++;
        if(pattern[k]==pattern[j])
            next[j] = next [k];
        else
            next[j] = k;
    }
    while(k!=-1 && pattern[k] != pattern[j]) k = next[k];
    j++;k++;
    next[j] = k;
}
/* find PATTERN in SRC*/
int KMPsearch(char *src,char *pattern,int next[])
{
    int i=0,j=0;
    int nCount = 0;
    while(src[i]){
        if(j == -1 || src[i] == pattern[j]){
            i++;j++;
        }else{
            j = next[j];
        }
        if(j == -1) continue;
        if(!pattern[j]){ 
            // 找到一个匹配的 pattern 统计，并且开始寻找下一个
            nCount++;
            j = next[j];
        }
    }
    return nCount; 
}

#endif
