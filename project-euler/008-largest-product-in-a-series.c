#include <stdio.h>

/* Project Euler #8: Largest product in a series
Constraints
1 ≤ T ≤ 100
1 ≤ K ≤ 7
K ≤ N ≤ 1000
Sample Input
3
10 5
3675356291
10 5
2709360626
10 3
1230349012
Sample Output
3150
0
*/

int main() {
    
    int i, j, N, K, test_cases;
    long long int product, max_product;
    char s[1001];
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d %d", &N, &K);
        scanf("%s", s);
        
        max_product = 0;
        for (i = 0; i < N - K; i++) {
            product = 1;
            for (j = i; j < i + K; j++) {
                product *= (s[j] - '0');
            }
            if (product > max_product)
                max_product = product;
        }
        printf("%lld\n", max_product);
    }
    return 0;
}
