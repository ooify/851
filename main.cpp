#include "list/listT.h"
#include "stack/stackT.h"
#include "queue/queueT.h"
#include "tree/treeT.h"
#include "graph/graphT.h"
#include "search/searchT.h"
#include "sort/sortT.h"


void SqListInsertTest() {
    SqList L;
    InitList(L);
    SqListInsert(L, 1, 1);
    SqListInsert(L, 1, 2);
    SqListInsert(L, 1, 3);
    SqListInsert(L, 1, 4);
    SqListInsert(L, 1, 5);
//    printf("%d\n", ListInsert(L, 1, 6));
    PrintSqList(L);
}

void SqListDeleteTest() {
    SqList L;
    InitList(L);
    SqListInsert(L, 1, 1);
    SqListInsert(L, 1, 2);
    SqListInsert(L, 1, 3);
    SqListInsert(L, 1, 4);
    SqListInsert(L, 1, 5);
    int x;
    printf("%d\n", SqListDelete(L, 1, x));
    PrintSqList(L);
}

void SqListLocateElemTest() {
    SqList L;
    InitList(L);
    SqListInsert(L, 1, 1);
    SqListInsert(L, 1, 2);
    SqListInsert(L, 1, 3);
    SqListInsert(L, 1, 4);
    SqListInsert(L, 1, 5);
    printf("%d", SqListLocateElem(L, 5));
}

void LinkListTest() {
    LinkList L;
    InitLinkList(L);
    LinkListInsert(L, 1, 1);
    LinkListInsert(L, 1, 2);
    LinkListInsert(L, 1, 3);
    LinkListInsert(L, 1, 4);
    LinkListInsert(L, 1, 5);
    LinkListInsertpriorNode(GetElem(L, 3), 9);
    LinkListInsertpriorNode(LocateElem(L, 1), 8);
    LinkListInsertNextNode(LocateElem(L, 1), 6);
    PrintLinkList(L);
    int x;
    LinkListDelete(L, 3, x);
    PrintLinkList(L);
}

void LinkListMergeTest() {
    LinkList L1, L2, L3;
    InitLinkList(L1);
    InitLinkList(L2);
    InitLinkList(L3);
    LinkListInsert(L1, 1, 6);
    LinkListInsert(L1, 1, 2);
    LinkListInsert(L1, 1, 1);
    LinkListInsert(L2, 1, 9);
    LinkListInsert(L2, 1, 4);
    LinkListInsert(L2, 1, 3);
    PrintLinkList(L1);
    PrintLinkList(L2);
    LinkListMerge(L1, L2, L3);
    PrintLinkList(L3);
}


void MoveTest() {
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Move(A, 3, 9);
    for (int i = 0; i < 9; ++i) {
        printf("%d\t", A[i]);
    }
}

void InsertElemTest() {
    int A[] = {11, 12, 13, 4, 5, 6, 7, 8, 9};
    InsertElem(A, 3, 6);
    for (int i = 0; i < 9; ++i) {
        printf("%d\t", A[i]);
    }
}

void DifferenceTest() {
    LinkList L1, L2;
    InitLinkList(L1);
    InitLinkList(L2);
    LinkListInsert(L1, 1, 7);
    LinkListInsert(L1, 1, 6);
    LinkListInsert(L1, 1, 4);
    LinkListInsert(L1, 1, 1);
    LinkListInsert(L2, 1, 9);
    LinkListInsert(L2, 1, 8);
    LinkListInsert(L2, 1, 6);
    LinkListInsert(L2, 1, 3);
    PrintLinkList(L1);
    PrintLinkList(L2);

    Difference(L1, L2);
    PrintLinkList(L1);
}

void DeleteElemTest() {
    SqList L;
    InitList(L);
    SqListInsert(L, 1, 5);
    SqListInsert(L, 1, 4);
    SqListInsert(L, 1, 3);
    SqListInsert(L, 1, 2);
    SqListInsert(L, 1, 1);
    PrintSqList(L);
    DeleteElem(L, 1, 3);
    PrintSqList(L);
}

void PartitionTest() {
    int A[] = {5, 2, 6, 3, 1, 9, 4, 8, 7};
    Partition(A, 9);
    for (int i: A) {
        printf("%d\t", i);
    }
}

void DelSameTest() {
    LinkList L;
    InitLinkList(L);
    LinkListInsert(L, 1, 4);
    LinkListInsert(L, 1, 3);
    LinkListInsert(L, 1, 3);
    LinkListInsert(L, 1, 3);
    LinkListInsert(L, 1, 2);
    LinkListInsert(L, 1, 2);
    LinkListInsert(L, 1, 1);
    PrintLinkList(L);
    DelSame(L);
    PrintLinkList(L);
}

void ReverseTest() {
    LinkList L;
    InitLinkList(L);
    LinkListInsert(L, 1, 9);
    LinkListInsert(L, 1, 8);
    LinkListInsert(L, 1, 7);
    LinkListInsert(L, 1, 6);
    LinkListInsert(L, 1, 5);
    LinkListInsert(L, 1, 4);
    LinkListInsert(L, 1, 3);
    LinkListInsert(L, 1, 2);
    LinkListInsert(L, 1, 1);
    PrintLinkList(L);
    Reverse(L);
    PrintLinkList(L);
}

void SplitTest() {
    LinkList L1, L2;
    InitLinkList(L1);
    InitLinkList(L2);
    LinkListInsert(L1, 1, 10);
    LinkListInsert(L1, 1, 9);
    LinkListInsert(L1, 1, 8);
    LinkListInsert(L1, 1, 7);
    LinkListInsert(L1, 1, 6);
    LinkListInsert(L1, 1, 5);
    LinkListInsert(L1, 1, 4);
    LinkListInsert(L1, 1, 3);
    LinkListInsert(L1, 1, 2);
    LinkListInsert(L1, 1, 1);
    PrintLinkList(L1);
    Split(L1, L2);
    PrintLinkList(L1);
    PrintLinkList(L2);
}

void RecursionPrintLinkListTest() {
    LinkList L = (LinkList) malloc(sizeof(LNode));
    L->Elem = 1;
    LNode *n1 = (LNode *) malloc(sizeof(LNode));
    LNode *n2 = (LNode *) malloc(sizeof(LNode));
    n1->Elem = 2;
    n2->Elem = 3;
    L->next = n1;
    n1->next = n2;
    n2->next = NULL;
    RecursionPrintLinkList(L);
}

void EqualTest() {
    LinkList L1, L2;
    InitLinkList(L1);
    InitLinkList(L2);
    LinkListInsert(L1, 1, 4);
    LinkListInsert(L1, 1, 3);
    LinkListInsert(L1, 1, 2);
    LinkListInsert(L1, 1, 1);
    LinkListInsert(L2, 1, 4);
    LinkListInsert(L2, 1, 3);
    LinkListInsert(L2, 1, 2);
    LinkListInsert(L2, 1, 1);
    PrintLinkList(L1);
    PrintLinkList(L2);
    printf("%d", Equal(L1, L2));
}

void FindKTest() {
    LinkList L;
    InitLinkList(L);
    LinkListInsert(L, 1, 9);
    LinkListInsert(L, 1, 8);
    LinkListInsert(L, 1, 7);
    LinkListInsert(L, 1, 6);
    LinkListInsert(L, 1, 5);
    LinkListInsert(L, 1, 4);
    LinkListInsert(L, 1, 3);
    LinkListInsert(L, 1, 2);
    LinkListInsert(L, 1, 1);
    PrintLinkList(L);
    printf("%d\n", FindK(L, 5));
}

void MajorityTest() {
//    int A[] = {0, 5, 5, 3, 5, 7, 5, 5};
    int A[] = {0, 5, 5, 3, 5, 1, 5, 7};
    printf("%d", Majority(A, 8));
}

void SqListInsertElemTest() {
    SqList L;
    InitList(L);
    SqListInsert(L, 1, 5);
    SqListInsert(L, 1, 4);
    SqListInsert(L, 1, 2);
    SqListInsert(L, 1, 1);
    PrintSqList(L);
    InsertElem(L, 0);
    PrintSqList(L);
}

void SortT10Test() {
    SqList L;
    InitList(L);
    SqListInsert(L, 1, 4);
    SqListInsert(L, 1, -1);
//    SqListInsert(L, 1, 3);
    SqListInsert(L, 1, 0);
//    SqListInsert(L, 1, 1);
    SqListInsert(L, 1, -2);
    SqListInsert(L, 1, 1);
    PrintSqList(L);
    SortT10(L);
    PrintSqList(L);
}

void ReverseT12Test() {
    SqList L;
    InitList(L);
    SqListInsert(L, 1, 5);
    SqListInsert(L, 1, 4);
    SqListInsert(L, 1, 3);
    SqListInsert(L, 1, 2);
    SqListInsert(L, 1, 1);
    PrintSqList(L);
    ReverseT12(L);
    PrintSqList(L);
}

void LinkListMergeDelSameTest() {
    LinkList L1, L2, L3;
    InitLinkList(L1);
    InitLinkList(L2);
    InitLinkList(L3);
    LinkListInsert(L1, 1, 5);
    LinkListInsert(L1, 1, 2);
    LinkListInsert(L1, 1, 1);
    LinkListInsert(L2, 1, 4);
    LinkListInsert(L2, 1, 3);
    LinkListInsert(L2, 1, 2);
    PrintLinkList(L1);
    PrintLinkList(L2);
    LinkListMerge(L1, L2, L3);
    PrintLinkList(L3);
}

void SqStackTest() {
    SqStack S;
    InitSqStack(S);
    printf("%d\n", SqStackEmpty(S));
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    PrintStack(S);

    int x;
    GetTop(S, x);
    printf("\n%d\n", x);
    PrintStack(S);

    Pop(S, x);
    printf("\n%d\n", x);
    PrintStack(S);
    printf("\n%d\n", SqStackEmpty(S));

}

void LinkStackTest() {
    LinkStack S;
    InitLinkStack(S);
    printf("%d\n", LinkStackEmpty(S));
    Push(S, 1);
    Push(S, 2);
    Push(S, 3);
    PrintLinkStack(S);

    int x;
    GetTop(S, x);
    printf("\n%d\n", x);
    PrintLinkStack(S);

    Pop(S, x);
    printf("\n%d\n", x);
    PrintLinkStack(S);
    printf("\nLinkStackEmpty:%d\n", LinkStackEmpty(S));
}


void SqQueueTest() {
    SqQueue Q;
    InitSqQueue(Q);
    printf("\nSqQueueEmpty:%d\n", SqQueueEmpty(Q));
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    PrintSqQueue(Q);

    int x;
    GetHead(Q, x);
    printf("\nGetHead:%d\n", x);
    PrintSqQueue(Q);


    DeQueue(Q, x);
    printf("\nDeQueue:%d\n", x);
    PrintSqQueue(Q);

}

void SqQueueTest1() {
    SqQueue Q;
    InitSqQueue(Q);
    EnQueue(Q, 1);
    EnQueue(Q, 2);
    EnQueue(Q, 3);
    EnQueue(Q, 4);
    PrintSqQueue(Q);
    int x;
    DeQueue(Q, x);
    DeQueue(Q, x);
    EnQueue(Q, 5);
    EnQueue(Q, 6);
    PrintSqQueue(Q);

}

void LinkQueueTest() {
    LinkQueue Q;
    InitLinkQueue(Q);
    EnLinkQueue(Q, 1);
    EnLinkQueue(Q, 2);
    EnLinkQueue(Q, 3);
    EnLinkQueue(Q, 4);
    EnLinkQueue(Q, 5);
    PrintLinkQueue(Q);
    int x;
    DeLinkQueue(Q, x);
    DeLinkQueue(Q, x);
    DeLinkQueue(Q, x);
    PrintLinkQueue(Q);
}

void MatchTest() {
    int s[] = {'(', '(', ')', '(', ')', ')', ')'};
    printf("%d", Match(s, 6));
}

void CalcExpTest() {
    char exp[] = "45*6+93/-";
    printf("%d", CalcExp(exp));
}

void StackQueueTest() {
    int x;
    SqStack in, out;
    InitSqStack(in);
    InitSqStack(out);
    EnStackQueue(in, 1);
    EnStackQueue(in, 2);
    DeStackQueue(in, out, x);
    printf("%d\t", x);
    EnStackQueue(in, 3);
    EnStackQueue(in, 4);
    EnStackQueue(in, 5);
    DeStackQueue(in, out, x);
    printf("%d\t", x);
    DeStackQueue(in, out, x);
    printf("%d\t", x);
    DeStackQueue(in, out, x);
    printf("%d\t", x);
    DeStackQueue(in, out, x);
    printf("%d\t", x);
}

void JudgeSqTest() {
    char str[] = {'i', 'i', 'o', 'i', 'o', 'o', '\0'};
    printf("%d", JudgeSq(str));
}

void CheakBracTest() {
    char str[] = {'(', '[', '[', '(', ']', ']', ')', ')', '\0'};
//    char str[] = {'(', '(', '[ ', '[', ']', ']', ')', ')', '\0'};
    printf("%d", CheakBrac(str));
}

void ChackTest() {
    char str[] = "a+b&b+a@";
    printf("%d", Chack(str));
}

void ChackStrTest() {
//    char str[] = "abccba";
    char str[] = "abcdef";
    printf("%d", ChackStr(str));
}

void SwitchTypeTest() {
    char str[] = "HSHSHSHHHHHSSSSS";
    SwitchType(str);
}

void SqTagQueueTest() {
    SqTagQueue Q;
    InitTagQueue(Q);
    EnTagQueue(Q, 1);
    EnTagQueue(Q, 2);
    EnTagQueue(Q, 3);
    EnTagQueue(Q, 4);
    EnTagQueue(Q, 5);
    PrintSqTagQueue(Q);
    int x;
    DeTagQueue(Q, x);
    PrintSqTagQueue(Q);
    DeTagQueue(Q, x);
    DeTagQueue(Q, x);
    DeTagQueue(Q, x);
    DeTagQueue(Q, x);
    PrintSqTagQueue(Q);

}

void BinSearch_RecursionTest() {
    SSTable T;
    ElemType E[9];
    for (int i = 0; i < 9; ++i) {
        E[i].key = i + i;
        printf("%d\t", i + i);
    }
    printf("\n");
    T.p = E;
    T.length = 9;
//    int x = BinSearch_Recursion(T, 8, 0, T.length - 1);
    int x = BinSearch(T, 0);
    printf("%d\n", x);
}

void PrintSort(int A[]) {
    for (int i = 0; i < 9; ++i) {
        printf("%d\t", A[i]);
    }
    printf("\n");
}

void InsertSortTest() {
    int A[] = {0, 4, 3, 2, 5, 1, 7, 8, 6};
    PrintSort(A);
    InsertSort(A, 9);
    PrintSort(A);
}

void BinaryInsertTest() {
    int A[] = {0, 4, 3, 2, 5, 1, 7, 8, 6};
    PrintSort(A);
    BinaryInsert(A, 9);
    PrintSort(A);
}

void ShellSortTest() {
    int A[] = {0, 4, 3, 2, 5, 1, 7, 8, 6};
    PrintSort(A);
    ShellSort(A, 9);
    PrintSort(A);
}

void BubbleSortTest() {
    int A[] = {0, 4, 3, 2, 5, 1, 7, 8, 6};
    PrintSort(A);
    BubbleSort(A, 9);
    PrintSort(A);
}

void QuickSortTest() {
    int A[] = {0, 4, 3, 2, 5, 1, 7, 8, 6};
    PrintSort(A);
    QuickSort(A, 0, 8);
    PrintSort(A);
}

void SelectSortTest() {
    int A[] = {0, 4, 3, 2, 5, 1, 7, 8, 6};
    PrintSort(A);
    SelectSort(A, 9);
    PrintSort(A);
}

void HeadSortTest() {
    int A[] = {0, 4, 3, 2, 5, 1, 7, 8, 6};
    PrintSort(A);
    HeadSort(A, 9);
    PrintSort(A);
}

void MergeSortTest() {
    int A[] = {0, 4, 3, 2, 5, 1, 7, 8, 6};
    PrintSort(A);
    MergeSort(A, 0, 8);
    PrintSort(A);

}

int main() {
    MergeSortTest();
    return 0;
}
