#include "insert.h"
#include "binaryinsert.h"
#include "shell.h"
#include "bubble.h"
#include "quick.h"
#include "select.h"
#include "heap.h"
#include "merge.h"

//2.将所以负数放到非负数之前
void ReSort(int A[], int n) {
    int low = 0, high = n - 1;
    int key = 0;
    while (low < high) {
        while (low < high && A[high] >= key)high--;
        while (low < high && A[low] <= key)low++;
        Swap(A[low], A[high]);
    }
}

//3.双向冒泡
void BiBubble(int A[], int n) {
    int low = 0, high = n - 1;
    bool flag = true;
    while (flag) {
        flag = false;
        for (int i = low; i < high; ++i) {
            if (A[i] > A[i + 1]) {
                Swap(A[i], A[i + 1]);
                flag = true;
            }
        }
        high--;
        for (int i = high; i > low; --i) {
            if (A[i] < A[i - 1]) {
                Swap(A[i], A[i - 1]);
                flag = true;
            }
        }
        low++;
    }
}

//4.对带头节点的单链表进行直接插入排序
void LinkListInsertSort(LinkList &L) {
    if (!L->next)return;
    LNode *q = L->next;
    LNode *p = q->next;
    q->next = NULL;

    while (p) {
        LNode *pre = L;
        q = L->next;
        while (q && q->Elem <= p->Elem) {
            pre = q;
            q = q->next;
        }
        LNode *t = p;
        p = p->next;
        t->next = q;
        pre->next = t;
    }
}

//T13.使用带头节点的单链表实现简单选择排序
void LinkListSelectSort(LinkList &L) {
    LNode *p = L->next, *q, *min;
    while (p) {
        q = p->next;
        min = p;
        while (q) {
            if (q->Elem < min->Elem)
                min = q;
            q = q->next;
        }
        if (min != p)
            min->Elem = p->Elem;
        p = p->next;
    }
}