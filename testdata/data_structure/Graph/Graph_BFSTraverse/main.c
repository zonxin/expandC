/* TestFilePath:testdata/data_structure/Graph/Graph_BFSTraverse/  */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>
#include "clib/types/x64.h"
#include "clib/data_structure/Graph/Graph_BFSTraverse.h"

int visit(int v){
    printf("%d ",v);
    return 1;
}
int main(int argc,char * argv[])
{
    int n,i,v,w;
    scanf("%d\n",&n);
    Graph g = newGraph(n);
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        scanf("%d %d\n",&v,&w);
        Graph_addEdge(g,v,w);
    }
    int in;
    Graph_BFSTraverse(g,visit);
    return 0;
}
