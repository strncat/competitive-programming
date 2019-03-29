#include <stdio.h>

/* UVa [11150 - Cola]
Sample Input / Output
 1 => 1
 2 => 3
 3 => 4
 4 => 6
 5 => 7
 6 => 9
 7 => 10
 8 => 12
 9 => 13
 10 => 15
 15 => 22
 20 => 30
 30 => 45
 40 => 60
 50 => 75
 100 => 150
 150 => 225
 190 => 285
 199 => 298
 200 => 300
*/

int bottles(int full, int borrowed) {
    
    int total = full; /* initially, I drink all the full bottles */
    int empty = borrowed; /* initially, used bottles are only those borrowed ones */
    int reuse = full+empty; /* bottles I can re-use */
    
    while (reuse > 2) {
        empty = reuse%3; /* empty bottles I can't re-use */
        total += reuse/3; /* additional bottles to drink */
        reuse = reuse/3 + reuse%3;
    }
    
    empty += reuse;
    
    /* If I can't return the borrowed ones, result is invalid */
    if (borrowed > empty)
        total = -1;
    
    return total;
}

int main() {
    
    int x, max, total, i;
    
    while (scanf("%d", &x) == 1) {
        
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
