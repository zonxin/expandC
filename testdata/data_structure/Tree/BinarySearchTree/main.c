/* TestFilePath:testdata/data_structure/Tree/BinarySearchTree/  */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>

#define Key  char
#define Value int
#define compare(a,b) ((a)-(b))
#include "clib/data_structure/Tree/BinarySearchTree.h"

#define MAXLEN 10000
void echoTree(BinarySearchTree head){
    if(*head == NULL) { return; }
    echoTree(&(*head)->left);
    printf("%c %d\n",(*head)->key,(*head)->val);
    echoTree(&(*head)->right);
}
int main(int argc,char * argv[])
{
    int n,i;
    Key key;
    Value val;
    BinarySearchTree bitree = newBinarySearchTree();
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        scanf("%c %d\n",&key,&val);
        BST_put(bitree,key,val);
    }
    echoTree(bitree);
    freeBinarySearchTree(bitree);
    return 0;
}
