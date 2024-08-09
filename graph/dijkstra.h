void Dijkstra(MGraph G, int v, int dist[], int path[]) {
    int u, min;
    bool set[MAX_VERTEX];
    for (int i = 0; i < G.vexnum; ++i) {
        set[i] = false;
        dist[i] = G.Edge[v][i];
        if (dist[i] < INT_MAX) {
            path[i] = v;
        } else {
            path[i] = -1;
        }
    }
    path[v] = -1;
    set[v] = true;
    for (int i = 0; i < G.vexnum - 1; ++i) {
        min = INT_MAX;
        for (int j = 0; j < G.vexnum; ++j) {
            if (!set[j] && dist[j] < min) {
                min = dist[j];
                u = j;
            }
        }
        set[u] = true;
        for (int j = 0; j < G.vexnum; ++j) {
            if (!set[j] && dist[u] + G.Edge[u][j] < dist[j]) {
                dist[j] = dist[u] + G.Edge[u][j];
                path[j] = u;
            }
        }
    }
}

void Trace(int path[], int j) {
    if (j == -1)return;
    Trace(path, path[j]);
    printf("%d\t", j);
}