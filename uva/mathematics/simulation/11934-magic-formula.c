#include <stdio.h>
#include <string.h>

/* 11934 - Magic Formula
Sample Input
0 0 10 5 100
0 0 10 6 100
1 2 3 4 5
1 2 3 3 5
0 0 0 0 0
Sample Output
101
0
0
4
*/

int main() {
    
    int a, b, c, d, L; /* a b c d L ( -1000 <= a, b, c <= 1000, 1 < d < 1000000, 0 <= L <= 1000) */
    int i, count;
    
    /* f (n) = a x 2 + b x + c */
    
    while (scanf("%d %d %d %d %d", &a, &b, &c, &d, &L) == 5) {
        
        if (a == 0 && b == 0 && c == 0 && d == 0 && L == 0)
            break;
        
        count = 0;
        
        for (i = 0; i <= L; i++)
            if ((a * i * i + b * i + c) % d == 0)
                count++;
        
        printf("%d\n", count);
        
    }
    return 0;
}