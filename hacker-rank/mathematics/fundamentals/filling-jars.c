#include <stdio.h>
#include <assert.h>

/* Filling Jars (the only trick is the long long int!)
 5 3
 1 2 100
 2 5 100
 3 4 100
 
 conxtraints
 3 <= N <= 10^7
 1 <= M <= 10^5
 1 <= a <= b <= N
 0 <= k <= 10^6
*/

int main() {

    int n, m, i;
    long long int a, b, candy, total = 0;
    
    scanf("%d %d", &n, &m);

    for (i = 0; i < m; i++) {

        scanf("%lld %lld %lld", &a, &b, &candy);
        
        total += candy * (b - a + 1);
    }
    printf("%lld", total / n);
    return 0;
}