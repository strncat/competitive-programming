#include <stdio.h>
#include <string.h> 

/* UVa [1225 - Digit Counting]
 Sample Input
 2
 3
 13
 Sample Output
 0 1 1 1 0 0 0 0 0 0
 1 6 2 2 1 1 1 1 1 1
 */

#define N 10001
#define D 10

int digits[N][D];

/* you don't need to pre-calculate, I just did */

void calculate() {
    int i, j, k;
    
    for (i = 1; i < N; i++)
        for (j = 0; j < D; j++)
        digits[i][j] = 0;
    
    
    for (i = 1; i <= N; i++) {
        j = i;
        while (j > 0) {
            for (k = i; k < N; k++)
                digits[k][j%10]++;
            j = j / 10;
        }
    }
}

int main() {
    
    int i, cases, x;
    scanf("%d", &cases);
    
    calculate();
    
    while (cases--) {
        
        scanf("%d", &x);
 
        for (i = 0; i < D-1; i++)
            printf("%d ", digits[x][i]);
        printf("%d\n", digits[x][9]);
    }
    return 0;
}
