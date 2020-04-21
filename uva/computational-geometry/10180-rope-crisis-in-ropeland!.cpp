//
//  10180 - Rope Crisis in Ropeland!
//  100 days challenge
//
//  Created by FB on 9/22/17.
//  Copyright © 2017 FB. All rights reserved.
//
#include <iostream>
#include <math.h>

int main() {
    freopen("example.in" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    int n;
    scanf("%d", &n);

    while (n--) {
        double x1, y1, x2, y2, r;
        scanf("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &r);

        // vector from A to Circle's origin O is just x1-0,y1-0
        double OAx = 0-x1;
        double OAy = 0-y1;
        // vector AB
        double BAx = x2-x1;
        double BAy = y2-y1;
        // projection of AO onto AB = |AO|*cos@
        //                          = |AO|*(AO dot AB)/|AO||AB|
        //                          = (AO dot AB)/|AB|
        double dot_product = BAx * OAx + BAy * OAy;
        double BA_norm = sqrt(BAy * BAy + BAx * BAx);
        double scalar_proj = dot_product / (BA_norm * BA_norm);

        double xx = 0.0;
        double yy = 0.0;

        // https://stackoverflow.com/questions/849211/shortest-distance-between-a-point-and-a-line-segment
        // also https://www.desmos.com/calculator helps a lot 
        if (scalar_proj < 0) {
            xx = x1;
            yy = y1;
        } else if (scalar_proj > 1) {
            xx = x2;
            yy = y2;
        } else {
            xx = x1 + scalar_proj * (x2-x1);
            yy = y1 + scalar_proj * (y2-y1);
        }

        double dx = 0 - xx;
        double dy = 0 - yy;
        double distance = sqrt(dx * dx + dy * dy);

        double rope = 0.0;
        if (distance < r) {
            double d1 = sqrt(y1*y1 + x1*x1);
            double d2 = sqrt(y2*y2 + x2*x2);

            double t1 = sqrt(d1*d1 - r*r);
            double t2 = sqrt(d2*d2 - r*r);

            double d = sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));

            double theta1 = acos(r/d2);
            double theta2 = acos(r/d1);
            double theta = acos((d1*d1 + d2*d2 - d*d)/(2*d1*d2));

            double theta3 = theta - theta1 - theta2;
            double arc = r * theta3;
            rope = t1 + t2 + arc;
        } else {
            rope = sqrt((y2-y1)*(y2-y1) + (x2-x1)*(x2-x1));
        }
        printf("%.3lf\n", rope);
    }
    return 0;
}
