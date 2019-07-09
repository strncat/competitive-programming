#include <stdio.h>

/* Red John is Back
http://www.iarcs.org.in/inoi/online-study-material/topics/dp-tiling.php
1 <= T <= 20
1 <= N <= 40
Sample Input
2
1
7
Sample Output
0
3
 */

#define N 41
#define M 1000000

void count(int *a, int n) {
    
    a[0] = a[1] = a[2] = a[3] = 1;
    
    for (int i = 4; i <= n; i++)
        a[i] = a[i - 1] + a[i - 4];
}

void primes(int *p, int m) {
    
    long int i, j;
    
    p[0] = p[1] = 0;
    for (i = 2; i < m; i++)
        p[i] = 1;
    
   
    for (j = 2; j <= m/2; j++) {
        if (p[j]) {
            for (i = j; i * j < m; i++)
                p[i * j] = 0;
        }
    }
}

void total_primes(int *t, int *p, int m) {
    
    int i, total = 0;
    
    for (i = 0; i < m; i++) {
        total += p[i];
        t[i] = total;
    }
}

int main() {
    
    int n, test_cases, a[N + 1], p[M], t[M];
    
    count(a, N);
    primes(p, M);
    total_primes(t, p, M);
    
    scanf("%d\n", &test_cases);
    
    while (test_cases--) {
        scanf("%d", &n);
        printf("%d\n", t[a[n]]);
    }
    
    return 0;
}

