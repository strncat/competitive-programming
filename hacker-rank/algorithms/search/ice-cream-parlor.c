#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// just brute force!
/* Ice Cream Parlor
1 ≤ T ≤ 50
2 ≤ M ≤ 10000
2 ≤ N ≤ 10000
1 ≤ ci ≤ 10000
--
Sample Input
2
4
5
1 4 5 3 2
4
4
2 2 4 3
Sample Output
1 4
1 2
*/

#define N 10001

int main() {

    int n, m, a[N], test_cases, found = 0;

    scanf("%d", &test_cases);

    while (test_cases--) {
        
        scanf("%d", &m);
        scanf("%d", &n);
        
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        found = 0;
        for (int i = 0; i < n; i++) {
             for (int j = i + 1; j < n; j++) {
                 if (a[i] + a[j] == m) {
                     printf("%d %d\n", i + 1, j + 1);
                     found = 1;
                     break;
                 }
             }
            if (found == 1)
                break;
        }
    }
    return 0;
}
