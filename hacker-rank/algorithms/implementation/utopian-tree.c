#include <stdio.h>

/* Utopian Tree
first cycle => double height
second cycle => add 1 m
Sample Input:
2
0
1
Sample Output:
1
2
Sample Input: #01:
2
3
4
Sample Output: #01:
6
7
*/


int main() {
    
    int test_cases, n, i;
    long long int height;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &n);
        
        height = 1;
        for (i = 1; i <= n; i++) {
            if (i % 2)
                height *= 2;
            else
                height += 1;
        }
        printf("%lld\n", height);
    }
    return 0;
}

