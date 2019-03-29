#include <stdio.h>

/* 11093 - Just Finish it up
SAMPLE INPUT:
8
5
1 1 1 1 1
1 1 2 1 1
7
1 1 1 10 1 1 1
2 2 2 2 2 2 2
9
1 3 1 4 2 1 2 3 2
2 2 1 3 1 3 1 1 1
5
2 6 7 1 1
3 7 1 1 1
6
1 8 9 6 4 1
9 1 1 2 3 2
7
13 1 2 1 3 1 2
1 2 3 1 14 3 1
6
1 2 3 4 1 4
12 3 2 1 2 1
5
3 4 4 5 6
2 1 1 14 1
SAMPLE OUTPUT:
Case 1: Not possible
Case 2: Possible from station 4
Case 3: Possible from station 2
Case 4: Possible from station 3
Case 5: Possible from station 2
Case 6: Not possible
Case 7: Not possible
Case 8: Possible from station 5
*/

int main() {
    
    int i, j, k, T, N, p[100001], q[100001], success, need, have, sum, required, total;
    
    scanf("%d", &T);
    
    for(i = 1; i <= T; i++) {
        
        success = 0;
        sum = 0;
        required = 0;
        scanf("%d", &N);

        for (j = 0; j < N; j++) {
            scanf("%d", &p[j]);
            sum += p[j];
        }
        
        for (j = 0; j < N; j++) {
            scanf("%d", &q[j]);
            required += q[j];
        }
        
        if (sum >= required) {
        
            for (j = 0; j < N; j++) {
                
                /* start station is j */

                if (p[j] < q[j]) /* not possible */
                    continue;
                
                total = 0;
                
                for (k = 0; k < N; k++) {
                    
                    need = (k + j) % N;
                    have = (k + j) % N;
                    
                    if (p[have] + total < q[need]) /* not possible from this station */
                        break;

                    else
                        total += (p[have] - q[need]);
                }
                if (k == N) { /* was able to succeed, break */
                    success = 1;
                    break;
                }
            }
        }
        printf("Case %d: ", i);
        
        if (success)
            printf("Possible from station %d\n", j + 1);
        else
            printf("Not possible\n");
    }
    return 0;
}