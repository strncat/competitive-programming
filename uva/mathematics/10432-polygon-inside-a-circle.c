#include <stdio.h>
#include <math.h>

/* 10432 - Polygon Inside A Circle
 Sample Input
 2 2000
 10 3000
 Sample Output
 12.566
 314.159
 http://www.mathwords.com/a/area_regular_polygon.htm or
 http://www.mathopenref.com/polygonregulararea.html
 360 = 2 * pi 
*/

#define pi 2*acos(0)

int main() {
    
    double n, r;
    double area;
    
    while (scanf("%lf %lf", &r, &n) == 2) {
    
        area = (0.5) * (n) * (r) * (r) * sin(((2*pi)/n));
                
        printf("%.3lf\n", area);
    }
    return 0;
}