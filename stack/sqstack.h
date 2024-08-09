#define MAX_SIZE 10
typedef struct SqStack {
    int data[MAX_SIZE];
    int top;
} SqStack;

void InitSqStack(SqStack &S) {
    S.top = -1;
}

bool SqStackEmpty(SqStack S) {
    if (S.top == -1)
        return true;
    return false;
}

bool GetTop(SqStack S, int &e) {
    if (S.top == -1)
        return false;
    e = S.data[S.top];
    return true;
}

bool Push(SqStack &S, int e) {
    if (S.top == MAX_SIZE - 1)
        return false;
    S.data[++S.top] = e;
    return true;
}

bool Pop(SqStack &S, int &e) {
    if (S.top == -1)
        return false;
    e = S.data[S.top--];
    return true;
}

void PrintStack(SqStack S) {
    printf("S.top:%d\n", S.top);
    while (S.top != -1)
        printf("%d\t", S.data[S.top--]);
}