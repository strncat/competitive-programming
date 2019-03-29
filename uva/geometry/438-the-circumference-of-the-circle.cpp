//
//  438 - The Circumference of the Circle
//
//  Created by Fatima B on 10/8/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <assert.h>

const static double EPSILON = 1e-4;
const static double PI = 3.141592653589793;

typedef struct circle {
    double h;
    double k;
    double r; // radius
    circle(double h, double k, double r) {
        this->h = h; this->k = k; this->r = r;
    }
    circle() { }
} circle;

void find_circle(double x1, double y1, double x2, double y2,
                 double x3, double y3, circle *c) {
    // (x-x1)^2 + (y-y1)^2 = r^2
    // (x-x2)^2 + (y-y2)^2 = r^2
    // (x-x3)^2 + (y-y3)^2 = r^2
    // make 1=2 & 1=3
    double C1 = x1*x1 - x2*x2 + y1*y1 - y2*y2;
    double C2 = x1*x1 - x3*x3 + y1*y1 - y3*y3;
    double H1 = 2.0*(x2 - x1);
    double H2 = 2.0*(x3 - x1);
    double K1 = 2.0*(y2 - y1);
    double K2 = 2.0*(y3 - y1);

    double d = (H1*K2 - K1*H2);
    c->h = (K1*C2 - K2*C1) / d;
    c->k = (H2*C1 - H1*C2) / d;
    c->r = sqrt((c->h - x1)*(c->h - x1) + (c->k - y1)*(c->k - y1));
}

void tests() {
    double x1 = 1, y1 = 1, x2 = 1, y2 = 7, x3 = 4, y3 = 4;
    circle c;
    find_circle(x1, y1, x2, y2, x3, y3, &c);

    assert(fabs(c.h - 1.0) <= EPSILON
           && fabs(c.k - 4.0) <= EPSILON
           && fabs(c.r - 3.0) <= EPSILON);

    x1 = 7, y1 = -5, x2 = -1, y2 = 1, x3 = 0, y3 = -6;
    find_circle(x1, y1, x2, y2, x3, y3, &c);

    assert(fabs(c.h - 3.0) <= EPSILON
           && fabs(c.k + 2.0) <= EPSILON
           && fabs(c.r - 5.0) <= EPSILON);
}

int main() {
    tests();
    double x1, y1, x2, y2, x3, y3;
    while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) == 6) {
        circle c;
        find_circle(x1, y1, x2, y2, x3, y3, &c);
        printf("%.2lf\n", 2.0*PI*c.r);
    }
    return 0;
}
