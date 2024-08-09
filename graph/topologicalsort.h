int indegree[MAX_VERTEX];
int print[MAX_VERTEX];
SqStack S;

bool TopoLogicalSort(ALGraph G) {
    InitSqStack(S);
    for (int i = 0; i < G.vexnum; ++i) {
        if (!indegree[i]) {
            Push(S, i);
        }
    }
    int count = 0;
    while (!SqStackEmpty(S)) {
        int v;
        Pop(S, v);
        print[count++] = v;
        for (ArcNode *p = G.vertices[v].first; p; p = p->next) {
            int w = p->adjvex;
            if (!(--indegree[w])) {
                Push(S, w);
            }
        }
    }
    if (count < G.vexnum) {
        return false;
    } else {
        return true;
    }
}

void GetInDegree(ALGraph G, int indegree[]) {
    for (int i = 0; i < G.vexnum; ++i) {
        indegree[i] = 0;
    }
    for (int i = 0; i < G.vexnum; ++i) {
        for (ArcNode *p = G.vertices[i].first; p; p = p->next) {
            int w = p->adjvex;
            indegree[w]++;
        }
    }
}