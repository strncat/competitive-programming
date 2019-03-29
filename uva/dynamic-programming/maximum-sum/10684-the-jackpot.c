#include <stdio.h>

/* 10684 - The jackpot
  N ≤ 10000, Integers ≤ 1000
 input: 
 5
 12 -4
 -10 4
 9
 3
 -2 -1 -2
 0
 The maximum winning streak is 13.
 Losing streak.
 */

#define N 10000
int a[N];

int kadane(int n) {
    
    int i, sum=0, max=0;
    
    for (i=0; i<n; i++) {
        sum += a[i];
        
        if (sum < 0)
            sum = 0;
        
        if (sum > max)
            max = sum;
    }
    return max;
}

int main() {
        
    int i, n, sum;
    
    while ((scanf("%d", &n) == 1) && n) {
        
        for (i=0; i<n; i++) 
            scanf("%d", &a[i]);
        
        sum = kadane(n);
        
        if (sum > 0)
            printf("The maximum winning streak is %d.\n", sum);
        else
            printf("Losing streak.\n");
    }
    return 0;
}
