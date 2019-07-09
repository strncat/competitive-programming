#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/* The Love-Letter Mystery
Sample Input #00
3
abc
abcba
abcd
Sample Output #00
2
0
4
*/

int main() {
    
    int test_cases, i, length, mid, last, total;
    char s[10000];
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%s", s);
        length = (int) strlen(s);
        mid = length / 2;
        last = length - 1;
        
        total = 0;
        for (i = 0; i < mid; i++) {
            if (s[i] != s[last])
                total += abs(s[i] - s[last]);
            last--;
        }
        printf("%d\n", total);
    }
    return 0;
}

