
#include "linklist.h"
#include "sqlist.h"

//1.
void LinkListMerge(LinkList L1, LinkList L2, LinkList &L3) {
    LNode *p = L1->next, *q = L2->next, *r = L3;
    while (p && q) {
        if (p->Elem < q->Elem) {
            r->next = p;
            r = p;
            p = p->next;
        } else {
            r->next = q;
            r = q;
            q = q->next;
        }
    }
    while (q) {
        r->next = q;
        r = q;
        q = q->next;
    }
    while (p) {
        r->next = p;
        r = q;
        p = p->next;
    }
    r->next = NULL;
}

//2.
void Swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void Reverse(int A[], int low, int high) {
    while (low < high) {
        Swap(A[low++], A[high--]);
    }
}

void Move(int A[], int i, int n) {
    Reverse(A, 0, i - 1);
    Reverse(A, i, n - 1);
    Reverse(A, 0, n - 1);

}

//3.前m个有序，后n个有序，实现0~m+n有序
void InsertElem(int A[], int m, int n) {
    for (int i = m; i < m + n; ++i) {
        int j, key = A[i];
        for (j = i - 1; j >= 0 && A[j] > key; j--)
            A[j + 1] = A[j];
        A[j + 1] = key;
    }
}

//4.两个带头节点有序链表的差集L1-L2
void Difference(LinkList L1, LinkList L2) {
    LNode *p = L1->next, *q = L2->next;
    LNode *prior = L1;
    while (p && q) {
        if (p->Elem < q->Elem) {
            prior = p;
            p = p->next;
        } else if (p->Elem > q->Elem) {
            q = q->next;
        } else {
            prior->next = p->next;
            LNode *temp = p;
            p = p->next;
            free(temp);
        }
    }
}

//5.删除顺序表指定范围的全部元素
void DeleteElem(SqList &L, int i, int j) {
    int num = j - i + 1;
    for (int k = 0; k < L.length - num; ++k) {
        L.data[i + k] = L.data[j + k + 1];
    }
    L.length -= num;
}

//6.顺序表，比表头元素大的在后面、小的在前面
void Partition(int A[], int n) {
    int low = 0, high = n - 1;
    int key = A[low];
    while (low < high) {
        while (low < high && A[high] >= key)
            high--;
        Swap(A[high], A[low]);
        while (low < high && A[low] <= key)
            low++;
        Swap(A[high], A[low]);
    }
}

//7.带头节点的L的元素递增，去除重复元素
void DelSame(LinkList &L) {
    LNode *p = L, *q = L->next;
    while (q) {
        if (q->Elem == p->Elem) {
            p->next = q->next;
            LNode *temp = q;
            q = p->next;
            free(temp);
        } else {
            q = q->next;
            p = p->next;
        }
    }
}

//8.将带头节点的单链表L，逆置，利用现有节点
void Reverse(LinkList &L) {
    LNode *p = L->next;
    L->next = NULL;
    while (p) {
        LNode *temp = p;
        p = p->next;
        temp->next = L->next;
        L->next = temp;
    }
}

//9.L1,L2都是整数元素，L1留下奇数元素，L2为偶数元素，保持相对顺序
void Split(LinkList &L1, LinkList &L2) {
    LNode *p = L1, *q = L2;
    while (p->next) {
        if (p->next->Elem % 2 == 0) {
            q->next = p->next;
            q = q->next;
            p->next = q->next;
            q->next = NULL;
        } else
            p = p->next;
    }
}

//10.打印不带头节点单链表的数据（递归）
void RecursionPrintLinkList(LNode *p) {
    if (!p)return;
    RecursionPrintLinkList(p->next);
    printf("%d\t", p->Elem);
}

//11.两个递增或递减的有序带头结点的单链表，判断是否相等
bool Equal(LinkList L1, LinkList L2) {
    LNode *p = L1->next, *q = L2->next;
    while (q && p) {
        if (q->Elem != p->Elem)
            return false;
        else {
            q = q->next;
            p = p->next;
        }
    }
    if (p == q)
        return true;
    else
        return false;
}

//13.带头节点单链表L，查找L的倒数第k个元素
bool FindK(LinkList L, int k) {
    LNode *p = L, *q = L;
    while (q && k--)q = q->next;
    if (!q)return false;
    while (q) {
        p = p->next;
        q = q->next;
    }
    printf("%d\n", p->Elem);
    return true;
}

//14.寻找个数超过n/2的主元素
int Majority(int A[], int n) {
    int j[n];
    for (int i = 0; i < n; ++i) {
        j[i] = 0;
    }
    for (int i = 0; i < n; ++i) {
        j[A[i]]++;
        if (j[A[i]] > n / 2)
            return A[i];
    }
    return -1;
}

//T9.顺序表有序，插入一个元素，保持有序
void InsertElem(SqList &L, int e) {
    int i;
    for (i = L.length; i > 0 && L.data[i - 1] > e; i--) {
        L.data[i] = L.data[i - 1];
    }
    L.data[i] = e;
    L.length++;
}

//T10.顺序表，小于零的在左边，大于等于零的在右边
void SortT10(SqList &L) {
    int low = 0;
    int high = L.length - 1;
    while (low < high) {
        while (low < high && L.data[high] > 0)high--;
        Swap(L.data[high], L.data[low]);
        while (low < high && L.data[low] <= 0)low++;
        Swap(L.data[high], L.data[low]);
    }
}

//T12.原地逆置顺序表
void ReverseT12(SqList &L) {
    int low = 0, high = L.length - 1;
    while (low < high)
        Swap(L.data[low++], L.data[high--]);
}

//T14.合并结果为a1 b1 a2 b2 ...
void Merge(LinkList &L1, LinkList &L2) {
    LNode *q;
}

//T16.
void LinkListMergeDelSame(LinkList L1, LinkList L2, LinkList &L3) {
    LNode *p = L1->next, *q = L2->next, *r = L3;

}
