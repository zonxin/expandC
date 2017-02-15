#ifndef __CLIB_DATA_STRUCTURE_TREE_BITREE_C__
#define __CLIB_DATA_STRUCTURE_TREE_BITREE_C__

//#define TElem int

#include <malloc.h>
#include "../../types/Status.h"
typedef struct _BiTNode_{
    TElem data;
    struct _BiTNode_ *left,*right;
}*BiTNode,**BiTree;

BiTNode newBiTNode(TElem data)
{
    BiTNode node = (BiTNode)malloc(sizeof(struct _BiTNode_));
    node -> data = data;
    node -> left = NULL;
    node ->right = NULL;
    return node;
}
BiTree newBiTree()
{
    BiTree t = (BiTree)malloc(sizeof(struct _BiTNode_ *));
    *t = NULL;
    return t;
}
void _freeSubBiTree_(BiTree t)
{
    if(*t == NULL) { return;}
    _freeSubBiTree_(&(*t)->left);
    _freeSubBiTree_(&(*t)->right);
    free(*t);
}
void freeBiTree(BiTree t)
{
    _freeSubBiTree_(t);
    free(t);
}

Status BiTree_PreTraverse(BiTree tree, Status (*visit)(TElem e))
{
    if(*tree) {
        return visit((*tree)->data) 
            && BiTree_PreTraverse(&(*tree)->left,visit) 
            && BiTree_PreTraverse(&(*tree)->right,visit);
    } 
    return OK;
}
Status BiTree_InTraverse(BiTree tree, Status (*visit)(TElem e))
{
    if(*tree) {
        return BiTree_InTraverse(&(*tree)->left,visit) 
            && visit((*tree)->data) 
            && BiTree_InTraverse(&(*tree)->right,visit);
    } 
    return OK;
}
Status BiTree_PostTraverse(BiTree tree, Status (*visit)(TElem e))
{
    if(*tree) {
        return BiTree_PostTraverse(&(*tree)->left,visit) 
            && BiTree_PostTraverse(&(*tree)->right,visit)
            && visit((*tree)->data);
    } 
    return OK;
}

#endif
