//
//  10310 - Dog and Gopher
//  100 days challenge
//
//  Created by FB on 9/22/17.
//  Copyright © 2017 FB. All rights reserved.
//
//  pretty straight forward, calculate the distances!

#include <iostream>
#include <math.h>
#include <algorithm>

int main() {
    //freopen("example.in" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    double hole[11000][2];

    int n, index = 0;
    while (scanf("%d", &n) != EOF) {
        double xdog, ydog, xgopher, ygopher;
        scanf("%lf %lf %lf %lf", &xgopher, &ygopher, &xdog, &ydog);

        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &hole[i][0], &hole[i][1]);
        }

        bool found = false;
        for (int i = 0; i < n; i++) {
            double d1 = sqrt((xdog-hole[i][0])*(xdog-hole[i][0]) + (ydog-hole[i][1])*(ydog-hole[i][1]));
            double d2 = sqrt((xgopher-hole[i][0])*(xgopher-hole[i][0]) + (ygopher-hole[i][1])*(ygopher-hole[i][1]));

            if (d2*2 <= d1) {
                found = true;
                index = i;
                break;
            }
        }
        if (!found) {
            printf("The gopher cannot escape.\n");
        } else {
            printf("The gopher can escape through the hole at (%.3lf,%.3lf).\n", hole[index][0], hole[index][1]);
        }
    }
    return 0;
}
