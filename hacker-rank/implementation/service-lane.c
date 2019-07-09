#include <stdio.h>

/* Service Lane
Sample Input #00
8 5
2 3 1 2 3 2 3 3
0 3
4 6
6 7
3 5
0 7
Sample Output #00
1
2
3
2
1
*/

int main() {
    
    int test_cases, k, n, i, j, min;
    int lane[100001];
    
    scanf("%d %d", &n, &test_cases);
    
    for( i = 0; i < n; i++)
        scanf("%d", &lane[i]);
    
    while (test_cases--) {
        
        scanf("%d %d", &i, &j);
        
        min = lane[j];
        for (k = i; k < j; k++) {
            if (min > lane[k])
                min = lane[k];
            if (min == 1)
                break;
        }
        
        printf("%d\n", min);
    }
    return 0;
}
