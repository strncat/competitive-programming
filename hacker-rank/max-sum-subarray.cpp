//
//  Hacker Rank
//  Max-Sum-Subarray
//
//  Created by Fatima B on 1/20/16.
//  Copyright © 2016 Fatima B. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <string.h>
#include <limits.h>

int max_subarray(int *a, int n) {
    int current_sum = 0;
    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        current_sum += a[i];
        if (current_sum < 0 || a[i] == 0) {
            current_sum = 0;
        }
        if (max < current_sum) {
            max = current_sum;
        }
    }
    return max;
}

int main() {
    int n, a[100001];
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("%d\n", max_subarray(a, n));
    return 0;
}
