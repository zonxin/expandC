/* TestFilePath:testdata/b/perfectString  */
#include <stdio.h>
#include "clib/b/perfectString.h"

#define MAXLEN 10000
char str[MAXLEN];
int main(int argc,char * argv[])
{
    scanf("%s\n",str);
    printf("%d\n",perfectString(str));
    return 0;
}
