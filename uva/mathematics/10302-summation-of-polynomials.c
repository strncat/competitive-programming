#include <stdio.h>

int main() {
    
    long long int n=0, sum=0;
    
    /* The sum of consecutive cubes from 1³ to n³ is the square of the nth triangular number. That is,
     S₃(n) = n²(n+1)²/4 = [n(n+1)/2]² = [T(n)]² */
    
    while(scanf("%lld",&n)==1) {
        
        sum = ((n*n) * (n+1)*(n+1)) / 4;
        
        printf("%lld\n", sum);
    }
    
    return 0;
}