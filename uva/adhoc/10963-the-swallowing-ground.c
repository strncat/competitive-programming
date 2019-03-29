#include <stdio.h>

/* 10963 - The Swallowing Ground
Sample Input
 1
 5
 2 1
 0 -1
 1 0
 1 0
 2 1
 Sample Output
 yes
 */

int main() {

    int test_cases, W, end, begin, previous, current, flag, newline = 0;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &W);
        
        scanf("%d %d", &end, &begin);
        previous = end - begin;
        W--;
        flag = 1;
        
        while (W--) {
            
            scanf("%d %d", &end, &begin);
            current = end - begin;
            if (previous != current) {
                flag = 0;
            }
        }
        
        if (newline)
            printf("\n");
        newline = 1;
        
        if (flag)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}

