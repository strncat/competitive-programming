#include <stdio.h>

/* 11559 - Event Planning
 Sample Input
 3 1000 2 3
 200
 0 2 2
 300
 27 3 20
 5 2000 2 4
 300
 4 3 0 4
 450
 7 8 0 13
 Sample Output
 900
 stay home
*/

int main() {

    int N, budget, hotels, weeks, price, beds, min, i, k;

    while (scanf("%d %d %d %d", &N, &budget, &hotels, &weeks) != EOF) {
  
        min = budget + 1; /* the maximum amount possible + 1 */
     
        for (i = 0; i < hotels; i++) { /* for each hotel */
            
            scanf("%d", &price);
            
            for (k = 0; k < weeks; k++) {
                scanf("%d", &beds);
                
                if (beds >= N && (price * N <= min)) {
                    min = price * N;
                }
            }
        }
        if (min <= budget)
            printf("%d\n", min);
        else
            printf("stay home\n");
    }
    return 0;
}