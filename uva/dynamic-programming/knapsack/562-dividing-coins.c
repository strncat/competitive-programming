#include <stdio.h>

/* 562 - Dividing coins
 Knapsack! see http://nemo.la/?p=560
 Sample Input
 6
 3
 2 3 5
 4
 1 2 4 6
 4
 1 9 990 10
 7
 2 48 48 49 49 50 50
 13
 1 4 6 8 5 3 4 7 5 3 5 2 100
 10
 500 499 500 488 467 500 499 488 499 487
 Sample Output
 0
 1
 970
 47
 0
 1
 */

#define N 500
#define M 60000
#define maximum(a, b) a > b ? a : b

int weight[N];
int cost[N];
int K[N + 1][M + 1];

int knapsack(int W, int n) {
    int i, w;
    
    for (i = 0; i <= n; i++)
        K[i][0] = 0;
    
    for (w = 0; w <= W; w++)
        K[0][w] = 0;
    
    for (i = 1; i <= n; i++) {
        for (w = 1; w <= W; w++) {
            
            if (weight[i - 1] <= w)
                K[i][w] = maximum(cost[i - 1] + K[i - 1][w - weight[i - 1]],  K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {

    int i, test_cases, n, total, max;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &n);
        
        total = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &weight[i]);
            cost[i] = weight[i];
            total += weight[i];
        }
        
        max = knapsack(total / 2, n); /* total - max is what the other guy recieved */
        
        printf("%d\n", total - 2 * max);
    }
    
    return 0;
}