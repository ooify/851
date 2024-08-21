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

int BinSearch_Recursion(SSTable T, int key, int low, int high) {
    if (low > high)return -1;
    if (low <= high) {
        int mid = (low + high) / 2;
        if (T.p[mid].key == key) {
            return mid;
        } else if (T.p[mid].key < key) {
            return BinSearch_Recursion(T, key, mid + 1, high);
        } else {
            return BinSearch_Recursion(T, key, low, mid - 1);
        }
    }
}

int BinSearch(SSTable T, int key) {
    int low = 0;
    int high = T.length - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (T.p[mid].key == key) {
            return mid;
        } else if (T.p[mid].key < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}