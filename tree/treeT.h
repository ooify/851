#include "linkbitree.h"
#include "sqbitree.h"
#include "threadbitree.h"

//层次遍历
#define MAX_SIZE 5
typedef struct {
    BiTNode *data[MAX_SIZE];
    int front, rear;
} SqTreeQueue;

void InitSqTreeQueue(SqTreeQueue &Q) {
    Q.rear = Q.front = 0;
}

bool SqTreeQueueEmpty(SqTreeQueue Q) {
    if (Q.front == Q.rear)
        return true;
    else
        return false;
}

bool EnTreeQueue(SqTreeQueue &Q, BiTNode *e) {
    if ((Q.rear + 1) % MAX_SIZE == Q.front)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAX_SIZE;
    return true;
}

bool DeTreeQueue(SqTreeQueue &Q, BiTNode *&e) {
    if (Q.front == Q.rear)
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    return true;
}

bool IsEmpty(SqTreeQueue Q)
{
    return  Q.front == Q.rear;
}
void LevelOrder(BiTree T) {
    SqTreeQueue Q;
    InitSqTreeQueue(Q);
    EnTreeQueue(Q, T);
    while (!SqTreeQueueEmpty(Q)) {
        BiTNode *p;
        DeTreeQueue(Q, p);
        printf("%d", p->data);
        if (p->lchild)
            EnTreeQueue(Q, p->lchild);
        if (p->rchild)
            EnTreeQueue(Q, p->rchild);
    }
}

//2.计算表达式求值
int calc(int a, char op, int b) {
    if (op == '+')
        return a + b;
    else if (op == '-')
        return a - b;
    else if (op == '*')
        return a * b;
    else if (op == '/') {
        if (b == 0) {
            printf("error");
            return -1;
        } else {
            return a / b;
        }
    }
    return -1;
}

//    printf("%d\t%d\t%d\t%d",'+','-','*','/');
int CalcExp(BiTree T) {
    if (!T)return 0;
    if (T->lchild && T->rchild) {
        int a = CalcExp(T->lchild);
        int b = CalcExp(T->rchild);
        return calc(a, T->data, b);
    } else {
        return T->data - '0';
    }
}

//3.求二叉树深度
int Depth(BiTNode *p) {
    if (!p)return 0;
    int l = Depth(p->lchild);
    int r = Depth(p->rchild);
    return l < r ? r + 1 : l + 1;
}

//4.寻找值为key的节点返回给p(初始为NULL)
void Search(BiTree T, BiTNode *&p, int key) {
    if (!T)return;
    if (T->data == key) {
        p = T;
    } else {
        Search(T, p->lchild, key);
        if (!p)
            Search(T, p->rchild, key);
    }
}

//5.求二叉树的叶子节点个数
int GetNum(BiTree T) {
    if (!T)return 0;
    if (!T->lchild && !T->rchild) {
        return 1;
    }
    return GetNum(T->lchild) + GetNum(T->rchild);
}

//6.已知两个节点指针head、tail(初始为NULL)分别用于指向单链表的首元节点和尾节点
//  利用这两个指针把叶子节点从左至右连成一个单链表
void link(BiTree T, BiTNode *&head, BiTNode *&tail) {
    if (!T)return;
    if (!T->lchild && !T->rchild) {

        if (!head) {
            head = tail = T;
        } else {
            tail->rchild = T;
            tail = T;
        }
    }
    link(T->lchild, head, tail);
    link(T->rchild, head, tail);
}

//7.给每个节点添加一个双亲节点，并赋值，打印出所以节点的路径
typedef struct BiParentTNode {
    int data;
    struct BiParentTNode *lchild, *rchild, *parent;
} BiParentTNode, *BiParentTree;

void AddParent(BiParentTree T, BiParentTNode *pre) {
    if (!T)return;
    T->parent = pre;
    pre = T;
    AddParent(T->lchild, pre);
    AddParent(T->rchild, pre);
}

void PrintPath(BiParentTNode *p) {
    while (p) {
        printf("%d\t", p->data);
        p = p->parent;
    }
}

void AllPath(BiParentTree T) {
    if (!T)return;
    PrintPath(T);
    AllPath(T->lchild);
    AllPath(T->rchild);
}

//8.

//9.输出值为x的层号
int deep = 1;

void GetDepth(BiTree T, int x) {
    if (!T)return;
    if (T->data == x)
        printf("%d", deep);
    deep++;
    GetDepth(T->lchild, x);
    GetDepth(T->rchild, x);
    deep--;
}

//10.输出根节点到每个叶子节点的路径
BiTNode *pathStack[MAX_SIZE];
int pathTop = -1;

void GetPath(BiTree T) {
    if (!T)return;
    pathStack[++pathTop] = T;
    if (!T->lchild && !T->rchild) {
        for (int i = 0; i <= pathTop; ++i) {
            printf("%d\t", pathStack[i]->data);
        }
    }
    GetPath(T->lchild);
    GetPath(T->rchild);
    pathTop--;
}

//11.（1）寻找线索二叉树子树t的中序的最后一个节点
//   （2）寻找节点t的中序前驱
ThreadNode *InLast(ThreadTree T) {
    ThreadNode *p = T;
    while (p && !p->rtag)
        p = p->rchild;
    return p;
}

ThreadNode *InPre(ThreadTree T) {
    ThreadNode *p = T->lchild;
    while (p && !p->rchild) {
        p = InLast(T);
    }
    return p;
}


//T8.复制一个二叉树

void CopyBiTree(BiTree T1, BiTree &T2) {
    if (!T1) {
        T2 = NULL;
    } else {
        T2 = (BiTNode *) malloc(sizeof(BiTNode));
        T2->data = T1->data;
        CopyBiTree(T1->lchild, T2->lchild);
        CopyBiTree(T1->rchild, T2->rchild);
    }
}

//T10.判断是否为完全二叉树
bool IsCompleteTree(BiTree T) {
    if (!T)return false;
    bool isLeaf = false;
    SqTreeQueue Q;
    InitSqTreeQueue(Q);
    EnTreeQueue(Q, T);
    while (!SqTreeQueueEmpty(Q)) {
        BiTNode *p;
        DeTreeQueue(Q, p);
        if (p->lchild) {
            if (isLeaf)return false;
            EnTreeQueue(Q, p->lchild);
        } else {
            isLeaf = true;
        }
        if (p->rchild) {
            if (isLeaf)return false;
            EnTreeQueue(Q, p->rchild);
        } else {
            isLeaf = true;
        }
    }
    return true;
}

//T11.双序遍历
void DoubleTraverse(BiTree T) {
    if (!T)return;
    printf("%d", T->data);
    DoubleTraverse(T->lchild);
    printf("%d", T->data);
    DoubleTraverse(T->rchild);
}

// 计算二叉树宽度（每层节点的最大值）
int WidthOfBiTree(BiTree T) {
    if (T == NULL)
        return 0;

    int maxWidth = 0;
    SqTreeQueue Q;
    EnTreeQueue(Q, T);  // 将根节点入队
    while (!IsEmpty(Q)) {
        int len = (Q.rear - Q.front+MAX_SIZE)%MAX_SIZE;
        if (maxWidth< len) {
            maxWidth = len;
        }
        for (int i = 0; i < len; i++) {
            BiTNode *t;
            DeTreeQueue(Q,t);  // 弹出当前节点
            if (t->lchild)
                EnTreeQueue(Q, t->lchild);  // 左子节点入队
            if (t->rchild)
                EnTreeQueue(Q, t->rchild);  // 右子节点入队
        }
    }
    return maxWidth;
}