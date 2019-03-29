#include <stdio.h>
#include <string.h>

/* 713 - Adding Reversed Numbers
Sample Input
3
24 1
4358 754
305 794
Sample Output
34
1998
1
 */

#define MAX 220
void add(int *sum, int* a, int* b) { /* add two numbers a and b and save the sum in sum */
    
    int result, carry, j;
    
    carry = 0;
    for (j = 0; j < MAX; j++) {
        result = a[j] + b[j] + carry;
        sum[j] = result % 10;
        carry = result / 10;
    }
    
}

int main() {
    
    int i, n, m, test_cases, a[MAX], b[MAX], sum[MAX], end, leading_zero;
    char c;
    
    scanf("%d\n", &test_cases);
    
    while (test_cases--) {
        
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(sum, 0, sizeof(sum));
        
        /* save a and b in a their reversed ways */
        
        n = 0;
        while ((c = getchar()) != ' ')
            a[n++] = c - '0';
        
        m = 0;
        while ((c = getchar()) != '\n')
            b[m++] = c - '0';
        
        add(sum, a, b); /* sum the already reversed numbers */
        
        /* print it so that there are no leading or trailing zeros */
        end = 0;
        for (i = MAX - 1; i >= 0; i--) {
            if (sum[i] == 0)
                end++;
            else
                break;
        }
        end = MAX - end;
        
        leading_zero = 1;
        for (i = 0; i < end; i++) {
            if (sum[i] || (sum[i] == 0 && !leading_zero)) {
                printf("%d", sum[i]);
                leading_zero = 0;
            }
        }
        printf("\n");
    }
    return 0;
}