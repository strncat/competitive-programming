#include <stdio.h>
#include <string.h>

/* Sam and sub-strings
I ended up looking @@
Constraints
1 ≤ N ≤ 2*10^5
Sample Input
16
123
Sample Output
23
164
*/

#define MOD7 1000000007

int main() {
    
    int length, i;
    unsigned long long int sum = 0, term;
    char number[200010];
    
    scanf("%s", number);
    length = (int) strlen(number);
    
    term = (number[0] - '0');
    sum = term;
    for (i = 1; i < length; i++) {
        term = 10*term + (i + 1)*(number[i] - '0');
        term %= MOD7;
        sum = (term + sum) % MOD7;
        
    }
    printf("%llu\n", sum);
    return 0;
}
