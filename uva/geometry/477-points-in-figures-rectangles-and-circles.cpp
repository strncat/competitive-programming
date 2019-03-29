//
//  main.cpp
//  477 - Points in Figures: Rectangles and Circles
//
//  Created by Fatima B on 10/11/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <math.h>

int main() {
    char c;
    double r[10][5];
    double xleft, xtop, xright, ybottom, x, y, radius;

    int i = 0, j = 0;
    while (1) {
        std::cin >> c;
        if (c == '*') { break; }
        if (c == 'r') {
            scanf("%lf %lf %lf %lf", &xleft, &xtop, &xright, &ybottom);
            r[i][0] = xleft;
            r[i][1] = xtop;
            r[i][2] = xright;
            r[i][3] = ybottom;
            r[i][4] = 0;
        } else {
            scanf("%lf %lf %lf", &x, &y, &radius);
            r[i][0] = x;
            r[i][1] = y;
            r[i][2] = radius;
            r[i][4] = 1;
        }
        i++;
    }

    while (1) {
        scanf("%lf %lf", &x, &y);
        if (x == 9999.9 && y == 9999.9) { break; }
        j++;

        bool contained = false;
        // for each figure
        for (int m = 0; m < i; m++) {
            // if within bounds
            if (r[m][4] == 0) {
                if ((x > r[m][0] && x < r[m][2] && y > r[m][3] && y < r[m][1])) {
                    printf("Point %d is contained in figure %d\n", j, m+1);
                    contained = true;
                }
            } else {
                double distance = (y - r[m][1])*(y - r[m][1]) + (x - r[m][0])*(x - r[m][0]);
                if (distance < r[m][2]*r[m][2]) {
                    printf("Point %d is contained in figure %d\n", j, m+1);
                    contained = true;
                }
            }
        }

        if (!contained) {
            printf("Point %d is not contained in any figure\n", j);
        }
    }
}
