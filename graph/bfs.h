bool visited[MAX_VERTEX];
SqQueue Q;

void visit(int e) {
    printf("%d", e);
}

void ABFS(ALGraph G, int i) {
    visit(i);
    visited[i] = true;
    EnQueue(Q, i);
    while (!SqQueueEmpty(Q)) {
        int v;
        DeQueue(Q, v);
        for (ArcNode *p = G.vertices[v].first; p; p = p->next) {
            int w = p->adjvex;
            if (!visited[w]) {
                visit(w);
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}

void MBFS(MGraph G, int i) {
    visit(i);
    visited[i] = true;
    EnQueue(Q, i);
    while (!SqQueueEmpty(Q)) {
        int v;
        DeQueue(Q, v);
        for (int w = 0; w < G.vexnum; w++) {
            if (!visited[w] && G.Edge[v][w] == 1) {
                visit(w);
                visited[w] = true;
                EnQueue(Q, w);
            }
        }
    }
}

void BFSAll(ALGraph G) {
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = false;
    }
    InitSqQueue(Q);
    for (int i = 0; i < G.vexnum; ++i) {
        if (!visited[i])
            ABFS(G, i);
    }
}
