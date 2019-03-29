#include <stdio.h>
#include <math.h>

/* 11614 - Etruscan Warriors Never Play Chess
 
 http://oeis.org/A002024 The sequence 1, 3, 6, 10 ... can be generated using x = m (m + 1) / 2
 we are given x and we need to solve m^2 + m - 2x = 0 using the quadratic formula

 Sample Input
 6
 3
 6
 7
 8
 9
 10
 Sample Output
 2
 3
 3
 3
 3
 4
 */

int main() {
    
    int test_cases;
    double n;
    long long int m;

    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%lf", &n);
        
        /* solving m * (m + 1) / 2 = n using the quadratic formula */
    
        m = (long long int) (sqrt((n * 8) + 1) - 1) / 2;
        
        printf("%lld\n", m);
        
    }
    
    return 0;
}