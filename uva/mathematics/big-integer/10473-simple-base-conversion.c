#include <stdio.h>

/* 10473 - Simple Base Conversion
 Sample Input
 4
 7
 44
 0x80685
 -1
 Sample Output
 0x4
 0x7
 0x2C
 525957
*/

int main() {
    
    char n[100];
    int x;
        
    while (scanf("%s", n) == 1) {
        
        if (n[0] == '-')
            break;
        
        if (n[0] == '0' && n[1] == 'x') {
            sscanf(n, "%X", &x);
            printf("%d\n", x);
        }
        else {
            sscanf(n, "%d", &x);
            printf("0x%X\n", x);
        }
    }
    
    return 0;
}