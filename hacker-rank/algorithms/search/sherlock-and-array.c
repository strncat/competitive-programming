#include <stdio.h>

// May 2014 Hack 101
// Sherlock Challenge

int main() {

    int test_cases, i, n, a[100000], left_sum, right_sum, yes;
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &n);
        
        left_sum = right_sum = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            right_sum += a[i];
        }
        yes = 0;
        for (i = 0; i < n; i++) {
            right_sum -= a[i];
            if (left_sum == right_sum) {
                printf("YES\n");
                yes = 1;
                break;
            }
            left_sum += a[i];
        }
        if (yes == 0) {
            printf("NO\n");
        }
    }
    
    return 0;
}

