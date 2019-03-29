#include <stdio.h>
#include <string.h>

/* 10130 - SuperSale
 Sample Input
 2
 3
 72 17
 44 23
 31 24
 1
 26
 6
 64 26
 85 22
 52 4
 99 18
 39 13
 54 9
 4
 23
 20
 20
 26
 Output for the Sample Input
 72
 514
*/

#define MAX 1000 /* 1 <= N <= 1000 */
#define MW 30 /* 1 <= MW <= 30 */
#define maximum(a, b) a > b ? a : b

int weight[MAX];
int price[MAX];
int K[MAX + 1][MAX + 1];

void build_knapsack(int N) {
    
    int n, w;
    
    memset(K, 0, sizeof(K));
    
    for (n = 1; n <= N; n++)
        for (w = 1; w <= MW; w++)
            if (weight[n - 1] <= w) /* index exists */
                K[n][w] = maximum (K[n - 1][w], price[n - 1] + K[n - 1][w - weight[n - 1]]);
            else
                K[n][w] = K[n - 1][w];
}

int main() {
    
    int test_cases, N, i, G, person[100], total;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &N);
    
        for (i = 0; i < N; i++) /* collect objects with their weights and prices */
            scanf("%d %d", &price[i], &weight[i]);
        
        build_knapsack(N);
        
        scanf("%d", &G);
        
        for (i = 0; i < G; i++) /* collect the people in the group */
            scanf("%d", &person[i]);
        
        total = 0;
        for (i = 0; i < G; i++)
            total += K[N][person[i]];
        
        printf("%d\n", total);
    }
    return 0;
}