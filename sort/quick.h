int partition(int A[], int low, int high) {
    int pivot = A[low];
    while (low < high) {
        while (low < high && A[high] >= pivot)high--;
        A[low] = A[high];
//        Swap(A[low], A[high]);
        while (low < high && A[low] <= pivot)low++;
        A[high] = A[low];
//        Swap(A[low], A[high]);
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high) {
    if (low >= high)return;
    int pivot = partition(A, low, high);
    QuickSort(A, low, pivot - 1);
    QuickSort(A, pivot + 1, high);
}