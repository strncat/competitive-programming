#include <stdio.h>
#include <string.h>

/* Divisibility of 11
 http://www.counton.org/explorer/primes/divisibility-tests-for-9-and-11/ */ 

int main() {
    
    char a[1000];
    int i, n, sum=0;
    
    while(scanf("%s",a) == 1) {
        
        if (a[0] == '0' && a[1] == '\0')
            break;
       
        sum = 0;
        n = (int)strlen(a);
        
        for (i=0; i<n; i++)
            printf("%c", a[i]);
        
        for (i=n-1; i>=0; i--)
            if (i%2 == 0)
                sum += a[i]-'0';
            else
                sum -= a[i]-'0';
        
        if (sum%11 == 0)
            printf(" is a multiple of 11.\n");
        else
            printf(" is not a multiple of 11.\n");
    }
    return 0;
}

