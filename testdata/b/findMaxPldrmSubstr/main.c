/* TestFilePath:testdata/b/findMaxPldrmSubstr/  */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>
#include "clib/b/findMaxPldrmSubstr.h"

#define MAXLEN 1000001
char str[MAXLEN];
int main(int argc,char * argv[])
{
    int n,i;
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        scanf("%s\n",str);
        printf("%d\n",findMaxPldrmSubstr(str));
    }
    return 0;
}
