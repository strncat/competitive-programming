#include <stdio.h>

/* Priyanka and Toys */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parition(int *a, int first, int last) {
    int pivot = last;
    int index = first;
    
    for (int i = first; i < last; i++) {
        if (a[i] < a[pivot]) {
            swap(&a[index], &a[i]);
            index++;
        }
    }
    swap(&a[index], &a[pivot]);
    return index;
}

void quicksort(int *a, int first, int last) {
    if (first < last) {
        int p = parition(a, first, last);
        quicksort(a, first, p - 1);
        quicksort(a, p + 1, last);
    }
}

int main() {
    int w[100010], n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }
    quicksort(w, 0, n - 1);

    int buy = 1;
    int max = w[0] + 4;

    for (int i = 1; i < n; i++) {
        if (w[i] > max) {
            buy++;
            max = w[i] + 4;
        }
    }
    printf("%d\n", buy);
    return 0;
}
