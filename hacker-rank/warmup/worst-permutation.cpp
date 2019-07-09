//
//  main.cpp
//  weekly-challenge
//  https://www.hackerrank.com/contests/w14/challenges/worst-permutation
//  The worst permutation is just the largest number
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

int main() {
    int swaps = 0, n, k, a[10000], index = 0;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // at most k swaps
    while (swaps < k && index < n) {

        // find the largest number, starting at index
        for (int j = index; j < n; j++) {

            // we found the largest but it's not in its right position
            if (a[j] == n - index && j != index) {
                swap(&a[j], &a[index]);
                swaps++;
                break;
            }
        }
        // either we found the largest and we swapped or the largest was just in its right position
        // either way we should increment index
        index++;
    }
    print(a, n);
    //printf("%d\n", swaps);
    return 0;
}
