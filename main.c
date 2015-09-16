#include <stdio.h>

#define MAXLEN 1000
char str[MAXLEN];
int main(int argc,char * argv[])
{
    int n,i;
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        scanf("%s\n",str);
        printf("%s\n",str);
    }
    return 0;
}
