#include <stdio.h>

/* 10327 - Flip Sort
 Sample Input
 3
 1 2 3
 3
 2 3 1
 Sample Output
 Minimum exchange operations : 0
 Minimum exchange operations : 2
*/

#define N 10000

int main() {
    
    int n, i, j, count, a[1000];
    
    while (scanf ("%d", &n) == 1) {
        
        for (i=0; i<n; i++)
            scanf ("%d", &a[i]);
        
        count = 0;
        for (i=0; i<n; i++) {
            for (j=i+1; j<n; j++)
                if (a[i] > a[j])
                    count++;
        }
        printf ("Minimum exchange operations : %d\n", count);
    }
    return 0;
}