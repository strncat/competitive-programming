#include <stdio.h>

/* 12646 - Zero or One */

int main() {

    int a, b, c, sum;
    
    while (scanf("%d %d %d", &a, &b, &c) == 3) {
        
        sum = a + b + c;
        
        if (sum == 0 || sum == 3)
            printf("*\n");
        else if (sum == 1) {
            if (a)
                printf("A\n");
            else if (b)
                printf("B\n");
            else
                printf("C\n");
            
        }
        else { /* sum == 2 */
            if (!a)
                printf("A\n");
            else if (!b)
                printf("B\n");
            else
                printf("C\n");
        }
    }
    return 0;
}

