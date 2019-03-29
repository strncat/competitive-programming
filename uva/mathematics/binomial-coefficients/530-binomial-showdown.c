#include <stdio.h>

/* 530 - Binomial Showdown
 Sample Input
 4 2
 10 5
 49 6
 0 0
 Sample Output
 6
 252
 13983816
 http://www.mathblog.dk/uva-530-binomial-showdown/
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
        
    int n, k;
    
    while (scanf("%d %d", &n, &k) == 2) {
        
        if (!n && !k)
            break;
        
        printf("%ld\n", Bionomial(n, k));
        
    }
    return 0;
}
