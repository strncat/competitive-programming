#include <stdio.h>

/* 12468 - Zapping
input
3 9
0 99
12 27
-1 -1
Output
6
1
15
 got so many runtime erros because I forgot return 0;
*/

int main() {

    int a, b, diff;
    
    while(scanf("%d %d", &a, &b) == 2) {
        
        if (a == -1 && b == -1)
            break;
        
        diff = (b - a > 0) ? b - a : a - b;
        
        if (diff <= 50)
            printf("%d\n", diff);
        else
            printf("%d\n", (99 - diff) + 1);
    }
    
    return 0;
}

