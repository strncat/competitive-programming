#include <stdio.h>
#include <limits.h>
#include <string.h>

/* 348 - Optimal Array Multiplication Sequence
 Sample Input
 3
 5 4
 4 3 
 3 2
 
 3
 1 5
 5 20
 20 1
 
 3
 5 10
 10 20
 20 35
 
 6
 30 35
 35 15
 15 5
 5 10
 10 20
 20 25
 0
 Sample Output
 Case 1: (A1 x (A2 x A3))
 Case 1: (A1 x (A2 x A3))
 Case 2: ((A1 x A2) x A3)
 Case 3: ((A1 x (A2 x A3)) x ((A4 x A5) x A6))
*/

#define N 12

int m[N][N];
int s[N][N];
int p[N + 1]; /* at most N matrices */

void print_optimal_parens(int i, int j) {
    
    if (i == j)        printf("A%d", i);
    else {
        printf("(");
        print_optimal_parens(i, s[i][j]);
        
        if (i < j)
            printf(" x ");
        
        print_optimal_parens(s[i][j] + 1, j);
        printf(")");
    }
}

void print_matrix(int n) { /* to debug */
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            printf("%d\t\t\t", m[i][j]);
        printf("\n");
    }
}

void matrix_multiplication(int n) {
    
    int i, j, k, length, q;
    
    for (i = 1; i <= n; i++)
        m[i][i] = 0;
    
    for (length = 2; length <= n; length++) { /* length is the chain length, we need to start from the shortest lengths to the longest */
        
        for (i = 1; i <= n - length + 1; i++) {
            
            j = i + length - 1;
            m[i][j] = INT_MAX;
            
            for (k = i; k <= j - 1; k++) {
                
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

int main() {

    int i, n, counter = 1;
    
    while (scanf("%d", &n) == 1 && n) {
        
        memset(p, 0, sizeof(p));
        
        for (i = 0; i <= n - 1; i++)
            scanf("%d %d", &p[i], &p[i+1]);
        
        matrix_multiplication(n);
        
        printf("Case %d: ", counter++);
        print_optimal_parens(1, n);
        printf("\n");
    }
    return 0;
}