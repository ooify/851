// #define MAX_SIZE 5
typedef struct {
    int data[MAX_SIZE];
    int front, rear;
} SqQueue;

void InitSqQueue(SqQueue &Q) {
    Q.rear = Q.front = 0;
}

bool SqQueueEmpty(SqQueue Q) {
    if (Q.front == Q.rear)
        return true;
    return false;
}

bool GetHead(SqQueue Q, int &e) {
    if (SqQueueEmpty(Q))
        return false;
    e = Q.data[Q.front];
    return true;
}

bool EnQueue(SqQueue &Q, int e) {
    if ((Q.rear + 1) % MAX_SIZE == Q.front)
        return false;
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MAX_SIZE;
    return true;
}

bool DeQueue(SqQueue &Q, int &e) {
    if (Q.rear == Q.front)
        return false;
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    return true;
}

void PrintSqQueue(SqQueue Q) {
    printf("\nQ.front:%d\tQ.rear:%d\n", Q.front, Q.rear);
    while (Q.front != Q.rear) {
        printf("%d\t", Q.data[Q.front]);
        Q.front = (Q.front + 1) % MAX_SIZE;
    }
}