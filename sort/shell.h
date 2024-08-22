void ShellSort(int A[], int n) {
    int d, i, j;
    for (d = n / 2; d >= 1; d /= 2) {
        for (i = d + 1; i <= n; ++i) {
            A[0] = A[i];
            if (A[i] < A[i - d]) {
                for (j = i - d; j > 0 && A[j] > A[0]; j -= d) {
                    A[j + d] = A[j];
                }
                A[j + d] = A[0];
            }
        }
    }
}
//void ShellSort(int A[], int n) {
//    for (int k = n / 2; k >= 1; k /= 2) {
//        for (int i = k; i < n; ++i) {
//            int key = A[i], j;
//            for (j = i - k; j >= 0 && A[j] > key; j -= k) {
//                A[j + k] = A[j];
//            }
//            A[j + k] = key;
//        }
//    }
//}
//