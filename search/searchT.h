#include "sqsearchtable.h"
#include "binarysorttree.h"

typedef struct BSTNode {
    int count;
    int data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTTree;

//1.判断一颗二叉树是否为二叉排序树
int prior = INT_MIN;

bool IsBST(BiTree T) {
    if (!T)return true;
    bool l = IsBST(T->lchild);
    if (!l || prior > T->data)
        return false;
    prior = T->data;
    return IsBST(T->rchild);
}

//2.在二叉排序树中插入一个节点如果存在count+1，反之插入

void InsertBSTNode(BSTTree &T, int e) {
    BSTNode *pre = NULL;
    BSTNode *p = T;
    while (p) {
        if (p->data != e) {
            pre = p;
            if (e < p->data) {
                p = p->lchild;
            } else {
                p = p->rchild;
            }
        } else {
            p->count++;
        }
    }
    BSTNode *s = (BSTNode *) malloc(sizeof(BSTNode));
    s->data = e;
    s->count = 1;
    s->lchild = s->rchild = NULL;
    if (!pre)
        T = s;
    if (p->data > e)
        pre->lchild = s;
    else
        pre->rchild = s;
}