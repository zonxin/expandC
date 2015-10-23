/* TestFilePath:testdata/a/same/  */
#include <stdio.h>
#include "clib/types/x64.h"

#define MAXLEN 1000
char str[MAXLEN];
int main(int argc,char * argv[])
{
    int l;
    scanf("%d\n",&l);
    for(;l>0;l--){
        scanf("%s\n",str);
        printf("%s\n",str);
    }
    return 0;
}
