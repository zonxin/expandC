/* TestFilePath:testdata/b/taskArrage  */
#include <stdio.h>
#include "clib/types/x64.h"
#include "clib/b/taskArrage.h"

#define MAXLEN 100000
Task t[MAXLEN];
int main(int argc,char * argv[])
{
    int l,i;
    scanf("%d\n",&l);
    for(i=0;i<l;i++){
        scanf("%d %d\n",&(t[i].x),&(t[i].y));
    }
    printf("%d\n",taskArrage(t,l));
    return 0;
}
