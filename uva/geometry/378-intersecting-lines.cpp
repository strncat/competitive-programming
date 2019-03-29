//
//  378 - Intersecting Lines
//
//  Created by Fatima B on 10/11/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <assert.h>

#define EPSILON 0.000001

typedef struct point {
    double x;
    double y;
    point() { x=0; y=0; }
    point(double x, double y) { this->x = x; this->y = y; }
    bool operator==(const point p2) const {
        return (fabs(this->x - p2.x) <= EPSILON && fabs(this->y - p2.y) <= EPSILON);
    }
} point;

typedef struct line {
    double a;
    double b;
    double c;
    line() { a = 0; b = 0; c = 0; }
    line(double a, double b, double c) {
        this->a = a; this->b = b; this->c = c;
    }
} line;

void points_to_lines(point p1, point p2, line *l) {
    // (y - y1) = m(x - x1)
    // y - y1 - mx + mx1 = 0
    // y - mx + mx1 - y1 = 0
    //
    if (fabs(p1.x - p2.x) <= EPSILON) { // vertical line
        l->a = 1;
        l->b = 0;
        l->c = -p1.x;
    } else {
        double m = (p2.y-p1.y)/(p2.x-p1.x);
        l->a = -m;
        l->b = 1;
        l->c = m*p1.x - p1.y;
    }
}

bool parallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) <= EPSILON && fabs(l1.b - l2.b) <= EPSILON);
}

bool same_line(line l1, line l2) {
    return (fabs(l1.a - l2.a) <= EPSILON && fabs(l1.b - l2.b) <= EPSILON
            && fabs(l1.c - l2.c) <= EPSILON);
}
int intersection(line l1, line l2, point *p_out) {
    if (same_line(l1, l2)) { // many points
        return 2;
    }
    if (parallel(l1, l2)) { // none
        return 0;
    }
    // solve for x
    p_out->x = (l2.b*l1.c - l1.b*l2.c) / (l1.b*l2.a - l2.b*l1.a);
    // plug in the equation
    // we need to test for the case if one of the two lines is vertical!
    if (fabs(l1.b) > EPSILON) {
        p_out->y = ((-l1.a*p_out->x) - l1.c) / l1.b;
    } else {
        p_out->y = ((-l2.a*p_out->x) - l2.c) / l2.b;
    }
    return 1;
}

void tests() {
    int a[5][8] = {0, 0, 4, 4, 0, 4, 4, 0,
                   5, 0, 7, 6, 1, 0, 2, 3,
                   5, 0, 7, 6, 3, -6, 4, -3,
                   2, 0, 2, 27, 1, 5, 18, 5,
                   0, 3, 4, 0, 1, 2, 2, 5};
    for (int i = 0; i < 5; i++) {
        point p1(a[i][0], a[i][1]);
        point p2(a[i][2], a[i][3]);
        point p3(a[i][4], a[i][5]);
        point p4(a[i][6], a[i][7]);

        line line1, line2;
        points_to_lines(p1, p2, &line1);
        points_to_lines(p3, p4, &line2);

        point p;
        int r = intersection(line1, line2, &p);
        if (r == 0) {
            printf("NONE\n");
        } else if (r == 2) {
            printf("LINE\n");
        } else {
            printf("POINT %.2f %.2f\n", p.x, p.y);
        }
    }

}

int main() {
    //tests();

    int x, y;
    int test_cases;
    printf("INTERSECTING LINES OUTPUT\n");

    scanf("%d", &test_cases);
    while (test_cases--) {
        scanf("%d %d", &x, &y);
        point p1(x, y);

        scanf("%d %d", &x, &y);
        point p2(x, y);

        scanf("%d %d", &x, &y);
        point p3(x, y);

        scanf("%d %d", &x, &y);
        point p4(x, y);

        line line1, line2;
        points_to_lines(p1, p2, &line1);
        points_to_lines(p3, p4, &line2);

        point p;
        int r = intersection(line1, line2, &p);
        if (r == 0) {
            printf("NONE\n");
        } else if (r == 2) {
            printf("LINE\n");
        } else {
            printf("POINT %.2f %.2f\n", p.x, p.y);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
