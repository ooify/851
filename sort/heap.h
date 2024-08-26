void HeapAdjust(int A[], int k, int n) {
    A[0] = A[k];
    for (int i = k * 2; i <= n; i *= 2) {
        if (i < n && A[i] < A[i + 1])
            i++;
        if (A[0] >= A[i])
            break;             x
        else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = A[0];
}

void BuildMaxHeap(int A[], int n) {
    for (int i = n / 2; i > 0; --i) {
        HeapAdjust(A, i, n);
    }
}

void HeadSort(int A[], int n) {
    BuildMaxHeap(A, n);
    for (int i = n; i > 1; --i) {
        Swap(A[i], A[1]);
        HeapAdjust(A, 1, i - 1);
    }
}