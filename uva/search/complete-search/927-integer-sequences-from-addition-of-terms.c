#include <stdio.h>

/* Sample Input
 927 - Integer Sequences from Addition of Terms
 Sample Input
 2
 4 3 0 0 0 23
 25
 100
 1 0 1
 1
 6
 Sample Output
 1866
 3
*/

int main() {

    int test_cases, n, d, k, i, j, term, p[20];
    long long int total, power;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &n);
        
        for (i = 0; i <= n; i++) {
            scanf("%d", &p[i]);
        }
        
        scanf("%d", &d);
        scanf("%d", &k);
        
        term = 1;
        i = d;
        while (i < k) {
            term++;
            i += term * d;
        }
        
        total = 0;
        for (i = 0; i <= n; i++) {
            
            if (p[i] != 0) {
                
                /* calculate the power */
                power = 1;
                for (j = 0; j < i; j++)
                    power *= term;
                
                total += (p[i] * power);
            }
        }
        printf("%lld\n", total);
    }
    return 0;
}

