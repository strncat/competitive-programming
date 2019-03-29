#include <stdio.h>

/* UVa - [11247 - Income Tax]
 Sample Input 
 20 10
 2300 4
 100 1
 2345235 34
 1243214 34
 213123 45
 21313 5
 12432 65
 456456 54
 3452342 23
 36213 21
 324234 4
 35645555 4
 344 3
 23325 100
 0 0
 Output for Sample Input
 21
 2394
 Not found
 3553384
 1883656
 387494
 22433
 35517
 992293
 4483559
 45837
 337742
 37130785
 353
 Not found
*/
int main() {
    
    long long x, m, numerator, denominator, income;
    
    while (scanf("%lld %lld", &m, &x) == 2) {
        
        if (!m && !x)
            break;
        
        /* if tax is zero or 100% we won't find an income! */
        if (x == 100 || x == 0 || m == 1) {
            printf("Not found\n");
            continue;
        }
        
        numerator = ( (m - 1) * 100 );
        denominator = ( 100 - x );
        income = numerator / denominator;
        
        if (numerator % denominator == 0)
            income = income - 1;
            
        if (income < m)
            printf("Not found\n");
        else
            printf("%lld\n" , income);
    }
    return 0;
}
