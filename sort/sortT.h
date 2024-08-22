#include "insert.h"
#include "binaryinsert.h"
#include "shell.h"
#include "bubble.h"
#include "quick.h"
#include "select.h"

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