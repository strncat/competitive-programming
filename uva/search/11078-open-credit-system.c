#include <stdio.h>

/* 
11078 - Open Credit System
 Sample Input
 3
 
 2
 
 100
 
 20
 
 4
 
 4
 
 3
 
 2
 
 1
 4
 1
 2
 3
 4
 Output for Sample Input
 80
 3
 -1
*/

int main() {
    
    int i, n, difference, max_score, score, test_cases;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &n);
    
        scanf("%d", &max_score);
        scanf("%d", &score);
        
        difference = max_score - score;
        
        if (score > max_score)
            max_score = score;
        
        /* keep track of the maximum score */
        for (i = 2; i < n; i++) {
            
            scanf("%d", &score);
            
            if (max_score - score > difference)
                difference = max_score - score;
            
            if (score > max_score)
                max_score = score;
        }
        printf("%d\n", difference);
    }
    return 0;
}