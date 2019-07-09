//
//  Cut the sticks
//
//

#include <iostream>

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
}

int partition(int *a, int first, int last) {
    int pivot = last;
    int index = first;
    for (int i = first; i < last; i++) {
        if (a[i] < a[pivot]) {
            swap(&a[i], &a[index]);
            index++;
        }
    }
    swap(&a[index], &a[pivot]);
    return index;
}

void quicksort(int *a, int first, int last) {
    if (first < last) {
        int pivot = partition(a, first, last);
        quicksort(a, first, pivot - 1);
        quicksort(a, pivot + 1, last);
    }
}

void tests() {
}

int main() {
    tests();
    int n, a[1001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n-1);

    printf("%d\n", n);
    int index = 0;
    while (index < n) {
        int min = a[index];
        for (int i = index; i < n; i++) {
            a[i] -= min;
            if (a[i] == 0) {
                index++;
            }
        }
        if (index == n) { break; }
        printf("%d\n", n - index);
    }

    return 0;
}
