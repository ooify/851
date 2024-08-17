//#include "insert.h"
//#include "quick.h"
//
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
//
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
//void swap(int *a, int *b) {
//    int temp = *a;
//    *a = *b;
//    *b = temp;
//}
//
//void BubbleSort(int A[], int n) {
//    for (int i = 0; i < n; ++i) {
//        int flag = 0;
//        for (int j = n - 2; j >= i; --j) {
//            if (A[j] > A[j + 1]) {
//                swap(&A[j + 1], &A[j]);
//                flag = 1;
//            }
//        }
//        if (!flag)return;
//    }
//}
//
//int partition(int A[], int low, int high) {
//    int key = A[low];
//    while (low < high) {
//        while (low < high && A[high] >= key)high--;
////        A[low] = A[high];
//        swap(&A[low], &A[high]);
//        while (low < high && A[low] <= key)low++;
////        A[high] = A[low];
//        swap(&A[low], &A[high]);
//    }
////    A[low] = key;
//    return low;
//}
//
//void QuickSort(int A[], int low, int high) {
//    if (low >= high)return;
//    int pivot = partition(A, low, high);
//    QuickSort(A, low, pivot - 1);
//    QuickSort(A, pivot + 1, high);
//}
//
//void SelectSort(int A[], int n) {
//    int i, j, min;
//    for (i = 0; i < n - 1; ++i) {
//        min = i;
//        for (j = i + 1; j < n; ++j) {
//            if (A[j] < A[min])
//                min = j;
//        }
//        if (min != i)
//            swap(&A[i], &A[min]);
//    }
//}
//
//void adjust(int A[], int k, int n) {
//
//}
//
//void HeapSort(int A[], int n) {
//    for (int i = n / 2; i > 0; --i) {
//        adjust(A, i, n);
//    }
//    for (int i = n; i > 1; --i) {
//        swap(&A[1], &A[i]);
//        adjust(A, 1, i - 1);
//    }
//}