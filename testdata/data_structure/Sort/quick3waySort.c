/* TestFilePath:testdata/data_structure/Sort  */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>
#include <string.h>
#include "clib/types/Boolean.h"

typedef char Ord;
#define compare(a,b) ((a)-(b))
#include "clib/data_structure/Sort/quick3waySort.h"

#define MAXLEN 10000
char array[MAXLEN];
int main(int argc,char * argv[])
{
    int n;
    scanf("%s\n",array);
    n = strlen(array);
    quick3waySort(array,n);
    printf("%s\n",array);
    return 0;
}
