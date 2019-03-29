#include <stdio.h>

/* UVa - [11455 - Behold my quadrangle]
 Sample Input
 4
 10 8 7 6
 9 1 9 1
 29 29 29 29
 5 12 30 7
 Sample Output
 quadrangle
 rectangle
 square
 banana
*/
int main() {
    
    int cases, a, b, c, d;
    
    scanf("%d", &cases);
    
    while (cases--) {
        
        scanf("%d %d %d %d", &a, &b, &c, &d);
        
        if ((a == b) && (b == c) && (c == d))
            printf("square\n");
        else if ((a == b && c == d) || (b == c && a == d) || (a == c && b == d))
            printf("rectangle\n");
        else if ( (a+b+c < d) || (b+c+d < a) || (c+d+a < b) || (a+b+d < c) )
            printf("banana\n");
        else
            printf("quadrangle\n");
    }
    return 0;
}
