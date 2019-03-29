#include <stdio.h>

/* Hackerrank: Mark and Toys
 find an integer that denotes maximum number of toys Mark can buy for his son.
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int first, int last) {

    int pivot = last;
    int i, index = first;

    for (i = first; i < last; i++) {
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

int main() {
    int i, money, n, price[100001];
    
    scanf("%d %d", &n, &money);
    
    for (i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    
    quicksort(price, 0, n - 1);
    
    int count = 0;
    i = 0;
    while (money) {
        if (money < price[i]) {
            break;
        }
        count++;
        money -= price[i];
        i++;
    }
    printf("%d\n", count);

    return 0;
}
