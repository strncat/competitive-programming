#include <stdio.h>

/* HackerRank - John and GCD list */

long int gcd(long int a, long int b) {
    while (b != 0)
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    return a;
}

long int lcm(long int a, long int b) {
    return b * a / gcd(a, b);
}

int main() {

    int test_cases, n, i, a[1000];
    long int b[10001];
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &n);
        
        for (i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        b[0] = a[0];
        b[n] = a[n - 1];
        
        for (i = 1; i < n; i++) {
            b[i] = lcm(a[i - 1], a[i]);
        }
        
        for (i = 0; i <= n; i++) {
            printf("%ld ", b[i]);
        }
        printf("\n");
        
    }
    return 0;
}

