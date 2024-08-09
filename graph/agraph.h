#define MAX_VERTEX 10
#define MAX_EDGE 10
typedef struct ArcNode {
    int adjvex;
    struct ArcNode *next;
} ArcNode;
typedef struct VNode {
    int data;
    ArcNode *first;
} VNode, AdjList[MAX_VERTEX];

typedef struct {
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;

