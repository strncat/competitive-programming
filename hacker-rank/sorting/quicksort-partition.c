#include <stdio.h>

/* hackerrank - partition
 5
 4 5 3 7 2
 output
 3 2 4 5 7 
*/

void print(int *a, int n) {

    for (int k = 0; k < n; k++) {
        printf("%d ", a[k]);
    }
    printf("\n");
}

void swap (int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void partition(int *a, int n) {

    int i, lower[n], higher[n];
    int pivot = a[0]; /* pivot is the first element */
    int lowerIndex = 0, higherIndex = 0;

    for (i = 1; i < n; i++) {
        if (a[i] < pivot) {
            lower[lowerIndex++] = a[i];
        } else {
            higher[higherIndex++] = a[i];
        }
    }
    for (i = 0; i < lowerIndex; i++) { /* leftovers */
        a[i] = lower[i];
    }
    a[lowerIndex] = pivot;
    for (i = 0; i < higherIndex; i++) {
        a[lowerIndex + i + 1] = higher[i];
    }
    print(a, n);
}

/* Tail starts here */
int main(void) {

    int n;
    scanf("%d", &n);
    int a[n], i;
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    partition(a, n);

    return 0;
}