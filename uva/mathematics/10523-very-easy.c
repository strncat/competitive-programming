#include <stdio.h>
#include <string.h>

/* 10523 - Very Easy !!!
 The number of digits in a number:
 i*A^i ~= log(i) + N*log(i) = 3 + 150 * log (15) ~= 180
 Sample Input
 3 3
 4 4
 Sample Output
 102
 1252*/

#define MAX 250
void add(int* a, int* b) {
    
    int result, carry, j;
    
    carry = 0;
    for (j = 0; j < MAX; j++) {
        result = a[j] + b[j] + carry;
        a[j] = result % 10;
        carry = result / 10;
    }
    
}

void multiply(int* product, int M) { /* multiple array product with number M */
    
    int j, k, n = 0, result, carry;
    int m[10];
    int output[MAX] = {0};
    int sum[MAX] = {0};
    
    while (M > 0) {
        m[n++] = M % 10;
        M /= 10;
    }
    
    for (k = 0; k < n; k++) {

        /* multiply the first digit in M with each digit in product like how we did it in school
           out[k][j + k] because when we move to the 10th digit, the first digit is zero */
        
        memset(output, 0, sizeof(output));
        
        carry = 0;
        for (j = 0; j < MAX; j++) {
            result = m[k] * product[j] + carry;
            output[j + k] = result % 10;
            carry = (result / 10);
        }
        
        add(sum, output); /* add output to the sum */
    }
    /* copy result */
    for (j = 0; j < MAX; j++)
        product[j] = sum[j];
}

int main() {
    
    int i, j, k, N, A, flag;
    int number[MAX] = {0};
    int product[MAX] = {0};
    int sum[MAX] = {0};
    
    while (scanf("%d %d", &N, &A) == 2) {
        
        memset(number, 0, sizeof(number));
        memset(product, 0, sizeof(product));
        memset(sum, 0, sizeof(sum));
        product[0] = 1;
        
        /* example N = 100, A = 100: 1(10^1) + 2(10^2) + 3(10^3) + .... + 100(10^100) */
        
        if (A == 0)
            printf("0\n");
        
        else {
        
            for (i = 1; i <= N; i++) {
                
                /* Step (1) A^i keep product seperate to re-use */
                multiply(product, A);
                
                /* save product for next time and use number instead */
                for (j = 0; j < MAX; j++)
                    number[j] = product[j];
                
                /* Step (2) i * A^i */
                multiply(number, i);
                
                /* add number to the sum */
                add(sum, number);
            }
            
            flag = 0;
            for (k = MAX - 1; k >= 0; k--)
                if (sum[k] || (sum[k] == 0 && flag)) {
                    printf("%d", sum[k]);
                    flag = 1;
                }
            printf("\n");
        }
        
    }
    return 0;
}