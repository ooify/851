typedef struct LinkNode {
    int data;
    struct LinkNode *next;
} LinkNode;
typedef struct {
    LinkNode *top;
    int count;
} *LinkStack;
//不带头节点

bool InitLinkStack(LinkStack &S) {
    S = (LinkStack) malloc(sizeof(LinkStack));
    if (!S)return false;
    S->top = NULL;
    S->count = 0;
    return true;

}

bool LinkStackEmpty(LinkStack S) {
    if (!S->top)
        return true;
    return false;
}

bool GetTop(LinkStack S, int &e) {
    if (!S->top)
        return false;
    e = S->top->data;
    return true;
}

bool Push(LinkStack &S, int e) {
    LinkNode *p = (LinkNode *) malloc(sizeof(LNode));
    if (!p)return false;
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;
    return true;
}

bool Pop(LinkStack &S, int &e) {
    if (!S->top)return false;
    e = S->top->data;
    LinkNode *temp = S->top;
    S->top = S->top->next;
    free(temp);
    S->count--;
    return true;
}

void PrintLinkStack(LinkStack S) {
    printf("S.count:%d\n", S->count);
    LinkNode *p = S->top;
    while (p) {
        printf("%d\t", p->data);
        p = p->next;
    }
}