//
//  191 - Intersection
//  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=127
//
//  Created by Fatima B on 10/10/15.
//  Copyright © 2015 nemo. All rights reserved.
//  accepted solution

//  Idea: find if the line intersects with any of the edges of the rectangle
//        or if the line is in the rectangle

#include <iostream>
#include <math.h>
#include <assert.h>

const static double EPSILON = 0.00000001;

typedef struct point { // point struct
    double x;
    double y;
    point() { this->x = 0; this->y = 0; }
    point(double x, double y) { this->x = x; this->y = y; }
    bool operator==(const point &p2) const {
        return (fabs(x - p2.x) <= EPSILON && fabs(y - p2.y) <= EPSILON);
    }
} point;

typedef struct line { // the standard form ax + by + c = 0
    double a;
    double b;
    double c;
    line() { this->a = 0; this->b = 0; this->c = 0; }
    line(double a, double b, double c) {
        this->a = a; this->b = b; this->c = c;
    }
} line;

void points_to_line(point p1, point p2, line *l) { // ref: programming challenges
    // m = p2.y - p1.y / p2.x - p1.x
    // (y - p1.y) = m (x - p1.x)
    // y - mx - p1.y + p1.x*m = 0
    if (p1.x == p2.x) { // vertical line
        l->a = 1;
        l->b = 0;
        l->c = -p1.x; // if we have (1,2), (1,4) then it's just x=1
    } else {
        l->b = 1;
        l->a = -(p1.y - p2.y)/(p1.x - p2.x); // or just -m
        l->c = -(l->a * p1.x) - (l->b * p1.y);
    }
}

bool parallel(line l1, line l2) {
    return (fabs(l1.a - l2.a) <= EPSILON && fabs(l1.b - l2.b) <= EPSILON);
}

bool same_line(line l1, line l2) {
    return (fabs(l1.a - l2.a) <= EPSILON && fabs(l1.b - l2.b) <= EPSILON
            && fabs(l1.c - l2.c) <= EPSILON);
}

int intersection(line l1, line l2, point *p) { // ref: programming challenges
    if (same_line(l1, l2)) {
        return 2; // infinitely many points
    }
    if (parallel(l1, l2)) { // parallel don't intersect
        return 0;
    }
    p->x = (l2.b*l1.c - l1.b*l2.c) / (l1.b*l2.a - l2.b*l1.a);
    // one line could be a vertical line
    if (fabs(l1.b) > EPSILON) { // plug in x in the first line
        p->y = ((-l1.a*p->x) - l1.c) / l1.b;
    } else { // plugin x in the second line
        p->y = ((-l2.a*p->x) - l2.c) / l2.b;
    }
    return 1;
}

// is the point on the line segment?
bool point_in_line_segment(point start, point end, point p) {
    // the x component should be in between start.x and end.x
    if (!(p.x > start.x || fabs(p.x-start.x) <= EPSILON)) {
        return false;
    }
    if (!(p.x < end.x || fabs(p.x-end.x) <= EPSILON)) {
        return false;
    }

    // this was one of my mistakes
    // consider (1,5), (4,1) is point (2,3) within range? yes
    if ((p.y > start.y || fabs(p.y-start.y) <= EPSILON) && ((p.y < end.y || fabs(p.y-end.y) <= EPSILON))) {
        return true;
    }
    if ((p.y < start.y || fabs(p.y-start.y) <= EPSILON) && ((p.y > end.y || fabs(p.y-end.y) <= EPSILON))) {
        return true;
    }
    return false;
}

bool intersection_line_rectangle(point p1, point p2, point r1, point r2, point r3, point r4) {
    line segment;
    points_to_line(p1, p2, &segment);

    line e1, e2, e3, e4;
    points_to_line(r1, r2, &e1);
    points_to_line(r2, r3, &e2);
    points_to_line(r3, r4, &e3);
    points_to_line(r4, r1, &e4);

    // Is there an intersection? and is the point within the boundary of
    // the line segment? and within the boundary of the rectangle edge?
    point p_out;
    if (intersection(segment, e1, &p_out) > 0 &&
        point_in_line_segment(p1, p2, p_out) &&
        point_in_line_segment(r1, r2, p_out)) {
        return true;
    }

    if (intersection(segment, e2, &p_out) > 0 &&
        point_in_line_segment(p1, p2, p_out) &&
        point_in_line_segment(r2, r3, p_out)) {
        return true;
    }

    if (intersection(segment, e3, &p_out) > 0 &&
        point_in_line_segment(p1, p2, p_out) &&
        point_in_line_segment(r3, r4, p_out)) {
        return true;
    }

    if (intersection(segment, e4, &p_out) > 0 &&
        point_in_line_segment(p1, p2, p_out) &&
        point_in_line_segment(r4, r1, p_out)) {
        return true;
    }
    return false;
}

bool in_rectangle(int x, int y, int xleft, int ytop, int xright, int ybottom) {
    if (x >= xleft && x <= xright && y <= ytop && y >= ybottom) {
        return true;
    }
    return false;
}

void test1() {
    double xstart=5, ystart=2, xend=6, yend=2, xleft=4, ytop=4, xright=7, ybottom=1;
    point p1(xstart, ystart), p2(xend, yend);
    point r1(xleft, ytop), r2(xleft, ybottom), r3(xright, ybottom), r4(xright, ytop);
    assert(intersection_line_rectangle(p1, p2, r1, r2, r3, r4) == false);

}

void test2() { // inside
    double xstart=2, ystart=3, xend=5, yend=4, xleft=1, ytop=5, xright=7, ybottom=1;
    point p1(xstart, ystart), p2(xend, yend);
    point r1(xleft, ytop), r2(xleft, ybottom), r3(xright, ybottom), r4(xright, ytop);
    assert (in_rectangle(xstart, ystart, xleft, ytop, xright, ybottom) &&
            in_rectangle(xend, yend, xleft, ytop, xright, ybottom)); // agh
}

void test3() {
    //1 // true
    //-4 6 -15 9 -1 1 -11 11
    //1 false
    //9 1 9 2 4 3 9 6
}

void tests() {
    test1();
    test2();
    test3();
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    //tests();
    int test_cases;
    int xstart, ystart, xend, yend, xleft, ytop, xright, ybottom;
    scanf("%d", &test_cases);
    while (test_cases--) {
        scanf("%d %d %d %d %d %d %d %d", &xstart, &ystart, &xend,
              &yend, &xleft, &ytop, &xright, &ybottom);

        if (xleft > xright) { swap(&xleft,&xright); }
        if (ybottom > ytop) { swap(&ybottom,&ytop); }
        if (xstart > xend) { swap(&xstart, &xend); swap(&ystart, &yend); }

        if (in_rectangle(xstart, ystart, xleft, ytop, xright, ybottom) &&
            in_rectangle(xend, yend, xleft, ytop, xright, ybottom)) {
            printf("T\n");
            continue;
        }

        point p1(xstart, ystart), p2(xend, yend);
        point r1(xleft, ytop), r2(xleft, ybottom), r3(xright, ybottom), r4(xright, ytop);
        bool b = intersection_line_rectangle(p1, p2, r1, r2, r3, r4);
        if (b) { printf("T\n"); }
        else { printf("F\n"); }
    }
    return 0;
}
