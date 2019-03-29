#include <stdio.h>
#include <limits.h>
#include <string.h>

/* 11517 - Exact Change
 Sample Input
 3
 1400
 3
 500
 1000
 2000
 
 10000
 2
 9999
 9999
 
 13 5
 9 5 2 3 3

 Output for Sample Input
 1500 2
 19998 2
 13 4
 */

#define N 100001 /* The price will not exceed, 10 000 */
#define M 101 /* The number n is at most 100 */
#define minimum(a, b) a < b ? a : b

int main() {
    
    int test_cases, i, j, amount, n, coin[M], max_coin, f[N];
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        for (i = 1; i < N; i++)
            f[i] = INT_MAX - 1;
        f[0] = 0;
        
        scanf("%d", &amount);
        
        scanf("%d", &n); /* number of bills */
        
        for (i = 0; i < n; i++) {
            scanf("%d", &coin[i]);
            if (coin[i] > max_coin)
                max_coin = coin[i];
        }
        
        for (i = 0; i < n; i++) { /* for each coin */
            
            for (j = (max_coin + amount); j >= coin[i]; j--) { /* can make change with it for all amount = j? */
                
                if (f[j] > f[j - coin[i]] + 1)
                    f[j] = f[j - coin[i]] + 1;
            }
        }
        
        for (j = amount; j <= max_coin + amount; j++)
            if (f[j] < INT_MAX - 1) {
                printf("%d %d\n", j, f[j]);
                break;
            }
    }
    return 0;
}