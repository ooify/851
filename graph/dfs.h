void ADFS(ALGraph G, int i) {
    visit(i);
    visited[i] = true;
    for (ArcNode *p = G.vertices[i].first; p; p = p->next) {
        int w = p->adjvex;
        if (!visited[w]) {
            ADFS(G, w);
        }
    }
}

void MDFS(MGraph G, int i) {
    visit(i);
    visited[i] = true;
    for (int w = 0; w < G.vexnum; w++) {
        if (!visited[i] && G.Edge[i][w] == 1) {
            MDFS(G, i);
        }
    }
}

void DFS(ALGraph G) {
    for (int i = 0; i < G.vexnum; ++i) {
        visited[i] = false;
    }
    for (int i = 0; i < G.vexnum; ++i) {
        if (!visited[i]) {
            ADFS(G, i);
        }
    }
}
