/* TestFilePath:testdata/data_structure/Bag/  */
/* 测试文件所在路径，必须放在第一行，相对于Makefile所在路径 */
/* 包含的库函数，会自动展开引号中的文件，相对于Grunfile所在路径 */
#include <stdio.h>

#define BagElem int
#include "clib/data_structure/Bag/Bag.h"

int main(int argc,char * argv[])
{
    int n,i;
    Bag bag = newBag(1);
    BagElem elem;
    scanf("%d\n",&n);
    for(i=0; i<n; i++){
        scanf("%d\n",&elem);
        Bag_add(bag,elem);
    }
    int in,sum = 0;
    Bag_foreach(elem,in,bag){
        sum += elem;
    }
    printf("%d\n",sum);
    freeBag(bag);
    return 0;
}
