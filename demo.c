#include <stdio.h>
#include "clib/a/add.h"

int main()
{
    int a,b;
    while(scanf("%d %d",&a,&b)!=EOF){
        printf("%d\n",add(a,b));
    }
    return 0;
}
