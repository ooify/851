#include <climits>

void Prim(MGraph G, int v, int &sum) {
    bool isJoin[MAX_VERTEX];
    int u, min, lowcost[MAX_VERTEX];
    for (int i = 0; i < G.vexnum; ++i) {
        isJoin[i] = false;
        lowcost[i] = G.Edge[v][i];
    }
    isJoin[v] = true;
    sum = 0;
    for (int i = 0; i < G.vexnum - 1; ++i) {
        min = INT_MAX;
        for (int j = 0; j < G.vexnum; ++j) {
            if (!isJoin[j] && lowcost[j] < min) {
                min = lowcost[j];
                u = j;
            }
        }
        isJoin[u] = true;
        sum += min;
        for (int j = 0; j < G.vexnum; ++j) {
            if (!isJoin[j] && G.Edge[u][j] < lowcost[j]) {
                lowcost[j] = G.Edge[u][j];
            }
        }
    }
}
