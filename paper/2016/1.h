void divide(int m, int A[]) {
    int i = 0;
    while (m) {
        A[i++] = m % 10;
        m /= 10;
    }
}

void max_min(int A[], int &max, int &min) {
    max = min = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 4; ++j) {
            if (A[i] > A[j]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }

    }
    for (int i = 0, j = 3; i < 4;
         ++i, j--) {
        max = max * 10 + A[j];
        min = min * 10 + A[i];
    }
}

void vr6174(int n) {
    int A[4];
    int max, min;
    while (  n != 6174) {
        divide(n, A);
        max_min(A, max, min);
        n = max - min;
        printf("%d-%d=%d\n", max, min, n);
    }
}