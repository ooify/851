#include <cstdio>
#include <cstdlib>

#define INIT_SIZE 5

typedef struct {
    int *data;
    int length;
    int MaxSize;
} SqList;

void InitList(SqList &L) {
    L.length = 0;
    L.MaxSize = INIT_SIZE;
    L.data = (int *) malloc(sizeof(int) * INIT_SIZE);
}

bool SqListInsert(SqList &L, int i, int e) {
    if (i < 1 || i > L.length + 1 || L.length == L.MaxSize)
        return false;
    int j;
    for (j = L.length; j >= i; --j) {
        L.data[j] = L.data[j - 1];
    }
    L.data[j] = e;
    L.length++;
    return true;
}

bool SqListDelete(SqList &L, int i, int &e) {
    if (i > L.length || i < 1 || L.length == 0)
        return false;
    e = L.data[i - 1];
    for (int j = i - 1; j < L.length - 1; ++j) {
        L.data[j] = L.data[j + 1];
    }
    L.length--;
    return true;
}

int SqListLocateElem(SqList L, int e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e)
            return L.data[i];
    }
    return -1;
}

void PrintSqList(SqList L) {
    printf("length:%d\tMaxSize:%d\n", L.length, L.MaxSize);
    for (int i = 0; i < L.length; ++i) {
        printf("%d\t", L.data[i]);
    }
    printf("\n");

}





