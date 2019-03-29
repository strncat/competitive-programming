#include <stdio.h>

/* UVa [11877 - The Coco-Cola Store]
 Sample Input
 3
 10
 81
 0
 Sample Output
 1
 5
 40 */
/* I just reused my code from the other cola problem 11050? */

int bottles(int full, int borrowed) {
    
    int total = 0; /* initially, I drink all the full bottles */
    int empty = borrowed; /* initially, used bottles are only those borrowed ones */
    int reuse = full+empty; /* bottles I can re-use */
    
    while (reuse > 2) {
        empty = reuse%3; /* empty bottles I can't re-use */
        total += reuse/3; /* additional bottles to drink */
        reuse = reuse/3 + reuse%3;
    }
    
    empty = reuse;
    
    /* If I can't return the borrowed ones, result is invalid */
    if (borrowed > empty)
        total = -1;
    
    return total;
}

int main() {
    
    int x, max, total, i;
    
    while (scanf("%d", &x) == 1 && x) {
        
        max = bottles(x, 0);
        
        /* try to borrow one or two */
        for (i = 1; i < 3; i++) {
            total = bottles(x, i);
            
            if (total > max)
                max = total;
        }
        printf("%d\n", max);
    }
    return 0;
}
