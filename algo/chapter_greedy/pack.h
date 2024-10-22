void sort(int i, int* p);

void pack(int n, int M, int w[], int x[])
{
    sort(n, w);
    int i;
    for (i = 1; i <= n; ++i)
        x[i] = 0;
    int c = M;
    for (i = 1; i <= n; ++i)
    {
        if (w[i] > c)
            break;
        x[i] = 1;
        c -= w[i];
    }
    if (i <= n)
        x[i] = c / w[i];
}
