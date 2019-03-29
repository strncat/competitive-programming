#include <stdio.h>

/* 10919 - Prerequisites?
 Sample Input
 3 2
 0123 9876 2222
 2 1 8888 2222
 3 2 9876 2222 7654
 3 2
 0123 9876 2222
 2 2 8888 2222
 3 2 7654 9876 2222
 0
 Output for Sample Input
 yes
 no
 */

int main() {
    
    int i, j, k, total, courses, categories, course[100], required, minimum[100], fail = 0;
    
    while (scanf("%d", &courses) == 1) {
        
        if (courses == 0)
            break;
        
        scanf("%d", &categories);
        
        for (i = 0; i < courses; i++)
            scanf("%d", &course[i]);
        
        /* Each Category */
        for (i = 0; i < categories; i++) {
            
            scanf("%d", &total);
            scanf("%d", &minimum[i]);
        
            /* For Each Required Course */
            for (j = 0; j < total; j++) {
                
                scanf("%d", &required);
                
                /* Did Freddie Take It? */
                for (k = 0; k < courses; k++)
                    if (course[k] == required)
                        minimum[i]--;
            }
        }
        fail = 0;
        for (i = 0; i < categories; i++)
            if (minimum[i] > 0)
                fail = 1;
        
        if (fail)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
