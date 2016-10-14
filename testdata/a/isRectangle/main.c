/* TestFilePath:testdata/a/isRectangle/  */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>
#include "clib/a/isRectangle.h"

Segment segs[4];
int main(int argc,char * argv[])
{
    int n,i,j;
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        for(j=0;j<4;j++){
            scanf("%d %d %d %d\n",
                    &(segs[j].p1.x), &(segs[j].p1.y),
                    &(segs[j].p2.x), &(segs[j].p2.y));
        }
        if(isRectangle(segs)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }
    return 0;
}
