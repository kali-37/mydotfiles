#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define type int
#define tp(x) _Generic((x), \
    int: "%d ", \
    char: "%c ", \
    float: "%f ", \
    double: "%lf ", \
    char*: "%s ", \
    default: "Unknown format" \
)

void swap(type A[], int a, int b) {
    type temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}

void heapify(type A[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && A[l] > A[largest]) {
        largest = l;
    }
    if (r < n && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(A, largest, i);
        heapify(A, n, largest);
    }
}


void printType(type A[], int size) {
    for (int i = 0; i < size; i++)
        printf(tp(A[i]) , A[i]);
    printf("\n\n");
}




int main() {
    type A[] = {23, 34, 5, 3, 56, 0, 2, 34, 3333, 1};
    int n = sizeof(A) / sizeof(A[0]);
    printf("Before sorting:\n");
    printType(A, n);

    // Build max heap
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(A, n, i);
    }

    // Heap sort
    for (int i = n - 1; i >= 1; i--) {
        swap(A, i, 0);
        heapify(A, i, 0);
    }

    printf("After sorting:\n");
    printType(A, n);

    return 0;
}
