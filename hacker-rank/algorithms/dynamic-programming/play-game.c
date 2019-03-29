#include <stdio.h>

/* Play Game
Constraints
1 ≤ T ≤ 5
1 ≤ N ≤ 10^5
0 ≤ each number on brick ≤ 10^9
Sample Input
2
5
999 1 1 1 0
5
0 1 1 1 999
Sample Output
1001
999
*/

int main() {
    
    int test_cases;
    long long int max, i, n, dp[100009], a[100009], sum[100009];
    
    scanf("%d", &test_cases);
    
    while(test_cases--) {
        
        scanf("%lld", &n);
        
        a[0] = 0;
        for (i = n; i >= 1; i--) {
            scanf("%lld", &a[i]);
        }
        
        sum[0] = 0;
        for (i = 1; i <= n; i++) {
            sum[i] = sum[i - 1] + a[i];
        }
        
        dp[0] = 0;
        dp[1] = a[1];
        dp[2] = a[1] + a[2];
        dp[3] = a[1] + a[2] + a[3];
        
        for (i = 4; i <= n; i++) {
            
            dp[i] = a[i] + (sum[i - 1] - dp[i - 1]);
            
            max = a[i] + a[i - 1] + (sum[i - 2] - dp[i - 2]);
            if (max > dp[i])
                dp[i] = max;
            
            max = a[i] + a[i - 1] + a[i - 2] + (sum[i - 3] - dp[i - 3]);
            if (max > dp[i])
                dp[i] = max;
        }
        printf("%lld\n", dp[n]);
    }
    return 0;
}
