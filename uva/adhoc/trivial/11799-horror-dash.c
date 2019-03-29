#include <stdio.h>

/*  12015 - Google is Feeling Lucky

 Sample Input
 2
 5 9 3 5 2 6
 1 2
 
 Sample Output
 Case 1: 9
 Case 2: 2
*/

int main() {
    
    int i=0, cases, counter, max=0, total;
    int speed[100];
    
    scanf("%d", &cases);
    
    for (counter=1; counter<=cases; counter++) {
        
        scanf("%d", &total);
        
        max = 0;
        for (i=0; i<total; i++) {
            scanf("%d", &speed[i]);
            
            if (speed[i] > max)
                max = speed[i];
        }
        printf("Case %d: %d\n", counter, max);
    }
    return 0;
}