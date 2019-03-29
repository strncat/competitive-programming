#include <stdio.h>
#include <math.h>

/* 10879 - Code Refactoring
 Sample Input
 3
 120
 210
 10000000
 Sample Output
 Case #1: 120 = 12 * 10 = 6 * 20
 Case #2: 210 = 7 * 30 = 70 * 3
 Case #3: 10000000 = 10 * 1000000 = 100 * 100000
 */

void divisors(int n) {
    
    int i, st = sqrt(n), count = 0;
    
    for (i = 2; i <= st; i++)
        if (n % i == 0) {
            printf(" = %d * %d", n / i, i);
            count++;
            
            if (count == 2)
                break;
        }
}

int main() {
    
    int i, n, test_cases;
    
    scanf("%d", &test_cases);
    
    for (i = 1; i <= test_cases; i++) {
        
        scanf("%d", &n);
        printf("Case #%d: %d", i, n);
        divisors(n);
        printf("\n");
    }

    return 0;
}

