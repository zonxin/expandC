#ifndef __CLIB_DATA_STRUCTURE_TREE_REDBLACKTREE_C__
#define __CLIB_DATA_STRUCTURE_TREE_REDBLACKTREE_C__

// class Ord Key
// #define Key  char
// #define Value int
// #define compare(a,b) ((a)-(b))

#include <malloc.h>
typedef enum { BLACK=0,RED=1 } _RBcolor_;
typedef struct _RB_NODE_{
    Key key;
    Value val;
    _RBcolor_ color;
    struct _RB_NODE_ *left,*right;
} *_RBnode_,**RedBlackTree;

#define _RBT_isRed_(node) (((node)==NULL)?0:(node)->color)

_RBnode_ _newRBnode_(Key key,Value val,_RBcolor_ color)
{
    _RBnode_ p = (_RBnode_)malloc(sizeof(struct _RB_NODE_));
    p->key = key;
    p->val = val;
    p->color = color;
    return p;
}
RedBlackTree newRedBlackTree()
{
    RedBlackTree head = (RedBlackTree)malloc(sizeof(_RBnode_));
    *head = NULL;
    return head;
}
void _freeRedBlackTree_(RedBlackTree head)
{
    if((*head)==NULL) { return;}
    _freeRedBlackTree_(&(*head)->left);
    _freeRedBlackTree_(&(*head)->right);
}
void freeRedBlackTree(RedBlackTree head)
{
   _freeRedBlackTree_(head);
  free(head);
}

void _RBT_rotateLeft_(RedBlackTree head)
{
    // ASSERT((*head)!=NULL)
    _RBnode_ x = (*head)->right,h = (*head);
    h->right = x->left;
    x->left = h;
    x->color = h->color;
    h->color = RED;
    (*head) = x;
}
void _RBT_rotateRight_(RedBlackTree head)
{
    // ASSERT((*head)!=NULL)
    _RBnode_ x = (*head)->left,h = (*head);
    h->left = x-> right;
    x->right = h;
    x->color = h->color;
    h->color = RED;
    (*head) = x;
}
void _RBT_flipColor_(RedBlackTree head)
{
    _RBnode_ h = *head;
    h->color = RED;
    h->left->color = BLACK;
    h->right->color = BLACK;
}

int _RBT_put_(RedBlackTree head,Key key,Value val){
    int ret;
    if((*head)==NULL) {
        (*head) = _newRBnode_(key,val,RED);
        return 1;
    }
    int cmp = compare(key,(*head)->key);
    if     (cmp < 0) { ret = _RBT_put_(&(*head)->left,key,val); }
    else if(cmp > 0) { ret =  _RBT_put_(&(*head)->right,key,val); } 
    else  { (*head)->val = val; return 0; }
    if(_RBT_isRed_((*head)->right) && !_RBT_isRed_((*head)->left)) 
        { _RBT_rotateLeft_(head); }
    if(_RBT_isRed_((*head)->left) && _RBT_isRed_((*head)->left->left)) 
        { _RBT_rotateRight_(head); }
    if(_RBT_isRed_((*head)->left) && _RBT_isRed_((*head)->right)) 
        { _RBT_flipColor_(head); }
    return ret;
}
int RBT_put(RedBlackTree head,Key key,Value val)
{
    int ret = _RBT_put_(head,key,val);
    (*head)->color = BLACK;
    return ret;
}
// 获取一个键值,返回结果在pv中,若不存在返回 0
int RBT_get(RedBlackTree head,Key key,Value *pv)
{
    if(*head==NULL) { return 0; } 
    int cmp = compare(key,(*head)->key); 
    if     (cmp < 0) {return RBT_get(&(*head)->left,key,pv);}
    else if(cmp > 0) { return RBT_get(&(*head)->right,key,pv); }
    if(cmp == 0) { *pv = (*head)->val; return 1; }
}

#undef _RBT_isRed_


#endif
