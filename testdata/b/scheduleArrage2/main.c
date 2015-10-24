/* TestFilePath:testdata/b/scheduleArrage2  */
#include <stdio.h>

#define MAXLEN 10000
#include "clib/b/scheduleArrage2.h"

int s[MAXLEN];
int f[MAXLEN];
int main(int argc,char * argv[])
{
    int l,i;
    scanf("%d\n",&l);
    for(i=0;i<l;i++){
        scanf("%d %d\n",s+i,f+i);
    }
    printf("%d\n",scheduleArrage2(s,f,l));
    return 0;
}
