#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/* 10931 - Parity
 Sample Input
 1
 2
 10
 21
 0
 Sample Output
 The parity of 1 is 1 (mod 2).
 The parity of 10 is 1 (mod 2).
 The parity of 1010 is 2 (mod 2).
 The parity of 10101 is 3 (mod 2).
 */

int main() {
    
    int i, k, n, parity, a[32];
    
    while (scanf("%d", &n) == 1 && n) {
        
        parity = 0;
        i = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                parity++;
                a[i++] = 1;
            }
            else
                a[i++] = 0;
            n /= 2;
        }
        
        printf("The parity of ");
        for (k = i - 1; k >= 0; k--)
            printf("%d", a[k]);
        printf(" is %d (mod 2).\n", parity);
        
    }
    
    return 0;
}