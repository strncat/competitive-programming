#include <stdio.h>

/*  374 - Big Mod

 Sample Input
 3
 18132
 17
 
 17
 1765
 3
 
 2374859
 3029382
 36123
 
 2147483647
 2147483647
 46340

 Sample Output
 
 13
 2
 13195
 13903

*/

int  mod (int b, int p, int m) {
    int result;
    
    if (p == 0)
        return 1;
    
    if (p % 2 == 1)
        return ((b % m) * (mod (b, p-1, m ))) % m;

    else {
        result = mod (b, p/2, m);
        return ((result % m) * (result % m)) % m;
    }
}

int main() {
    
    int b, p, m;
    
    while(scanf("%d %d %d",&b, &p, &m) == 3) {
        printf("%d\n",mod(b,p,m));
    }
    return 0;
}