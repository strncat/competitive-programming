//
//  190 - Circle Through Three Points
//
//  Created by Fatima B on 10/8/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <assert.h>
#include <string.h>

const static double EPSILON = 1e-4;

typedef struct circle {
    double h;
    double k;
    double r; // radius
    circle(double h, double k, double r) {
        this->h = h; this->k = k; this->r = r;
    }
    circle() { }
} circle;

void find_circle(double x1, double y1, double x2, double y2, double x3, double y3, circle *c) {
    // (x-x1)^2 + (y-y1)^2 = r^2
    // (x-x2)^2 + (y-y2)^2 = r^2
    // (x-x3)^2 + (y-y3)^2 = r^2
    // make 1=2 & 1=3
    double C1 = x1*x1 - x2*x2 + y1*y1 - y2*y2;
    double C2 = x1*x1 - x3*x3 + y1*y1 - y3*y3;
    double H1 = 2.0*(x2 - x1); // a1
    double H2 = 2.0*(x3 - x1);
    double K1 = 2.0*(y2 - y1); // b1
    double K2 = 2.0*(y3 - y1);

    double d = (H1*K2 - K1*H2);
    c->h = (K1*C2 - K2*C1) / d;
    c->k = (H2*C1 - H1*C2) / d;
    c->r = sqrt((c->h - x1)*(c->h - x1) + (c->k - y1)*(c->k - y1));
}

void generate_equation1(circle c, char *s) {
    if (fabs(c.h) <= EPSILON) {
        sprintf(s, "x^2 + ");
    } else if (c.h >= EPSILON) {
        sprintf(s, "(x - %.3f)^2 + ", c.h);
    } else {
        sprintf(s, "(x + %.3f)^2 + ", -1*c.h);
    }
    if (fabs(c.k) <= EPSILON) {
        sprintf(s + strlen(s), "y^2 = %.3f^2", c.r);
    } else if (c.k >= EPSILON) {
        sprintf(s + strlen(s), "(y - %.3f)^2 = %.3f^2", c.k, c.r);
    } else {
        sprintf(s + strlen(s), "(y + %.3f)^2 = %.3f^2", -1*c.k, c.r);
    }
}


void generate_equation2(circle c, char *s) {
    // (x - h)^2 + (y - k)^2 = r^2
    // x^2 - 2hx + h^2 + y^2 - 2ky + k^2 - r^2 = 0
    // x^2 + y^2 - 2hx - 2ky + (k^2 + h^2 - r^2) = 0
    double C = c.k*c.k + c.h*c.h - c.r*c.r;
    double H = -2.0 * c.h;
    double K = -2.0 * c.k;

    sprintf(s, "x^2 + y^2 ");

    if (fabs(H) <= EPSILON) {
        ;
    } else if (H >= EPSILON) {
        sprintf(s + strlen(s), "+ %.3fx ", H);
    } else {
        sprintf(s + strlen(s), "- %.3fx ", -1*H);
    }

    if (fabs(K) <= EPSILON) {
        ;
    } else if (K >= EPSILON) {
        sprintf(s + strlen(s), "+ %.3fy ", K);
    } else {
        sprintf(s + strlen(s), "- %.3fy ", -1*K);
    }

    if (fabs(C) <= EPSILON) {
        sprintf(s + strlen(s), "= 0");
    } else if (C >= EPSILON) {
        sprintf(s + strlen(s), "+ %.3f = 0", C);
    } else {
        sprintf(s + strlen(s), "- %.3f = 0", -1*C);
    }
}

void tests() {
    double x1 = 1, y1 = 1, x2 = 1, y2 = 7, x3 = 4, y3 = 4;
    circle c;
    char s[100];
    find_circle(x1, y1, x2, y2, x3, y3, &c);


    x1 = 7, y1 = -5, x2 = -1, y2 = 1, x3 = 0, y3 = -6;
    find_circle(x1, y1, x2, y2, x3, y3, &c);

    char e1[100] = "(x - 3.000)^2 + (y + 2.000)^2 = 5.000^2";
    char e2[100] = "x^2 + y^2 - 6.000x + 4.000y - 12.000 = 0";

    generate_equation1(c, s);
    assert(strcmp(e1, s) == 0);
    generate_equation2(c, s);
    assert(strcmp(e2, s) == 0);
}

int main() {
    tests();
    double x1, y1, x2, y2, x3, y3;
    while (scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3) != EOF) {
        circle c;
        char s[100];
        find_circle(x1, y1, x2, y2, x3, y3, &c);
        generate_equation1(c, s);
        printf("%s\n", s);
        generate_equation2(c, s);
        printf("%s\n\n", s);
    }
    return 0;
}
