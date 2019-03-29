#include <stdio.h>

/* 11764 - Jumping Mario
 input:
 3
 8
 1 4 2 2 3 5 3 4
 1
 9
 5
 1 2 3 4 5
 output:
 Case 1: 4 2
 Case 2: 0 0
 Case 3: 4 0
*/

int main() {

    int test_cases, N, i, k, high, low, previous, current;
    
    scanf("%d", &test_cases);
    
    for (i = 1; i <= test_cases; i++) {
        
        scanf("%d", &N);
        
        scanf("%d", &previous);
        
        high = 0;
        low = 0;
        for (k = 0; k < N - 1; k++) {
            
            scanf("%d", &current);
            
            if (previous < current)
                high++;
            else if (previous > current)
                low++;
            
            previous = current;
        }
        printf("Case %d: %d %d\n", i, high, low);
    }
    return 0;
}