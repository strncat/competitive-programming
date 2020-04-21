//
//  11152 - Colourful Flowers
//
//  Created by Fatima B on 10/8/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <assert.h>

const static double EPSILON = 0.0001;

double triangle_area(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    double asquared = p * (p - a) * (p - b) * (p - c);
    return sqrt(asquared);
}

double circumscribed_circle_radius(double a, double b, double c) {
    double area = triangle_area(a, b, c);
    return (a * b * c) / (4 * area);
}

double inscribed_circle_radius(double a, double b, double c) {
    double p = (a + b + c) / 2.0;
    double rsquared = (p - a) * (p - b) * (p - c) / p;
    return sqrt(rsquared);
}

double circle_area(double r) {
    return M_PI*r*r;
}

void tests() {
    int a = 3, b = 4, c = 5;

    double triangle = triangle_area(a, b, c);

    double r1 = inscribed_circle_radius(a, b, c);
    double roses = circle_area(r1);

    double r2 = circumscribed_circle_radius(a, b, c);
    double sunflowers = circle_area(r2) - triangle;

    assert(fabs((triangle - roses) - 2.8584) <= EPSILON);
    assert(fabs(roses - 3.1416) <= EPSILON);
    assert(fabs(sunflowers - 13.6350) <= EPSILON);
}

int main() {
    int a, b, c;
    //tests();
    while(scanf("%d %d %d", &a, &b, &c) != EOF) {
        double r = inscribed_circle_radius(a, b, c);
        double triangle = triangle_area(a, b, c);
        double roses = circle_area(r);
        double violets = triangle - roses;
        double r2 = circumscribed_circle_radius(a, b, c);
        double sunflowers = circle_area(r2) - triangle;
        printf("%.4f %.4f %.4f\n", sunflowers, violets, roses);
    }
    return 0;
}
