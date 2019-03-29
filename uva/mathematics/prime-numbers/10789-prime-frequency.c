#include <stdio.h>

/* 10789 - Prime Frequency
 Sample Input
 3
 ABCC
 AABBBBDDDDD
 ABCDFFFF
 Sample Output
 Case 1: C
 Case 2: AD
 Case 3: empty
*/

void sieve_primes(int *p, int N) {
    
    int i, j;
    
    p[1] = 0;
    for (i = 2; i<= N; i++)
        p[i] = 1;
    
    for (i = 2; i <= N/2; i++)
        for (j = 2; j <= N/i; j++)
            p[i * j] = 0;
}

int main() {
    
    int primes[2005], ascii[256], test_cases, i, k, empty;
    char c;
   
    sieve_primes(primes, 2005);
    
    scanf("%d\n", &test_cases);
    
    for (i = 1; i <= test_cases; i++) {
        
        empty = 1;
        
        for (k = 0; k < 256; k++)
            ascii[k] = 0;
        
        while ((c = getc(stdin)) != '\n') {
            ascii[c]++;
        }
        
        printf("Case %d: ", i);
        for (k = 0; k < 256; k++) {
            if (primes[ascii[k]] == 1)
                if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z') || (k >= '0' && k <= '9')) {
                    printf("%c", k);
                    empty = 0;
                }
        }
        if(empty == 1)
            printf("empty");
        
        printf("\n");
    }
    return 0;
}
