#include <stdio.h>

/* 11498 - Division of Nlogonia
 Sample Input
 3
 2 1
 10 10
 -10 1
 0 33
 4
 -1000 -1000
 -1000 -1000
 0 0
 -2000 -10000
 -999 -1001
 0
 Sample Output
 NE
 divisa
 NO
 divisa
 NE
 SO
 SE
 */

int main() {

    int n, px, py, x, y;
    
    while (scanf("%d", &n) == 1 && n) {
        
        scanf("%d %d", &px, &py);
        
        while (n--) {
            
            scanf("%d %d", &x, &y);
            
            if (x == px || y == py)
                printf("divisa\n");
            else if (x < px && y > py)
                printf("NO\n");
            else if (x > px && y > py)
                printf("NE\n");
            else if (x > px && y < py)
                printf("SE\n");
            else if (x < px && y < py)
                printf("SO\n");
        }
    }
    return 0;
}

