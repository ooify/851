#define SIZE 10
int UFSets[SIZE];

void InitUFSet(int UF[], int n) {
    for (int i = 0; i < n; ++i) {
        UF[i] = -1;
    }
}

int Find(int UF[], int i) {
    while (UF[i] >= 0) {
        i = UF[i];
    }
    return i;
}

int FindUp(int UF[], int i) {
    int root = i;
    while (UF[root] >= 0) {
        root = UF[root];
    }
    while (i != root) {
        int temp = UF[i];
        UF[i] = root;
        i = temp;
    }
    return root;
}

void Union(int UF[], int t1, int t2) {
    if (t1 == t2)return;
    UF[t2] = t1;
}

void UnionUp(int UF[], int t1, int t2) {
    if (t1 == t2)return;
    if (UF[t1] < UF[t2]) {
        UF[t1] += UF[t2];
        UF[t2] = t1;
    } else {
        UF[t2] += UF[t1];
        UF[t1] = t2;
    }
}