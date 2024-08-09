typedef struct BiTNode {
    int data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

void PreOrder(BiTree T) {
    if (T == NULL)
        return;
    printf("%d\t", T->data);
    PreOrder(T->lchild);
    PreOrder(T->rchild);
}

void InOrder(BiTree T) {
    if (T == NULL)
        return;
    InOrder(T->lchild);
    printf("%d\t", T->data);
    InOrder(T->rchild);
}

void PostOrder(BiTree T) {
    if (T == NULL)
        return;
    PostOrder(T->lchild);
    PostOrder(T->rchild);
    printf("%d\t", T->data);
}

BiTNode *pp;
BiTNode *pre = NULL;
BiTNode *final = NULL;

void GetInPre(BiTNode *q) {
    if (pp == q) {
        final = pre;
    } else {
        pre = pp;
    }
}