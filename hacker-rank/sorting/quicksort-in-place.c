#include <stdio.h>

/*
 hackerrank: quicksort
 7
 5 8 1 3 7 9 2
 output
 2 3
 1 2 3
 7 8 9
 1 2 3 5 7 8 9
*/

void print(int *a, int n) {

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void swap(int *a, int *b) {

    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}

int partition(int *a, int first, int last, int n) {

    int i; /* counter */
    int pivotIndex; /* pivot element index */
    int storeIndex; /* divide position for pivot element */

    /* chose the pivot element and swap it with the last element */
    pivotIndex = last;

    storeIndex = first;
    for (i = first; i < last; i++) {
        if (a[i] < a[pivotIndex]) {
            swap(&a[i], &a[storeIndex]);
            storeIndex++; /* an element is stored in its right position, move index */
        }
    }
    swap(&a[pivotIndex], &a[storeIndex]);

    return storeIndex;
}

void quicksort(int *a, int first, int last, int n) {

    int p; /* partition index */

    if (first < last) {
        p = partition(a, first, last, n);
        print(a, n);
        quicksort(a, first, p - 1, n);
        quicksort(a, p + 1, last, n);
    }
}
int main(void) {

    int n;
    scanf("%d", &n);
    int a[n], i;
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, n - 1, n);
    return 0;
}


