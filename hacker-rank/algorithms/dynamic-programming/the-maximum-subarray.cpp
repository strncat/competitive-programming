//
//  The Maximum Subarray
//

#include <iostream>
#include <cstring>

int max_subarray(int *a, int n) {
    int sum = 0, max_sum = 0, negative = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum < 0) {
            sum = 0;
        }
        if (sum > max_sum) {
            max_sum = sum;
        }
        if (a[i] < 0) {
            negative++;
        }
    }
    if (negative == n) { // all elements are negative
        // find the max single element
        int max = -1000000000; // sloppy
        for (int i = 0; i < n; i++) {
            if (a[i] > max) {
                max = a[i];
            }
        }
        return max;
    }
    return max_sum;
}

int max_nonsubarray(int *a, int n) {
    int max_sum = 0, negative = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > 0) {
            max_sum += a[i];
        }
        if (a[i] < 0) {
            negative++;
        }
    }
    if (negative == n) { // all elements are negative
        // find the max single element
        int max = -1000000000; // sloppy
        for (int i = 0; i < n; i++) {
            if (a[i] > max) {
                max = a[i];
            }
        }
        return max;
    }

    return max_sum;
}

void tests() {
    int a[4] = {1,2,3,4};
    int sum = max_subarray(a, 4);
    int sum_nonsub = max_nonsubarray(a, 4);
    if (sum != 10 || sum_nonsub != 10) {
        printf("failed test sum = %d, sum_sub = %d\n", sum, sum_nonsub);
    }

    int b[6] = {2,-1,2,3,4,-5};
    sum = max_subarray(b, 6);
    sum_nonsub = max_nonsubarray(b, 6);
    if (sum != 10 || sum_nonsub != 11) {
        printf("failed test sum = %d, sum_sub = %d\n", sum, sum_nonsub);
    }

    int c[3] = {-2,-1,-5};
    sum = max_subarray(c, 3);
    sum_nonsub = max_nonsubarray(c, 3);
    if (sum != -1 || sum_nonsub != -1) {
        printf("failed test sum = %d, sum_sub = %d\n", sum, sum_nonsub);
    }
}


int main() {
    tests();
    int cases, n, a[100001];
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        std::cout << max_subarray(a, n) << " " << max_nonsubarray(a, n) << std::endl;
    }
    return 0;
}
