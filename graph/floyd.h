void Floyd(MGraph G, int A[][MAX_VERTEX], int path[][MAX_VERTEX]) {
    for (int i = 0; i < G.vexnum; ++i) {
        for (int j = 0; j < G.vexnum; ++j) {
            A[i][j] = G.Edge[i][j];
            path[i][j] = -1;
        }
    }
    for (int k = 0; k < G.vexnum; ++k) {
        for (int i = 0; i < G.vexnum; ++i) {
            for (int j = 0; j < G.vexnum; ++j) {
                if (A[i][j] > A[i][k] + A[k][j]) {
                    A[i][j] = A[i][k] + A[k][j];
                    path[i][j] = k;
                }
            }
        }
    }
}

void Trace(int i, int j, int path[][MAX_VERTEX], int A[][MAX_VERTEX]) {
    if (A[i][j] == INT_MAX) return;
    if (path[i][j] == -1)
        printf("<%d\t%d>", i, j);
    else {
        Trace(i, path[i][j], path, A);
        Trace(path[i][j], j, path, A);
    }
}
