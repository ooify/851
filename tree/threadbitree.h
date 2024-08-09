typedef struct ThreadNode {
    int data;
    struct ThreadNode *lchild, *rchild;
    int ltag, rtag;
} ThreadNode, *ThreadTree;

//ThreadNode *threadPre = NULL;

//void Visit(ThreadNode *T) {
//    if (T->lchild == NULL) {
//        T->lchild = threadPre;
//        T->ltag = 1;
//    }
//    if (threadPre != NULL && threadPre->rchild == NULL) {
//        threadPre->rchild = T;
//        threadPre->rtag = 1;
//    }
//    threadPre = T;
//}
//
//void InThread(ThreadNode *T) {
//    if (!T)
//        return;
//    InThread(T->lchild);
//    Visit(T);
//    InThread(T->rchild);
//}
//
//bool CreateInThread(ThreadTree &T) {
//    if (!T)return false;
//    InThread(T);
//    if (!pre->rchild)
//        pre->rchild = NULL;
//    return true;
//}

void InThread(ThreadTree T, ThreadNode *&pre) {
    if (!T)return;
    InThread(T->lchild, pre);
    if (T->lchild == NULL) {
        T->lchild = pre;
        T->ltag = 1;
    }
    if (pre != NULL && pre->rchild == NULL) {
        pre->rchild = T;
        pre->rtag = 1;
    }
    pre = T;
    InThread(T->rchild, pre);
}

bool CreateInThread(ThreadTree &T) {
    ThreadNode *pre = NULL;
    if (!T)return false;
    InThread(T, pre);
    pre->rchild = NULL;
    pre->ltag = 1;
    return true;
}

//找到以p为根的最先被中序遍历的节点
ThreadNode *FirstNode(ThreadNode *p) {
    while (p->ltag == 0)p = p->lchild;
    return p;
}

//在中序线索二叉树中找到p的后继结点
ThreadNode *NextNode(ThreadNode *p) {
    if (p->rtag == 0)return FirstNode(p->rchild);
    return p->rchild;
}

void InOrder(ThreadNode *T) {
    for (ThreadNode *p = FirstNode(T); p != NULL; p = NextNode(p)) {
        printf("%d\t", p->data);
    }
}



