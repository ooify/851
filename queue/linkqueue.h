typedef struct {
    LinkNode *front, *rear;
} LinkQueue;

void InitLinkQueue(LinkQueue &Q) {
    Q.front = NULL;
    Q.rear = NULL;
}

bool EnLinkQueue(LinkQueue &Q, int e) {
    LinkNode *p = (LinkNode *) malloc(sizeof(LinkNode));
    if (!p)return false;
    p->data = e;
    p->next = NULL;
    if (!Q.front) {
        Q.rear = p;
        Q.front = p;
    } else {
        Q.rear->next = p;
        Q.rear = p;
    }
    return true;
}

bool DeLinkQueue(LinkQueue &Q, int &e) {
    if (!Q.front)return false;
    LinkNode *p = Q.front;
    e = p->data;
    Q.front = p->next;
    if (Q.rear == p) {
        Q.front = NULL;
        Q.rear = NULL;
    }
    free(p);
    return true;
}

void PrintLinkQueue(LinkQueue Q) {
    while (Q.front) {
        printf("%d\t", Q.front->data);
        Q.front = Q.front->next;
    }
    printf("\n");

}