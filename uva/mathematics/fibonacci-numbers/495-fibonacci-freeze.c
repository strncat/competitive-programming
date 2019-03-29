#include <stdio.h>

/* 495 - Fibonacci Freeze
 n <= 5000 (number of digits in 5000 is 1045)
 Sample Input
 5
 7
 11
 Sample Output
 The Fibonacci number for 5 is 5
 The Fibonacci number for 7 is 13
 The Fibonacci number for 11 is 89
 
 */
#define N 5001
#define M 1050
int f[N+1][M];

void fibonacci() {
    
    int i, j;
    int sum=0, carry=0;
    
    /* Initialize */
    for (i=0; i<N; i++)
        for (j=0; j<M; j++)
            f[i][j] = 0;
    
    f[0][M-1] = 0;
    f[1][M-1] = f[2][M-1] = 1;
    
    /* Add with carry */
    for (i=3; i<N; i++) {
        for (j=M-1; j>=0; j--) {
            sum = f[i-1][j] + f[i-2][j] + carry;
            f[i][j] = sum%10;
            carry = sum/10;
        }
    }
}

int main() {
        
    int i, n, flag=0;
    
    fibonacci();
    
    while (scanf("%d", &n) == 1) {
        
        flag = 0;
        printf("The Fibonacci number for %d is ", n);
        
        if (n == 0)
            printf("0\n");
        else {
            for (i=0; i<M; i++) {
            
                if (flag)
                    printf("%d", f[n][i]);
            
                else if (!flag && f[n][i] != 0) {
                    flag = 1;
                    printf("%d", f[n][i]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}
