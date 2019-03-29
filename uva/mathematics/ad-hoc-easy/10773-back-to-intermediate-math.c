#include <stdio.h>
#include <math.h>

/* 10773 - Back to Intermediate Math
 Sample Input
 3
 8 5 6
 1 2 3
 1 5 6
 Sample Output
 Case 1: 1.079
 Case 2: 0.114
 Case 3: 0.135
*/

int main() {
    
    int i, test_cases;
    double d, v, u, t1, t2;
    
    scanf("%d", &test_cases);
    
    for (i = 1; i <= test_cases; i++) {
        
        scanf("%lf %lf %lf", &d, &v, &u);
        
        printf("Case %d: ", i);
        
        if (u == 0 || v == 0 || u <= v)
            printf("can't determine\n");
        
        else {
            /* Method One */
            t1 = d / u;
            
            /* Method Two */
            t2 = d / sqrt (u * u - v * v);
            
            printf("%.3lf\n", t2 - t1);
        }
    }
    
    return 0;
}