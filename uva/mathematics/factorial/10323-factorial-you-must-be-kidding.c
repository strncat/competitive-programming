#include <stdio.h>

/* 10323 - Factorial! You Must be Kidding!!!
10000 <= Factorial <= 6227020800
 Sample Input
 2
 10
 100
 Sample Output
 Underflow!
 3628800
 Overflow!
 
 look here: http://www.algorithmist.com/index.php/UVa_10323
 I keep getting WA when I compute the factorial, now precomputed
*/

int factorial(int n) { /* Not needed anymore */
    
    int f=1, i;
    
    for (i=1; i<=n; i++)
        f = f * i;
        
    return f;
}

int main() {
    
    int n;
    
    while (scanf("%d", &n) == 1) {
        
        if( (n >= 0 && n <= 7) || (n < 0 && n%2 == 0))
            printf("Underflow!\n");
        
        else if (n == 8)
            printf("40320\n");
        
        else if (n == 9)
            printf("362880\n");
        
        else if (n == 10)
            printf("3628800\n");
        
        else if (n == 11)
            printf("39916800\n");
        
        else if (n == 12)
            printf("479001600\n");
        
        else if (n == 13)
            printf("6227020800\n");
        
        else
            printf("Overflow!\n");

    }
    return 0;
}