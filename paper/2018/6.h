int CoinSum(int coin[], int n, int M) {
    int sum = 0;
    for (int i = 0; i < n && M != 0; ++i) {
        if (coin[i] <= M) {
            sum += M / coin[i];
            M %= coin[i];
        }
    }
    return sum;
}