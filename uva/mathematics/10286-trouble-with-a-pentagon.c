#include <stdio.h>
#include <math.h>

/* 10286 - Trouble with a Pentagon 
 Input: F, length of a side in the pentagon, (floating point (0<=F<=100000))
 Output: largest possible side of a square in a pentagon such that: 
 One vertex of the square will be coincident with a vertex of the square? (type? pentagon).
 
 p/sin(63) = q/sin(108)
 q = sin(108)/sin(63) * p
 */

int main() {

    double pi = acos(-1);
    double cv = sin((108 * pi)/ 180) / sin((63 * pi)/180);
 
    double f;
    
    while( scanf("%lf", &f) == 1 )
        printf("%.10lf\n",f * cv);
    
    return 0;
    
}
