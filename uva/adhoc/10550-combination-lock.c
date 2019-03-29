#include <stdio.h>

/* 10550 - Combination Lock
 Sample Input
 3
 6 6
 7 7
 9 13
 Sample Output
 4
 4
 12

 */

int main() {

    int initial, first, second, third, total, temp;
    
    while (scanf("%d %d %d %d", &initial, &first, &second, &third) == 4) {
       
        if (initial == 0 && first == 0 && second == 0 && third == 0)
            break;
        
        total = 0;
        
        /* 3 full turns in total */
        total += 1080;
        
        /* initial to first number is clock wise: initial - first (not the opposite) */
        
        temp = (initial - first) * 9; /* 9 * 40 = 360 degrees */
        
        total += ( temp ) > 0 ? temp : temp + 360;
        
        temp = (second - first) * 9; /* the second number is counter clockwise: second - first */
        
        total += ( temp ) > 0 ? temp : temp + 360;

        temp = (second - third) * 9; /* clockwise */
        
        total += ( temp ) > 0 ? temp : temp + 360;
        
        printf("%d\n", total);
        
    }
    
    return 0;
}

