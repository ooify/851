typedef struct Edge {
    int a, b;
    int w;
} Edge;
int v[MAX_VERTEX];

//Edge edge[MAX_EDGE];

int GetRoot(int a) {
    while (a != v[a])
        a = v[a];
    return a;
}

void Swap(Edge &a, Edge &b) {
    Edge temp = a;
    a = b;
    b = temp;
}

int partition(Edge edge[], int low, int high) {
    int key = edge[low].w;
    while (low < high) {
        while (low < high && edge[high].w >= key)high--;
        Swap(edge[low], edge[high]);
        while (low < high && edge[low].w <= key)low++;
        Swap(edge[low], edge[high]);
    }
    return low;
}

void QuickSort(Edge edge[], int low, int high) {
    if (low >= high)return;
    int pivot = partition(edge, low, high);
    QuickSort(edge, 0, pivot - 1);
    QuickSort(edge, pivot + 1, high);
}

void Kruskal(MGraph G, Edge edge[], int &sum) {
    for (int i = 0; i < G.vexnum; ++i) {
        v[i] = i;
    }
    sum = 0;
    QuickSort(edge, 0, G.arcnum - 1);
    for (int i = 0; i < G.arcnum; ++i) {
        int a = GetRoot(edge[i].a);
        int b = GetRoot(edge[i].b);
        if (a != b) {
            v[a] = b;
            sum += edge[i].w;
        }
    }
}
