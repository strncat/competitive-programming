#include <stdio.h>

/* 10019 - Funny Encryption Method
 Sample Input
 3
 265
 111
 1234
 Sample Output
 3 5
 6 3 
 5 5
 */

int main() {
    
    long int test_cases, n, m, b1, b2, d, dec;
    
    scanf("%ld", &test_cases);
    
    while (test_cases--) {
        
        b1 = 0;
        b2 = 0;
        
        scanf("%ld", &n);
        m = n;
        
        /* decimal to binary */
        while (n > 0) {
            if (n % 2 == 1)
                b1++;
            n /= 2;
        }
        
        /* hex to decimal */
        d = 1;
        dec = 0;
        while (m > 0) {
            dec += (m % 10) * d;
            m /= 10;
            d *= 16;
        }
        
        /* decimal to binary */
        b2 = 0;
        while (dec > 0) {
            if (dec % 2 == 1)
                b2++;
            dec /= 2;
        }
        
        printf("%ld %ld\n", b1, b2);
    }
}