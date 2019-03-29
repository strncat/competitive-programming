//
//  460 - Overlapping Rectangles
//
//  Created by Fatima B on 10/13/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <assert.h>

typedef struct rectangle {
    int xleft;
    int ytop;
    int xright;
    int ybottom;
    rectangle() { }
    rectangle(int xleft, int ytop, int xright, int ybottom) {
        this->xleft = xleft;
        this->ytop = ytop;
        this->xright = xright;
        this->ybottom = ybottom;
    }
} rectangle;

int minimum(int a, int b) {
    if (a < b) { return a; } else { return b; }
}
int maximum(int a, int b) {
    if (a > b) { return a; } else { return b; }
}

bool intersection(rectangle r1, rectangle r2, rectangle *t) {
    // x axis intersection
    int xmin = minimum(r1.xright, r2.xright);
    int xmax = maximum(r1.xleft, r2.xleft);

    if (xmin <= xmax) { // no intersection
        return false;
    } else {
        t->xleft = xmax;
        t->xright = xmin;
    }

    // y axis intersection
    int ymin = minimum(r1.ytop, r2.ytop);
    int ymax = maximum(r1.ybottom, r2.ybottom);

    if (ymin <= ymax) { // no intersection
        return false;
    } else {
        t->ytop = ymax;
        t->ybottom = ymin;
    }
    return true;
}

void tests() {
    rectangle r1(0, 0, 3, 3);
    rectangle r2(4, 4, 6, 6);
    rectangle t;
    assert(intersection(r1, r2, &t) == false);
}

int main() {
    //tests();
    int test_cases, xleft, ytop, xright, ybottom;
    scanf("%d", &test_cases);

    while (test_cases--) {
        scanf("%d %d %d %d", &xleft, &ybottom, &xright, &ytop);
        rectangle r1(xleft, ytop, xright, ybottom);
        scanf("%d %d %d %d", &xleft, &ybottom, &xright, &ytop);
        rectangle r2(xleft, ytop, xright, ybottom);

        rectangle t;
        bool b = intersection(r1, r2, &t);
        if (b) {
            printf("%d %d %d %d\n", t.xleft, t.ytop, t.xright, t.ybottom);
        } else {
            printf("No Overlap\n");
        }

        if (test_cases > 0) {
            printf("\n");
        }
    }
    return 0;
}
