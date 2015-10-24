/* TestFilePath:testdata/b/canoeNumber/  */
#include <stdio.h>
#include "clib/types/x64.h"
#include "clib/b/canoeNumber.h"

#define MAXLEN 10000
int str[MAXLEN];
int main(int argc,char * argv[])
{
    int l,m,i;
    scanf("%d %d\n",&l,&m);
    for(i=0;i<l;i++){
        scanf("%d\n",str+i);
    }
    printf("%d\n",canoeNumber(str,l,m));
    return 0;
}
