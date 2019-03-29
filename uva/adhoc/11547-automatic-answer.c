#include <stdio.h>
#include <math.h>

/* 11547 - Automatic Answer
 INPUT
 2
 637
 -120
 
 OUTPUT
 1
 3
 
“Multiply n by 567, then divide the result by 9, then add 7492, then multiply by 235, 
 then divide by 47,then subtract 498. What is the digit in the tens column
 */
int main() {
    
    int cases, n;
    
    scanf("%d", &cases);
    
    while (cases--) {
        
        scanf("%d", &n);
    
        /* n = (n * 567 / 9 + 7492) * 235 / 47 - 498; */
        /* Simplify */
        n = (n * 63 + 7492) * 5 - 498;
        
        printf("%d\n", abs((n/10)%10));
    }
    return 0;
}