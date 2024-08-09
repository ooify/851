void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(int A[], int low, int high) {
    int key = A[low];
    while (low < high) {
        while (low < high && A[high] >= key)high--;
//        A[low] = A[high];
        swap(A[low], A[high]);
        while (low < high && A[low] <= key)low++;
//        A[high] = A[low];
        swap(A[low], A[high]);
    }
//    A[low] = key;
    return low;
}

void QuickSort(int A[], int low, int high) {
    if (low >= high)return;
    int pivot = partition(A, low, high);
    QuickSort(A, low, pivot - 1);
    QuickSort(A, pivot + 1, high);
}