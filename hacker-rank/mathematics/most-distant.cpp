//
//  Hacker Rank
//  Most Distant
//
//  Created by Fatima B on 1/15/16.
//  Copyright © 2016 Fatima B. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <limits.h>


int main() {
    int n;
    scanf("%d", &n);

    long long x, y;
    long long xmax = -LONG_MAX, ymax = -LONG_MAX;
    long long xmin = LONG_MAX, ymin = LONG_MAX;

    //         p1
    //         |
    // p2------|------p0
    //         |
    //         p3

    // find p1, p2, p3 and p4

    for (int i = 0; i < n; i++) {
        scanf("%lld %lld", &x, &y);
        if (y == 0 && x < xmin) { xmin = x; }
        if (y == 0 && x > xmax) { xmax = x; }

        if (x == 0 && y < ymin) { ymin = y; }
        if (x == 0 && y > ymax) { ymax = y; }
    }

    // these can be an array and then computed in for loop but
    // I wanted it to be this way

    long long d1 = (xmax - xmin) * (xmax - xmin); // (p1, p3)
    long long d2 = (ymax - ymin) * (ymax - ymin); // (p2, p4)

    long long d3 = (xmax * xmax) + (ymax * ymax); // (p2, p3)
    long long d4 = (xmin * xmin) + (ymin * ymin); // (p3, p4)

    long long d5 = (xmax * xmax) + (ymin * ymin); // (p1, p4)
    long long d6 = (xmin * xmin) + (ymax * ymax); // (p2, p3)

    long long da = std::max(std::max(d2,d1), std::max(d3,d4));
    long long db = std::max(d5,d6);
    long long max = std::max(da, db);

    printf("%.12lf\n", sqrt(max));
    return 0;
}
