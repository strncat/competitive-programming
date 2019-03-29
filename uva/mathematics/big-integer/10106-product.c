#include <stdio.h>
#include <string.h>

/* 10106 - Product
Sample Input
12
12
2
222222222222222222222222
Sample Output
144
444444444444444444444444
*/

#define MAX 500

void add(int* a, int* b) {
    
    int result, carry, i;
    
    carry = 0;
    for (i = 0; i < MAX; i++) {
        result = a[i] + b[i] + carry;
        a[i] = result % 10;
        carry = result / 10;
    }
}

void multiply(int* a, int* b, int* sum) { /* multiple arrays a * b and store result in sum */
    
    int i, j, result, carry;
    int output[MAX + MAX];
    
    for (i = 0; i < MAX; i++) {
        
        /* multiply the first digit in b with each digit in a like how we did it in school
         output[j + i] because when we move to the 10th digit, the first digit is zero */
        
        memset(output, 0, sizeof(output));
        
        carry = 0;
        for (j = 0; j < MAX; j++) {
            result = b[i] * a[j] + carry;
            output[j + i] = result % 10;
            carry = (result / 10);
        }
        add(sum, output); /* add output to the sum */
    }
}

int main() {
    
    int leading_zero, zero_output, i, n;
    int a[MAX], b[MAX], result[MAX + MAX] = {0};
    char atemp[MAX], btemp[MAX];
    
    while(scanf("%s\n%s", atemp, btemp) == 2) {
        
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(result, 0, sizeof(result));
        
        n = (int) strlen(atemp);
    
        /* save the number so that the least signifact digit is at a[0] */
        for (i = n - 1; i >= 0; i--)
            a[i] = atemp[n - 1 - i] - '0';
        
        n = (int) strlen(btemp);
        
        for (i = n - 1; i >= 0; i--)
            b[i] = btemp[n - 1 - i] - '0';
        
        multiply(a, b, result);
        
        leading_zero = 1;
        zero_output = 1;
        for (i = MAX + MAX - 1; i >= 0; i--)
            if (result[i] || (result[i] == 0 && !leading_zero)) {
                printf("%d", result[i]);
                leading_zero = 0;
                zero_output = 0;
            }
        if (zero_output)
            printf("0");
        
        printf("\n");
    }
    
    return 0;
}