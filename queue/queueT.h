#include "sqqueue.h"
#include "linkqueue.h"

typedef struct {
    int data[MAX_SIZE];
    int front, rear, tag;
} SqTagQueue;

//T12.使用tag值来判断队的空和满
void InitTagQueue(SqTagQueue &Q) {
    Q.front = Q.rear = Q.tag = 0;
}

bool EnTagQueue(SqTagQueue &Q, int e) {
    if (Q.tag == 1)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAX_SIZE;
    if (Q.rear == Q.front)Q.tag = 1;
    return true;
}

bool DeTagQueue(SqTagQueue &Q, int &e) {
    if (Q.tag == 0)
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    if (Q.front == Q.rear)Q.tag = 0;
    return true;
}

void PrintSqTagQueue(SqTagQueue Q) {
    printf("\nQ.front:%d\tQ.rear:%d\tQ.tag:%d\n", Q.front, Q.rear, Q.tag);
    while (Q.tag != 0) {
        int x;
        DeTagQueue(Q, x);
        printf("%d\t", x);
    }
}

//T14.一个字符串，实现为数字时入队，小写字母出队，其他字符结束,循环队列
void QueueT(char str[]) {
    SqTagQueue Q;
    InitTagQueue(Q);
    char *p = str;
    while (*p) {
        if (*p >= '0' && *p <= '9') {
            EnTagQueue(Q, *p);
        } else if (*p >= 'a' && *p <= 'z') {
            int x;
            DeTagQueue(Q, x);
        } else {
            break;
        }
        p++;
    }
}