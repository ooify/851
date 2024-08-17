
typedef struct ElemType {
    int key;
    char other;
} ElemType; 
typedef struct SSTable {
    ElemType *p;
    int length;
} SSTable;

void InitSSTable(SSTable &T) {
    T.p = (ElemType *) malloc(sizeof(ElemType) * MAX_SIZE);
    T.length = MAX_SIZE;
}

int SqSearch(SSTable T, ElemType key) {
    T.p[0] = key;
    int i = T.length - 1;
    while (T.p[i].key != key.key)i--;
    return i;
}
