/* TestFilePath:testdata/b/commonParent/  */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>
#include <string.h>

typedef char* Key;
typedef int Value;
#define compare strcmp
#include "clib/data_structure/SymbolTable/RedBlackTree.h"

#define MAXLEN 100010
#define NAMELEN 50
char nameList[MAXLEN][NAMELEN];
char father[NAMELEN],son[NAMELEN];
int tree[MAXLEN],mark[MAXLEN];
int main(int argc,char * argv[])
{
    int n,i,size,pIndex,sIndex;
    RedBlackTree st = newRedBlackTree();
    scanf("%d\n",&n);
    memset(nameList,0,MAXLEN*NAMELEN);
    memset(tree,-1,MAXLEN*sizeof(int));
    size = 0;
    for(i=0; i<n; i++){
        scanf("%s%s\n",father,son);
        if(!RBT_get(st,father,&pIndex)) {  
            pIndex = size++;
            strcpy(nameList[pIndex],father);
            RBT_put(st,nameList[pIndex],pIndex);
        }
        if(!RBT_get(st,son,&sIndex)) {  
            sIndex = size++;
            strcpy(nameList[sIndex],son);
            RBT_put(st,nameList[sIndex],sIndex);
        }
        tree[sIndex] = pIndex;
    }
    
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        scanf("%s%s\n",father,son);
        // 注意，如果输入没有出现但是相同的名字，则输出该名字
        if(strcmp(father,son)==0) { printf("%s\n",father); continue;}

        memset(mark,0,sizeof(int)*MAXLEN);
        if(!RBT_get(st,father,&pIndex)) {  printf("-1\n"); continue; }
        if(!RBT_get(st,son,&sIndex)) {  printf("-1\n"); continue; }
        for(;pIndex != -1;pIndex=tree[pIndex]){
            mark[pIndex] = 1;
        }
        for(;sIndex != -1;sIndex = tree[sIndex]){
            if(mark[sIndex]) { break; }
        }
        if(sIndex != -1){
            printf("%s\n",nameList[sIndex]);
        }else {
            printf("-1\n");
        }
    }

    return 0;
}
