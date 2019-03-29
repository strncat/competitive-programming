#include <stdio.h>

/* UVa [834 - Continued Fractions]
 Read This First: http://www.jcu.edu/math/vignettes/continued.htm
 
 Sample Input
 43 19
 1 2
 Sample Output
 [2;3,1,4]
 [0;2]
*/
int main() {
    
    int a, b, fractions[1000], quotient, remainder, n, i;
    
    while (scanf("%d %d", &a, &b) == 2) {
        
        n = 0;
        do {
            quotient = a/b;
            remainder = a%b;
            fractions[n++] = quotient;
            a = b;
            b = remainder;
        } while (remainder > 0);
        
        printf("[%d;", fractions[0]);
        for (i = 1; i < n-1; i++) {
            printf("%d,", fractions[i]);
        }
        printf("%d]\n", fractions[n-1]);
    }
    
    
    return 0;
}
