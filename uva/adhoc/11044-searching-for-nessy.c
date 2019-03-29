#include <stdio.h>
#include <math.h>

/* 11044 Searching for Nessy
 
 Sample Input
 3
 6 6
 7 7
 9 13
 Sample Output
 4
 4
 12
 */

int main() {

    int test_cases;
    float n, m;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%f %f", &n, &m);
        
        printf("%0.0f\n", ceil( (m - 2) / 3.0) * ceil( (n - 2) / 3.0));
    }
    return 0;
}