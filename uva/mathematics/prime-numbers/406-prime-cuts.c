#include <stdio.h>
#include <math.h>

/* 406 - Prime Cuts
(1) N <= 1000
(2) C <= N
(3) print C*2 if even, C*2-1 if odd
 input: 
 21 2
 18 2
 18 18
 100 7
 output:
 21 2: 5 7 11
 
 18 2: 3 5 7 11
 
 18 18: 1 2 3 5 7 11 13 17
 
 100 7: 13 17 19 23 29 31 37 41 43 47 53 59 61 67 */

#define N 3000

int primes[N+1];

void sieve() {
    
    int flag[N+1], i, m;
    
    flag[1] = 1; /* Exception for this problem? */
    for (i = 2; i <= N; i++)
        flag[i] = 1;
    
    for (i = 2; i*i <= N; i++)
        if (flag[i]) {
            for (m = i*i; m < N; m += 2*i)
                flag[m] = 0;
        }
    
    m=0;
    primes[m++] = 1; /* Exception for this problem? */
    primes[m++] = 2;
    for (i = 3; i <= N; i += 2)
        if (flag[i])
            primes[m++]=i;
}

int main() {
        
    int i=0, j, n, c, begin, end, mid;
    
    sieve(); /* generate all primes between 1 and 1000 */

    while (scanf("%d %d", &n, &c) == 2) {
        
        i=0;
        while (primes[i] <= n)
            i++;
        
        printf("%d %d:", n, c);
        
        mid = i/2;
                
        if (i%2 == 0) {
            begin = mid-c;
            end = mid+c;
        }
        else {
            mid++;
            begin = mid-c;
            end = mid+c-1;

        }
        
        if (c >= mid) {
            begin = 0;
            end = i;
        }
                
        for (j=begin; j<end; j++) 
            printf(" %d", primes[j]);
        
        printf("\n\n");
    }
    
    return 0;
    
}
