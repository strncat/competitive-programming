//
// Project Euler #1: Multiples of 3 and 5
// Constraints 1 ≤ T ≤ 10^5, 1 ≤ N ≤ 10^9
/* Sample Input
 2
 10
 100
 Sample Output
 23
 2318
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int test_cases, n;
    unsigned long long int factors, triangular_number, sum, sum_3, sum_5, sum_15;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        scanf("%d", &n);
        n = n - 1;
        
        factors = n / 5;
        triangular_number = factors * (factors + 1) / 2;
        sum_5 = triangular_number * 5;
        
        factors = n / 3;
        triangular_number = factors * (factors + 1) / 2;
        sum_3 = triangular_number * 3;
        
        factors = n / 15;
        triangular_number = factors * (factors + 1) / 2;
        sum_15 = triangular_number * 15;
        
        sum = sum_5 + sum_3 - sum_15;
        
        printf("%llu\n", sum);
    }
    return 0;
}
