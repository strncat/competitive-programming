//
/* Project Euler #7: 10001st prime
Constraints
1 ≤ T ≤ 10^3
1 ≤ N ≤ 10^4
Sample Input
2
3
6
Sample Output
5
13
*/

#include <stdio.h>

#define N 110000

void sieve(int* primes) {
    int p, i, j, s[N];
    
    for (i = 0; i < N; i++)
        s[i] = 1;
    s[0] = s[1] = 0;

    p = 2;
    while (p < N) {
        for (j = 2*p; j < N; j+=p) {
            s[j] = 0;
        }
        for (i = p+1; p < N; i++) {
            if (s[i] == 1) {
                p = i;
                break;
            }
        }
    }
    int index = 1;
    for (i = 0; i < N; i++) {
        if (s[i] == 1) {
            primes[index++] = i;
        }
    }
}

int main() {
    int n, test_cases, primes[100002];
    
    sieve(primes);
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &n);
        printf("%d\n", primes[n]);
    }
    return 0;
}
