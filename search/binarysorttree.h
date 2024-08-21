BiTNode *BSTSearch(BiTree T, int key) {
    if (!T)
        return NULL;
    if (T->data == key) {
        return T;
    } else if (T->data < key) {
        return BSTSearch(T->lchild, key);
    } else {
        return BSTSearch(T->rchild, key);
    }
}

bool BSTInsert(BiTree &T, int key) {
    if (!T) {
        BiTNode *p = (BiTNode *) malloc(sizeof(BiTNode));
        p->data = key;
        p->lchild = p->rchild = NULL;
        return true;
    } else if (T->data == key) {
        return false;
    } else if (T->data > key) {
        return BSTInsert(T->lchild, key);
    } else {
        return BSTInsert(T->rchild, key);
    }
}