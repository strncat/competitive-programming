//
//  11207 - The easiest way
//
//  Created by Fatima B on 10/14/15.
//  Copyright © 2015 nemo. All rights reserved.
//

/*
 In how many ways can you divide a rectangle into 4 equal squares?
  -------------      ----       ---------
  |  |  |  |  |  or  |  |   or  |   |   |
  -------------      ----       ---------
                     |  |       |   |   |
                     ----       ---------
                     |  |
                     ----
                     |  |
                     ----
*/

#include <iostream>
#include <assert.h>

double minimum(double w, double h) {
    if (w < h) { return w; } else { return h; }
}

double biggest_square(double w, double h) {
    double min = minimum(w/2.0, h/2.0);
    double max = min;

    min = minimum(h/4.0, w);
    if (min > max) { max = min; }

    min = minimum(w/4.0, h);
    if (min > max) { max = min; }

    return max;
}

int main() {
    int n;
    double w, h;
    while (scanf("%d", &n) != EOF) {
        if (n == 0) { break; }
        int best = 1;
        double max = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%lf %lf", &w, &h);
            double current = biggest_square(w, h);
            if (current > max) {
                best = i;
                max = current;
            }
        }
        printf("%d\n", best);
    }
    return 0;
}
