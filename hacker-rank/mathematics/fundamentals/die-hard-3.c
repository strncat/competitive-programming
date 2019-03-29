#include <stdio.h>

/* Die Hard 3
Constraints
1 ? a, b, c ? 103
1 ? T ? 100
Sample Input
2
5 3 4
3 6 4
Sample Output
YES
 NO
*/

int gcd(int a, int b) {
    
    while (b != 0)
        if (a > b) {
            a = a - b;
        } else {
            b = b - a;
        }
    return a;
}

int main() {

    int test_cases, a, b, c;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d %d %d", &a, &b, &c);
        
        int g = gcd(a, b);
        
        if (c == a || c == b)
            printf("YES\n");
        else if ((g % c == 0 || c % g == 0) && (b >= c || a >= c))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
