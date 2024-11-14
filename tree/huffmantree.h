typedef struct HuffManNode
{
    int weigh;
    int parent, lchild, rchild;
} HuffManTree[];

void Select(HuffManTree T, int n, int& min1, int& min2)
{
    int min = MAX;
    for (int i = 0; i < n; ++i)
    {
        if (T[i].weigh < min && T[i].parent == -1)
        {
            min1 = i;
            min = T[i].weigh;
        }
    }
    min = MAX;
    for (int i = 0; i < n; ++i)
    {
        if (T[i].weigh < min && T[i].parent == -1 && i != min1)
        {
            min2 = i;
            min = T[i].weigh;
        }
    }
}

void HuffManTree(HuffManTree T, int n, int a[])
{
    for (int i = 0; i < 2 * n - 1; ++i)
    {
        T[i].lchild = -1;
        T[i].rchild = -1;
        T[i].parent = -1;
        T[i].weigh = -1;
    }
    for (int i = 0; i < n; ++i)
    {
        T[i].weigh = a[i];
    }
    int min1 = 0, min2 = 0;
    for (int i = n; i < 2 * n - 1; ++i)
    {
        Select(T, i, min1, min2);
        T[i].lchild = min1;
        T[i].rchild = min2;
        T[min1].parent = i;
        T[min2].parent = i;
        T[i].weigh = T[min1].weigh + T[min2].weigh;
    } q
}
