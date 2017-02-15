/* TestFilePath:testdata/data_structure/Queue */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>

#define QElem int
#include "clib/data_structure/Queue/Queue.h"

int main(int argc,char * argv[])
{
    int n,i;
    Queue q = newQueue(4);
    QElem elem,sum=0;
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        scanf("%d\n",&elem);
        Queue_enqueue(q,elem);
        if(i<2) { Queue_dequeue(q,&elem); }
    }
    int in;
    Queue_foreach(elem,in,q){
        sum += elem;
    }
    printf("%d\n",sum);
    return 0;
}
