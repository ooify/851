void InsertSort(int A[], int n) {
    int i, j;
    for (i = 2; i <= n; ++i) {
        if (A[i] < A[i - 1]) {
            A[0] = A[i];
            for (j = i - 1; A[j] > A[0]; --j)
                A[j + 1] = A[j];
            A[j + 1] = A[0];
        }
    }
}
//void InsertSort(int A[], int n) {
//    int key, i, j;
//    for (i = 1; i < n; ++i) {
//        if (A[i] < A[i - 1]) {
//            key = A[i];
//            for (j = i - 1; j >= 0 && A[j] > key; --j) {
//                A[j + 1] = A[j];
//            }
//            A[j + 1] = key;
//        }
//    }
//}
//