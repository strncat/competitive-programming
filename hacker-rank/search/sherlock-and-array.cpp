//
//  Sherlock and Array
//  determine if there exists an element in the array such
//  that the sum of the elements on its left is equal to
//  the sum of the elements on its righ
//

#include <iostream>
#include <string>
#include <math.h>

int balanced(int *a, int n) {
    int left_sum = 0, right_sum = 0;
    int i = 0, j = n - 1;
    while (i < j) {
        if (left_sum < right_sum) {
            left_sum += a[i++];
        } else {
            right_sum += a[j--];
        }
    }
    if (left_sum == right_sum) {
        return 1;
    }
    return 0;
}
//2 2 5 2 2
//2 2 2 2

int main() {
    int cases, n, a[100001];
    std::string s;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        if (balanced(a, n)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
