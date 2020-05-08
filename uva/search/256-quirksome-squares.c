#include <stdio.h>
#include <math.h>

/* 256 - Quirksome Squares
 Sample Input
 2
 2
 Sample Output
 00
 01
 81
 00
 01
 81
 */

int main() {
    
    int i;
    long int squares[10000], n, max, a, b, sum, d;
    
    for(i = 0; i <= 10000; i++)
        squares[i] = i * i;

    
    while (scanf("%ld", &n) == 1) {
        
        max = pow(10, n) - 1;
        d = pow(10, n - n / 2);
        
        for (i = 0; squares[i] <= max; i++) {
        
            a = squares[i] % d; /* first n / 2 digits */
            b = squares[i] / d; /* remaining digits */
            sum = a + b;
          
            if (sum <= d && sum * sum == squares[i]) { /* sum has to be less than d to be considered */
                
                /* Padding */
                if (n == 2)
                    printf("%02ld\n", squares[i]);
                else if (n == 4)
                    printf("%04ld\n", squares[i]);
                else if (n == 6)
                    printf("%06ld\n", squares[i]);
                else if (n == 8)
                    printf("%08ld\n", squares[i]);
                
            }
        }
    }
    
    return 0;
}