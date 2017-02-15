/* TestFilePath:testdata/a/PostOrdFromPreInOrd/  */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>
#include <string.h>
#include "clib/a/PostOrdFromPreInOrd.h"

#define MAXLEN 1000
int main(int argc,char * argv[])
{
    int len;
    char preOrd[MAXLEN],inOrd[MAXLEN];
    memset(preOrd,0,MAXLEN*sizeof(char));
    memset(inOrd,0,MAXLEN*sizeof(char));
    scanf("%s%s",preOrd,inOrd);
    len = strlen(preOrd);
    PostOrdFromPreInOrd(preOrd,inOrd,len);
    return 0;
}
