#include <stdio.h>

/*  hackerrank: all the numbers except for one are duplicated (x2). How do you get this numbers */

void only_once(int *a, int n) { /* O(n) time and O(1) space */
    
    int i, result = 0;
    
    for (i = 0; i < n; i++) {
        result ^= a[i];
    }
    
    printf("%d\n", result);
}

int main() {
    
    int a[7] = {2, 6, 3, 3, 2, 5, 5};
    
    only_once(a, 7);
    
    return 0;
}