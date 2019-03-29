//
//  10195 - The Knights Of The Round Table
//  100 days challenge
//
//  Created by FB on 9/22/17.
//  Copyright © 2017 FB. All rights reserved.
//

#include <iostream>
#include <math.h>

/*    A
      /\
     /  \
 c  /    \ b
   /  I   \
  /        \
B ---------- C
       a
(1) We use heron's formula to find the area of the triangle
(2) From the the center of the inscribed circle draw edges to a, b and c
(3) These edges are each of length r and also are perpendicular to each side
(4) The total area of the triangle is the sum of the three triangles IAB + IAC + IBC
(5) area of triangle = 1/2 * r * c + 1/2 * r * a + 1/2 * r * b
(6) solve for r
*/

int main() {
    //freopen("example.in" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    double a, b, c;

    while (scanf("%lf %lf %lf", &a, &b, &c) != EOF) {
        if (a == 0 && b == 0 && c == 0) {
            printf("The radius of the round table is: 0.000\n");
            continue;
        }
        double perimeter = a + b + c;
        double p = perimeter/2.0;
        double area = sqrt(p*(p-a)*(p-b)*(p-c)); // heron's formula
        double r = 2 * (area / (a + b + c));
        printf("The radius of the round table is: %.3lf\n", r);
    }
    return 0;
}
