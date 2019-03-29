#include <stdio.h>
#include <string.h>
/*
 12372 - Packing for Holiday
 Sample Input                                
 2
 20 20 20
 1 2 21
 Sample Output
 Case 1: good
 Case 2: bad
*/
int main() {
    
    int cases, i, L, W, H;
    
    scanf("%d", &cases);
    
    for (i=1; i<=cases; i++) {
        scanf("%d %d %d", &L, &W, &H);
        
        if (L <= 20 && W <= 20 && H <= 20)
            printf("Case %d: good\n", i);
        else
            printf("Case %d: bad\n", i);
    }
    return 0;
}