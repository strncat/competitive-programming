#include <stdio.h>

/* Find Point
http://www.ditutor.com/vec/symmetric_point.html
Sample input
1
0 0 1 1
Sample output
2 2
*/
    
int main() {
    
    int test_cases, x1, x2, x3, y1, y2, y3;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {

        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        x3 = (x2 - x1) + x2;
        y3 = (y2 - y1) + y2;
        
        printf("%d %d\n", x3, y3);
    }
    
    return 0;
}
