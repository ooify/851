void greed(int n, int k, int x[]) {
    int sum = 0;
    for (int i = 1; i <= k; ++i) {
        if (x[i] > n)
            return;
        sum += x[i];
        if (sum >= n) {
            printf("%d\t", i - 1);
            sum = x[i];
        }
    }
}   