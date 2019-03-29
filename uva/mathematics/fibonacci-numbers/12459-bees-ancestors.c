#include <stdio.h>

/* 12459 - Bees' ancestors
 Sample Input
 1
 2
 3
 0
 Sample Output
 1
 2
 3
*/

long int f[82];

void fb() {
    
    int i;
    
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    
    for (i = 3; i < 82; i++)
        f[i] = f[i - 1] + f[i - 2];
}

int main() {

    int n;
    
    fb();
    
    while (scanf("%d", &n) == 1) {
       
        if (n == 0)
            break;
        printf("%ld\n", f[n + 1]);
    }
    return 0;
}