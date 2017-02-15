#ifndef __CLIB_A_POSTORDFROMPREINORD_C__
#define __CLIB_A_POSTORDFROMPREINORD_C__

typedef char TElem;
#include "../data_structure/Tree/BiTree.h"
#include "../types/Status.h"

#include <stdlib.h>
int recoverTree(BiTree tree,char *pre,int preS,char *in,int inS,int len)
{
    int i,len1,len2;
    if(len <=0) { return OK; }
    char rootValue = pre[preS];
    *tree = newBiTNode(rootValue);

    i=inS;
    while(in[i] != rootValue) { 
        i++; 
        if(i-inS>len){ exit(0); }
    }

    len1 = i - inS; len2 = len - len1 - 1;
    recoverTree(&(*tree)->left,pre,preS+1,in,inS,len1);
    recoverTree(&(*tree)->right,pre,preS+1+len1,in,i+1,len2);
    return 0;
}
Status output(TElem e)
{
    printf("%c",e);
    return OK;
}
int PostOrdFromPreInOrd(char *preOrd,char *inOrd,int len)
{
    BiTree tree = newBiTree();
    recoverTree(tree,preOrd,0,inOrd,0,len);
    BiTree_PostTraverse(tree,output);
    printf("\n");
    freeBiTree(tree);
    return 0;
}

#endif
