//
/* Project Euler #5: Smallest multiple
Constraints
1 ≤ T ≤ 10
1 ≤ N ≤ 40
Sample Input
2
3
10
Sample Output
6
2520
*/

#include <stdio.h>

unsigned long long int gcd(unsigned long long int a, unsigned long long int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

unsigned long long int lcm(unsigned long long int a, unsigned long long int b) {
    return b * a / gcd(a,b);
}

int main() {
    
    int test_cases;
    unsigned long long int n, multiple, new_multiple;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%llu", &n);
        
        multiple = new_multiple = 1;
        
        for (int i = 2; i <= n; i++) {
            new_multiple = lcm(multiple, i);
            multiple = new_multiple;
        }
        printf("%llu\n", new_multiple);
    }
    return 0;
}
