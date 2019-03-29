#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* 10200 - Prime Time
 Count primes using n^2 + n + 41
 0 <= a <= b <= 10000
 
 0 39  => 100.00
 0 40 => 97.56
 39 40 => 50.00
 1423 2222 => 44.13
 */

#define N 10000000
#define M 10000

int sieve_primes[N+1];

void sieve() {
    
    int i, m;
    sieve_primes[1] = 0;
    for (i=2; i<= N; i++)
        sieve_primes[i] = 1;
    
    for (i = 2; i*i <= N; i++) {
        if (sieve_primes[i]) {
            for (m = i*i; m < N; m += 2*i)
                sieve_primes[m] = 0;
        }
    }
}

bool isPrime (int n)
{
    int m, i;
    
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n%2 == 0) return false;
    
    if (n < N && sieve_primes[n])
        return true;
    else {
        m = sqrt(n);
    
        for (i=3; i <= m; i+=2)
            if (n%i == 0)
                return false;
        return true;
    }
}

int main() {

    int a, b, i, n, primes[M];
    double p, euler_primes=0.0, true_primes=0.0;
    
    sieve(); /* generate enough primes */
    
    for(i=0; i<=M; i++) {
        
        n = i*i + i + 41;
        primes[i]=isPrime(n);
    }
    
    while (scanf("%d %d", &a, &b) == 2) {
        
        true_primes=0;
        euler_primes=b-a+1;
        
        for (i=a; i<=b; i++) 
            true_primes+=primes[i];
        
        p = (true_primes/euler_primes);
        
        /*printf("%.2f\n", round(p*10000)/100);*/
        printf("%.2lf\n",true_primes*100/euler_primes+0.00000005);
        
    }
    
    return 0;
}
