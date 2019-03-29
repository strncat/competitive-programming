#include <stdio.h>

/* UVa - [12149 - Feynman]
 Using the sum of squared formula
 Sample input
 2
 1
 8
 0
 Sample output
 5
 1
 204
*/
int main() {
    
    int n;
    
    while (scanf("%d", &n) == 1 && n)
        printf("%d\n", (n * (n + 1) * (2 * n + 1)) / 6 ); /* n is at max 100 */

    return 0;
}
