#include <stdio.h>

/* UVa - [11805 - Bafana Bafana]
 Sample Input
 3
 5 2 5
 6 3 5
 4 1 3
 Sample Output
 Case 1: 2
 Case 2: 2
 Case 3: 4
*/
int main() {
    
    int cases, counter, N, starting_player, passes, last_player;
    
    scanf("%d", &cases);
    
    for (counter=1; counter<=cases; counter++) {
        
        scanf("%d %d %d", &N, &starting_player, &passes);
        
        last_player = (starting_player + passes) % N;
        
        if (last_player)
            printf("Case %d: %d\n", counter, last_player);
        else
            printf("Case %d: %d\n", counter, N);
    }
    return 0;
}
