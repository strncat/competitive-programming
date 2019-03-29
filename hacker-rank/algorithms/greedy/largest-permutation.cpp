//
//  Hacker Rank
//  Largest Permutation
//
//  Created by Fatima B on 01/01/16.
//  Copyright © 2015 Fatima B. All rights reserved.


#include <iostream>
#include <algorithm>
#include <limits.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, k, a[1000002], index[1000002];
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        index[a[i]] = i; // record the index of each element
    }

    int swaps = 0;
    for (int i = 0; i < n; i++) {
        if (swaps == k) { break; }

        if (a[i] == n-i) { // a[i] doesn't need to be swapped
            continue;
        }
        // we need to swap n-i with the current a[i]
        int new_index = index[n-i]; // we find its index
        swap(&index[a[i]], &index[n-i]);
        swap(&a[new_index], &a[i]);
        swaps++;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
