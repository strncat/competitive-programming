#include <stdio.h>

/* Cavity Map
1 ≤ n ≤ 100
Sample Input
4
1112
1912
1892
1234
Sample Output
1112
1X12
18X2
1234
*/

int main() {
    
    char mark[100][100], a[100][100];
    int i, j, n;

    scanf("%d\n", &n);
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%c\n", &a[i][j]);
        }
    }
    
    for (i = 1; i < n - 1; i++) {
        for (j = 1; j < n - 1; j++) {
            if (a[i - 1][j] < a[i][j] && a[i + 1][j] < a[i][j] &&
                a[i][j - 1] < a[i][j] && a[i][j + 1] < a[i][j]) {
                mark[i][j] = 'X';
            }
        }
    }
    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mark[i][j] == 'X') {
                printf("X");
            } else {
                printf("%c", a[i][j]);
            }
        }
        printf("\n");
    }
    
    return 0;
}

