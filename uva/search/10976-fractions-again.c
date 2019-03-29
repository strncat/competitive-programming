
#include <stdio.h>

/* Sample Input
 10976 - Fractions Again?!
 Sample Input
 2
 12
 Sample Output
 
 2
 1/2 = 1/6 + 1/3
 1/2 = 1/4 + 1/4
 8
 1/12 = 1/156 + 1/13
 1/12 = 1/84 + 1/14
 1/12 = 1/60 + 1/15
 1/12 = 1/48 + 1/16
 1/12 = 1/36 + 1/18
 1/12 = 1/30 + 1/20
 1/12 = 1/28 + 1/21
 1/12 = 1/24 + 1/24
*/

/*
 
 1 / n + 1 / m = 1 / k
 
 m + n / m * n = 1 / k
 
 k * (m + n) = m * n
 
 k * m + k * n = m * n
 
 k * n = (m * n) - (k * m)
 
 k * n = m (n - k)
 
 m = (k * n) / (n - k)
*/

int main() {
    
    int k, n, total;
    
    while (scanf("%d", &k) == 1) {
    
        total = 0;
        
        for (n = k + 1; n <= 2 * k; n++)
            if ((n * k) % (n - k) == 0)
                total++;
        
        printf("%d\n", total);
        
        for(n = k + 1; n <= 2 * k; n++)
            if ((n * k) % (n - k) == 0)
                printf("%d/%d = %d/%d + %d/%d\n", 1, k, 1, (n * k) / (n - k), 1, n);
    }
    return 0;
}

