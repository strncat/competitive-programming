//
// Project Euler #3: Largest prime factor
// Constraints 1 ≤ T ≤ 10, 10 ≤ N ≤ 10^12
// Sample Input
// 2
// 10
// 17
// Sample Output
// 5
// 17
//
#include <stdio.h>

unsigned long long int max_prime_factorization(unsigned long long int n) {
    unsigned long long int max = 1, i;
    while (n % 2 == 0) {
        n /= 2;
        if (2 > max) {
            max = 2;
        }
    }
    for (i = 3; i * i <= n; i+=2) {
        while (n % i == 0) {
            if (i > max)
                max = i;
            n /= i;
        }
    }
    if (n > 2 && n > max) {
        max = n;
    }
    return max;
}

int main() {
    int test_cases;
    unsigned long long int value, max;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        scanf("%llu", &value);
        max = max_prime_factorization(value);
        printf("%llu\n", max);
    }
    return 0;
}
