#include <stdio.h>

/* UVa - [10579 - Fibonacci Numbers]
 Sample Input
 3
 100
 Sample Output
 2
 354224848179261915075
 
*/

#define N 1010
int F[N][N];


void print(int x) {
    
    int i, flag = 1;
    
    for (i = 0; i < N; i++) {
        if (F[x][i] == 0 && flag)
            continue;
        else {
            printf("%d", F[x][i]);
            flag = 0;
        }
    }
    printf("\n");
}

void add(int x) {
    
    int i, c, carry = 0;
    
    for (i = N-1; i >= 0; i--) {
        c = F[x-1][i] + F[x-2][i] + carry;
        F[x][i] = c%10;
        carry = c/10;
    }
}

void fibonacci() {
    
    int i, j;
    
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            F[i][j] = 0;
    
    F[0][N-1] = 0;
    F[1][N-1] = 1;
    
    for (i = 2; i < N; i++)
        add(i);
}

int main() {
    
    int number;

    fibonacci();
    
    while (scanf("%d", &number) == 1)
        if (number == 0)
            printf("0\n");
        else
            print(number);
    
    return 0;
}

