/* TestFilePath:testdata/a/heapTest/  */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>

#define Ord int
#define lt(a,b) ((a)-(b)<0?1:0)
#include "clib/data_structure/Heap/MaxPQ.h"

#define MAXLEN 100000
int main(int argc,char * argv[])
{
    int n,i;
    char c[3];
    Ord elem;
    MaxPQ pq= newMaxPQ(MAXLEN);
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        scanf("%s",c);
        if(c[0]=='A') {
            scanf("%d",&elem);
            MaxPQ_insert(pq,elem);
        }else{
            MaxPQ_delMax(pq,&elem);
            printf("%d\n",elem);
        }
    }
    return 0;
}
