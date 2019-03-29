#include <stdio.h>

/* 369 - Combinations
 5 <= N <= 100, 5 <= M <= 100
 Sample Input
 100  6
 20  5
 18  6
 0  0
 Sample Output
 100 things taken 6 at a time is 1192052400 exactly.
 20 things taken 5 at a time is 15504 exactly.
 18 things taken 6 at a time is 18564 exactly.
 */

long int Bionomial(int n, int k) {
    
    int i;
    
    if (n-k < k)
        k = n-k;
    
    long result = 1;
    
    for (i = 1; i <= k; i++) {
        result = result * (n - k + i) / i;
    }
    
    return result;
}

int main() {
    
    int n, m;
    
    while (scanf("%d  %d", &n, &m) == 2) {
        
        if (!n && !m)
            break;
        
        printf("%d things taken %d at a time is %ld exactly.\n", n, m, Bionomial(n, m));
        
    }
    return 0;
}