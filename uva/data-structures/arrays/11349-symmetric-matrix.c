#include <stdio.h>
#include <string.h>
/*
11349 - Symmetric Matrix
 A symmetric matrix is 
 1 2 3 4 5
 6 7 8 9 10
 11 12 13 12 11
 10 9 8 7 6
 5 4 3 2 1
 SAMPLE INPUT:
 2
 N = 3
 5 1 3
 2 0 2
 3 1 5
 N = 3
 5 1 3
 2 0 2
 0 1 5
 SAMPLE OUTPUT:
 Test #1: Symmetric.
 Test #2: Non-symmetric.
*/
int main() {
    
    long long a[100][100];
    int cases, i, j, N, counter;
    int symmetric, middle_row;
    
    scanf("%d", &cases);
    
    for (counter=1; counter<=cases; counter++) {
        symmetric = 1;
        
        scanf("\nN = %d",&N);
        
        for (i=0; i<N; i++)
            for (j=0; j<N; j++) {
                scanf("%lld", &a[i][j]);
                if (a[i][j] < 0)
                    symmetric = 0;
            }
        
        for (i=0; i<N/2; i++) /* match opposite row */
            for (j=0; j<N; j++)
                if (a[i][j] != a[N-i-1][N-j-1]) {
                    symmetric = 0;
                    break;
                }
        middle_row = N/2;
        if (N%2) { /* Odd Case */
            for (j=0; j<N/2; j++)
                if (a[middle_row][j] != a[middle_row][N-j-1]) {
                    symmetric = 0;
                    break;
                }
        }
        if (symmetric)
            printf("Test #%d: Symmetric.\n", counter);
        else
            printf("Test #%d: Non-symmetric.\n", counter);
    }
    return 0;
}