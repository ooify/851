int d[MAX_VERTEX], path[MAX_VERTEX];

void BFSMinDistance(ALGraph G, int v) {
    for (int i = 0; i < G.vexnum; ++i) {
        d[i] = INT_MAX;
        path[i] = -1;
    }
    visited[v] = true;
    EnQueue(Q, v);
    d[v] = 0;
    while (!SqQueueEmpty(Q)) {
        int u;
        DeQueue(Q, u);
        for (ArcNode *p = G.vertices[v].first; p; p = p->next) {
            int w = p->adjvex;
            visited[w] = true;
            path[w] = u;
            d[w] = d[u] + 1;
            EnQueue(Q, w);
        }
    }
}