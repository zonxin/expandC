/* TestFilePath:testdata/data_structure/Heap/IndexMinPQ/  */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>

typedef char Ord;
#define gt(a,b) ((a)>(b)?1:0)
#include "clib/data_structure/Heap/IndexMinPQ.h"

#define MAXLEN 1000
char s[100][MAXLEN];
char next[100];
int main(int argc,char * argv[])
{
    int n,i;
    Ord v;
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        scanf("%s\n",s[i]);
        next[i] = 0;
    }
    IndexMinPQ pq = newIndexMinPQ(n);
    for(i=0;i<n;i++){
        v = s[i][next[i]];
        next[i]++;
        if(v){
            IndexMinPQ_insert(pq,i,v);
        }
    }
    while(pq->size>0){
        v = IndexMinPQ_min(pq);
        printf("%c",v);
        i = IndexMinPQ_delMin(pq);
        v = s[i][next[i]];
        if(v){
            next[i]++;
            IndexMinPQ_insert(pq,i,v);
        }
    }
    printf("\n");
    return 0;
}
