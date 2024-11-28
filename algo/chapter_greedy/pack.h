void sort(int i, float* v, float* p);

void pack(int n, float M, float v[], float w[], float x[])
{
    sort(n, v, w);
    int i;
    for (i = 1; i <= n; ++i)
        x[i] = 0;
    float c = M;
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
