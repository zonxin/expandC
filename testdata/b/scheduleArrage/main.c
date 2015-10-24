/* TestFilePath:testdata/b/scheduleArrage/  */
#include <stdio.h>
#include "clib/b/scheduleArrage.h"

#define MAXLEN 10000
Act str[MAXLEN];
int main(int argc,char * argv[])
{
    int l,i;
    scanf("%d\n",&l);
    for(i=0;i<l;i++){
        scanf("%d %d\n",&(str[i].x),&(str[i].y));
    }
    printf("%d\n",scheduleArrage(str,l));
    return 0;
}
