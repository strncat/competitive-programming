#include <stdio.h>
#include <math.h>

/* MAX N = 1000000001 in Ternary = 2120200200021010002 */

int main() {
    
    long long int n; 
    int i=0, j=0, digits[20];
    
    while ((scanf("%lld", &n)) == 1) {
        
        if (n < 0)
            break;
        
        if (n==0)
            printf("0\n");
        else {
            i=0;
            while (n) {
                digits[i++] = n%3;
                n /= 3;
            }
        
            for (j=i-1; j>=0; j--)
                printf("%d", digits[j]);
            printf("\n");
        }
        
    }
    return 0;
}

