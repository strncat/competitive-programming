#include <stdio.h>
#include <string.h>

/* 11687 - Digits
Sample Input (up to a million digits)
42
1
5
END
Output
3
1
2
Explanation: x0 is 42, x1 is the number of digits in x0 = 2, x2 = 1, x3 = 1
i = 3 is the minimum i such that xi-1 = xi
*/

int main() {

    char d[1000010];
    int digits, i, new_digits;
    
    while (scanf("%s", d) == 1) {
        
        if (strcmp(d, "END") == 0)
            break;
        
        digits = (int) strlen(d);
        i = 1;
        
        if (strcmp(d, "1")) {
            
            while (1) {
                i++;
                sprintf(d, "%d", digits);
                new_digits = (int) strlen(d);
                if (new_digits == digits)
                    break;
                digits = new_digits;
            }
        }
        printf("%d\n", i);
    }
    return 0;
}