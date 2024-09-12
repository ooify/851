void Insert(int A[], int m, int B[], int n) {
    int i, temp;
    while (A[m - 1] > A[0]) {
        temp = A[m - 1];
        A[m - 1] = B[0];
        for (i = 1; i < n && B[i] <= temp; ++i)
            B[i - 1] = B[i];
        B[i - 1] = temp;
        temp = A[m - 1];
        for (i = m - 2; i >= 0 && A[i] >= temp; i--)
            A[i + 1] = A[i];
        A[i + 1] = temp;
    }
}