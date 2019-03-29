#include <stdio.h>

/* 12279 - Emoogle Balance
 Sample Input
 
 5
 3 4 0 0 1
 4
 2 0 0 0
 7
 1 2 3 4 5 0 0
 0
 Sample Output
 
 Case 1: 1
 Case 2: -2
 Case 3: 3
 */

int main() {
    
    int N, value, counter=1;
    int treat=0, party=0;
    
    while(scanf("%d", &N) && N != 0) {
        
        treat = 0;
        party = 0;
        
        while(N--) {
            
            scanf("%d", &value);
            
            if (value == 0)
                treat++;
            else
                party++;
            
        }
        printf("Case %d: %d\n", counter++, (party-treat));
    }
    return 0;
}