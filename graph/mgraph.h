#define MAX_VERTEX 10
#define MAX_EDGE 10
typedef struct {
    char Vex[MAX_VERTEX];
    int Edge[MAX_VERTEX][MAX_VERTEX];
    int vexnum, arcnum;
} MGraph;