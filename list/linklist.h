#include <cstdlib>
#include <cstdio>

typedef struct LNode {
    int Elem;
    struct LNode *next;
} LNode, *LinkList;

void InitLinkList(LinkList &L) {
    L = (LNode *) malloc(sizeof(LNode));
    L->next = NULL;
}

LinkList List_HeadInsert(LinkList &L) {
    int x;
    LNode *s;
    scanf("%d", &x);
    while (x != 999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->Elem = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L) {
    int x;
    LNode *s, *r = L;
    scanf("%d", &x);
    while (x != 999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->Elem = x;
        r->next = L->next;
        scanf("%d", &x);
    }
    return L;
}

bool LinkListInsertNextNode(LNode *p, int e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->Elem = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool LinkListInsertpriorNode(LNode *p, int e) {
    if (p == NULL)
        return false;
    LNode *s = (LNode *) malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->next = p->next;
    p->next = s;
    s->Elem = p->Elem;
    p->Elem = e;
    return true;
}

bool LinkListInsert(LinkList &L, int i, int e) {
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
//    if (p == NULL)
//        return false;
    return LinkListInsertNextNode(p, e);
}

bool LinkListDelete(LinkList &L, int i, int &e) {
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL || p->next == NULL)
        return false;
    LNode *s = p->next;
    e = s->Elem;
    p->next = s->next;
    free(s);
    return true;
}

int GetLength(LinkList L) {
    LNode *p = L;
    int len = 0;
    while (p->next != NULL) {
        p = p->next;
        len++;
    }
    return len;
}

LNode *GetElem(LinkList L, int i) {
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

LNode *LocateElem(LinkList L, int e) {
    LNode *p = L->next;
    while (p != NULL && p->Elem != e)
        p = p->next;
    return p;
}


void PrintLinkList(LinkList L) {
    LNode *p = L;
    printf("length:%d\n", GetLength(L));
    while (p->next != NULL) {
        p = p->next;
        printf("%d\t", p->Elem);
    }
    printf("\n");
}
