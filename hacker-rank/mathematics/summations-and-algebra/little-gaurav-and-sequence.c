#include <stdio.h>
#include <math.h>

/* Little Gaurav and Sequence
Constraints
1 ≤ T ≤ 1000
1 ≤ N ≤ 1015
Sample Input
3
1
2
3
Sample Output
0
6
0
*/

/*
2^i <= N -> N <= 10^15 -> i <= 50
 http://en.wikipedia.org/wiki/Geometric_progression
*/

int main() {
    
    int test_cases;
    long long int i, sum, n, power_of_2;

    scanf("%d", &test_cases);

    while (test_cases--) {

        scanf("%lld", &n);
        
        sum = 0;

        // case i = 0        sum += (n % 2) ? 0 : 2;
        
        // case i = 1
        if (n > 1)
            sum += (n % 2) ? 0 : 4;
        
        power_of_2 = 4;
        for(i = 2; power_of_2 <= n; i++, power_of_2 *= 2) {            sum += (n % 2) ? 0 : 6;
        }
        printf("%lld\n", sum % 10);
    }
    return 0;
}