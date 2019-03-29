//
//  main.cpp
//  476 - Points in Figures: Rectangles
//
//  Created by Fatima B on 10/11/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <math.h>

const static double EPSILON = 0.00000001;

typedef struct rectangle {
    double xleft;
    double ytop;
    double xright;
    double ybottom;
} rectangle;

int main() {
    char c;
    rectangle r[10];
    double xleft, xtop, xright, ybottom;

    int i = 0;
    while (1) {
        std::cin >> c;
        if (c == '*') { break; }
        if (c == 'r') {
            scanf("%lf %lf %lf %lf", &xleft, &xtop, &xright, &ybottom);
            r[i].xleft = xleft;
            r[i].ytop = xtop;
            r[i].xright = xright;
            r[i++].ybottom = ybottom;
        }
    }

    double x, y;
    int j = 0;
    while (1) {
        scanf("%lf %lf", &x, &y);
        if (x == 9999.9 && y == 9999.9) { break; }
        j++;

        // for each rectangle
        bool contained = false;
        for (int m = 0; m < i; m++) {
            // if within bounds
            if ((x > r[m].xleft && x < r[m].xright &&
                 y > r[m].ybottom && y < r[m].ytop)) {
                printf("Point %d is contained in figure %d\n", j, m+1);
                contained = true;
            }
        }

        if (!contained) {
            printf("Point %d is not contained in any figure\n", j);
        }
    }
}
