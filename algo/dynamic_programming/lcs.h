// 最长公共子序列
void LCSLength(int m, int n, char x[], char y[], int c[][MAX_SIZE], int b[][MAX_SIZE]) {
    for (int i = 1; i <= m; ++i)
        c[i][0] = 0;
    for (int i = 1; i <= n; ++i)
        c[0][i] = 0;
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (x[i] == y[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 1;
            } else if (c[i - 1][j] >= c[i][j - 1]) {
                c[i][j] = c[i - 1][j];
                b[i][j] = 2;
            } else {
                c[i][j] = c[i][j - 1];
                b[i][j] = 3;
            }
        }

    }
}

void TraceBack(int i, int j, char x[], int b[][MAX_SIZE]) {
    if (i == 0 || j == 0)
        return;
    if (b[i][j] == 1) {
        TraceBack(i - 1, j - 1, x, b);
        printf("%c", x[i]);
    } else if (b[i][j] == 2) {
        TraceBack(i - 1, j, x, b);
    } else {
        TraceBack(i, j - 1, x, b);
    }
}