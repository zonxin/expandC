/* TestFilePath:testdata/a/add/  */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>
#include "clib/types/x64.h"

#define MAXLEN 10000
int array[MAXLEN];
int main(int argc,char * argv[])
{
    int n,i;
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        scanf("%d\n",array+i);
    }
    printf("%d\n",{{@FN}}(array,n));
    return 0;
}
