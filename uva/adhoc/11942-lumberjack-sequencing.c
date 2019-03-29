#include <stdio.h>

/* 11942 - Lumberjack Sequencing
Sample Input
 3
 13 25 39 40 55 62 68 77 88 95
 88 62 77 20 40 10 99 56 45 36
 91 78 61 59 54 49 43 33 26 18
 Sample Output
 Lumberjacks:
 Ordered
 Unordered
 Ordered
*/

int main() {

    int test_cases, i, desc, ascn, previous, current;
    
    printf("Lumberjacks:\n");
    
    scanf("%d", &test_cases);

    while (test_cases--) {
        
        desc = 0;
        ascn = 0;
        
        scanf("%d", &previous);
        
        for (i = 1; i < 10; i++) {
            
            scanf("%d", &current);
            
            if (previous < current)
                ascn++;
            else if (previous > current)
                desc++;
            
            previous = current;
        }
        if (ascn == 9 || desc == 9)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
    return 0;
}