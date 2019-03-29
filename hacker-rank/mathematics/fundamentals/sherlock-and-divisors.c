#include <stdio.h>
#include <math.h>

/* Sherlock and Divisors
Constraints
1 ? T ? 100
1 ? N ? 10^9
Sample Input
2
9
8
Sample Output
0
3
 */

int main() {
    
    int test_cases, divisors;
    long int x, limit;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%ld", &x);
        limit = sqrt(x);
        
        divisors = 0;
        for (int i = 1; i <= limit; i++) {
            if (x % i == 0) {
                if (i % 2 == 0) {
                    divisors++;
                }
                if (x / i != i && (x/i) % 2 == 0) {
                    divisors++;
                }
            }
        }
        printf("%d\n", divisors);
    }
    return 0;
}