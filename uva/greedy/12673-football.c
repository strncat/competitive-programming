#include <stdio.h>
#include <string.h>

/* 12673 - Football
 Sample Input 2 1 1 1 1 1 3 2 1 3 3 1 2 2 4 10 1 1 2 2 1 3 0 4
 2 2
 1 1
 1 2
 5 5
 1 5
 1 1
 1 1
 1 1
 1 1 Sample Output 4 6 12
 4
 12
*/

int main() {

    int i, goals, matches, scored, recieved, lost[101], result;
    
    while (scanf("%d %d", &matches, &goals) == 2) {
        
        memset(lost, 0, sizeof(lost));
        result = 0;
        
        for (i = 0; i < matches; i++) {
            
            scanf("%d %d", &scored, &recieved);
            
            if (scored - recieved > 0) /* wins will stay wins */
                result += 3;
            
            else if (scored == recieved) { /* tie */
                if (goals) {
                    result += 3; /* I can win it by one goal */
                    goals--;
                }
                else
                    result++;
            }
            else   /* save the lost games by goals difference */
                lost[recieved - scored]++; /* example lost 1 - 2, store lost[1]++ since I need 1 goal to tie or 2 to win */
        }
        if (goals > 0) { /* lost matches if some goals are still left */

             for (i = 1; i <= 101; i++) {
                 while (goals >= i && lost[i] > 0) {
                     if (goals > i) { /* can win */
                         result += 3;
                         goals -= i + 1;
                     }
                     else { /* can only tie */
                         result += 1;
                         goals -= i;
                     }
                     lost[i]--;
                 }
             }
        }
        printf("%d\n", result); /* no goals that can be used */
    }
    return 0;
}