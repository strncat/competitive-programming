#include <stdio.h>
#include <string.h>
/*
11040 - Add bricks in the wall
 Sample Input
 2
 255
 54 67
 10 18 13
 3 3 5 2
 2 1 2 1 1
 256
 64 64
 16 16 16
 4 4 4 4
 1 1 1 1 1
 Sample Output
 255
 121 134
 54 67 67
 23 31 36 31
 10 13 18 18 13
 5 5 8 10 8 5
 3 2 3 5 5 3 2
 2 1 1 2 3 2 1 1
 2 0 1 0 2 1 1 0 1
 256
 128 128
 64 64 64
 32 32 32 32
 16 16 16 16 16
 8 8 8 8 8 8
 4 4 4 4 4 4 4
 2 2 2 2 2 2 2 2
 1 1 1 1 1 1 1 1 1
*/
int main() {
    
    int cases, a[10][10];
    int i, j, k, counter;
    int m,n;
    
    for (i=1; i<=9; i++)
        for (j=1; j<=9; j++)
            a[i][j] = 0;
    
    scanf("%d", &cases);
    
    while (cases--) {
        i = 1;
        j = 1;
        k = 1;
        counter = 0;
        
        /* Read Input */
        while (scanf("%d", &a[i][j]) == 1) {
            if (j%k == 0) {
                i = k+2;
                j = 1;
                k += 2;
            }
            else
                j+=2;
            
            counter ++;
            if (counter == 15)
                break;
        }
        
        m = 9;
        n = 2;
        
        for (m=9; m>=1; m-=2)
            for (n=2; n<=m; n+=2) {
                a[m][n] = (a[m-2][n-1] - a[m][n-1] - a[m][n+1])/2;
                a[m-1][n] = a[m][n]+a[m][n+1];
                a[m-1][n-1] = a[m][n-1]+a[m][n];
            }
        
        /* Print Output */
        for (i=1; i<=9; i++) {
            printf("%d", a[i][1]);
            for (j=2; j<=i; j++)
                printf(" %d", a[i][j]);
            printf("\n");
        }
        
    }
    return 0;
}