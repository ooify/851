void Pack(int n, int c, int w[], int v[], int dp[][MAX_SIZE]) {
    for (int i = 1; i <= n; ++i)
        dp[i][0] = 0;
    for (int i = 0; i <= c; ++i)
        dp[0][i] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (w[i - 1] > j)
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = fmax(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
        }
    }
}

void TraceBack(int n, int c, int w[], int dp[][MAX_SIZE], int x[]) {
    for (int i = n; i > 0; --i) {
        if (dp[i][c] == dp[i - 1][c])
            x[i] = 0;
        else {
            x[i] = 1;
            c -= w[i];
        }
    }
}