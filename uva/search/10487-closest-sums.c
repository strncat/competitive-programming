#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/* 10487 - Closest Sums
 find a sum of two distinct numbers from the set, which is closest to the query number
 Sample input
 5
 3
 12
 17
 33
 34
 3
 1
 51
 30
 3
 1
 2
 3
 3
 1
 2
 3
 3
 1
 2
 3
 3
 4
 5
 6
 0
 Sample output
 Case 1:
 Closest sum to 1 is 15.
 Closest sum to 51 is 51.
 Closest sum to 30 is 29.
 Case 2:
 Closest sum to 1 is 3.
 Closest sum to 2 is 3.
 Closest sum to 3 is 3.
 Case 3:
 Closest sum to 4 is 4.
 Closest sum to 5 is 5.
 Closest sum to 6 is 5.
 */

int main() {
    
    int i, j, k, n, a[10000], m, query, counter = 1, diff, sum, best;

    while (scanf("%d", &n) == 1 && n) {
        
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);
        
        scanf("%d", &m);
        
        printf("Case %d:\n", counter++);
        
        for (i = 0; i < m; i++) {
            
            scanf("%d", &query);
            
            diff = INT_MAX;
            
            for (j = 0; j < n; j++)
                for (k = j + 1; k < n; k++) {
                    sum = a[j] + a[k];
                    if (abs(sum - query) < diff) {
                        diff = abs(sum - query);
                        best = sum;
                    }
                }
            printf("Closest sum to %d is %d.\n", query, best);
        }
    }
    return 0;
}