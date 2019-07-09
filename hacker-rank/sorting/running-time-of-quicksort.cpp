//
//  main.cpp
//  quick
//
//  Created by Fatima B on 12/25/15.
//  Copyright © 2015 Fatima B. All rights reserved.
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

int partition(int *a, int first, int last, int n, int *count) {
    int pivot = last;
    int index = first;
    for (int i = first; i < last; i++) {
        if (a[i] < a[pivot]) {
            swap(&a[i], &a[index]);
            index++;
            (*count)++;
        }
    }
    swap(&a[pivot], &a[index]);
    (*count)++;
    return index;
}

void quicksort(int *a, int first, int last, int n, int *count) {
    if (first < last) {
        int p = partition(a, first, last, n, count);
        quicksort(a, first, p - 1, n, count);
        quicksort(a, p + 1, last, n, count);
    }
}

void insertion_sort(int *a, int n, int *count) {
    for (int i = 1; i < n; i++) {
        for (int j = i; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                swap(&a[j - 1], &a[j]);
                (*count)++;
            }
        }
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int a[n], b[n], i;
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    int quick_count = 0, insertion_count = 0;
    quicksort(a, 0, n - 1, n, &quick_count);
    insertion_sort(b, n, &insertion_count);
    printf("%d\n", insertion_count - quick_count);
    return 0;
}
