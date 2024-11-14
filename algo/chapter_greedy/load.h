void load(int x[], int w[], int c, int n)
{
    sort(n, w);
    for (int i = 1; i <= n; ++i)
        x[i] = 0;
    for (int i = 1; i <= n && w[i] <= c ; ++i)
    {
        x[i] = 1;
        c -= w[i];
    }
}
