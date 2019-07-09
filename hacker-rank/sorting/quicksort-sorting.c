#include <stdio.h>

/* hackerrank - QuickSort 2 - Sorting 
*/

void print(int *a, int first, int last) {

    for (int k = first; k <= last; k++) {
        printf("%d ", a[k]);
    }
    printf("\n");
}

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int first, int last, int n) {

    int i, lower[n], higher[n];
    int lowerIndex = 0, higherIndex = 0;
    int pivot = a[first]; /* pivot is the first element */

    /* copy elements to lower and higher arrays */
    for (i = first + 1; i <= last; i++) {
        if (a[i] < pivot) {
            lower[lowerIndex++] = a[i];
        } else {
            higher[higherIndex++] = a[i];
        }
    }

    /* (1) copy lower elements first to the array */
    for (i = 0; i < lowerIndex; i++) {
        a[first + i] = lower[i];
    }

    /* (2) copy the pivot element in its place */
    int pivotIndex = first + i;
    a[pivotIndex] = pivot;

    /* (3) copy the higher elements to the array after the pivot */
    for (i = 0; i < higherIndex; i++) {
        a[lowerIndex + first + i + 1] = higher[i];
    }
    return pivotIndex;
}

void quicksort(int *a, int first, int last, int n) {
    if (first < last) {
        int p = partition(a, first, last, n);
        quicksort(a, first, p - 1, n);
        quicksort(a, p + 1, last, n);
        print(a, first, last);
    }
}

/* Tail starts here */
int main(void) {

    int n;
    scanf("%d", &n);
    int a[n], i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1, n);

    return 0;
}