void BinaryInsert(int A[], int n) {
    int i, j, low, high, mid;
    for (i = 2; i <= n; ++i) {
        A[0] = A[i];
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[0] < A[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        for (j = i - 1; j >= low; --j)
            A[j + 1] = A[j];
        A[low] = A[0];
    }
}
//void BinaryInsertSort(int A[], int n) {
//    int key, i, j, low, high, mid;
//    for (i = 1; i < n; ++i) {
//        key = A[i];
//        low = 0, high = i - 1;
//        while (low <= high) {
//            mid = (low + high) / 2;
//            if (A[mid] < key)
//                low = mid + 1;
//            else
//                high = mid - 1;
//        }
//        for (j = i - 1; j >= high + 1; --j) {
//            A[j + 1] = A[j];
//        }
//        A[high + 1] = key;
//    }
//}