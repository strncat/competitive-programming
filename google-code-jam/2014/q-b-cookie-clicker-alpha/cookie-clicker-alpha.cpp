//
//  Problem B. Cookie Clicker Alpha
//  https://code.google.com/codejam/contest/2974486/dashboard#s=p1
//
//  Created by Fatima Broom on 2/27/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <assert.h>
#include <vector>
#include <unordered_map>

#define EPSILON 0.000001

// https://code.google.com/codejam/faq.html#floating_point
bool isEqual(double x, double y) {
    if (-EPSILON <= x - y && x - y <= EPSILON) {
        return true;
    }
    // is x or y too close to zero?
    if ((-EPSILON <= x && x <= EPSILON) || (-EPSILON <= y && y <= EPSILON)) {
        return false;
    }
    return ((-EPSILON <= (x - y) / x && (x - y) / x <= EPSILON) ||
            (-EPSILON <= (x - y) / y && (x - y) / y <= EPSILON) );
}

int main() {
    // measure time
    clock_t begin, end;
    double time_spent;
    begin = clock();

    freopen("in-large.txt" , "r" , stdin);
    freopen("out-large.txt" , "w" , stdout);

    int n;
    scanf("%d", &n);

    for (int t = 1; t <= n; t++) {

        double X; // the final goal
        double F; // the additional rate gained by buying a new farm
        double C; // the price of buying a new farm
        double rate = 2.0; // the rate at which we gain cookies per second
        double total_seconds = 0.0; // total seconds used to reach the goal

        scanf("%lf %lf %lf", &C, &F, &X);

        while (1) {
            // at every step we compare the number of seconds to reach the goal vs
            // the number of seconds to buy a new farm + the number of seconds to reach the goal with the new rate
            double seconds_to_goal = X/rate;
            double seconds_to_farm = C/rate + (X/(rate+F));

            if (seconds_to_farm < seconds_to_goal) {
                total_seconds += (C/rate);
                rate += F;
            } else {
                total_seconds += seconds_to_goal;
                break; // we're done
            }
        }
        printf("Case #%d: %.7lf\n", t, total_seconds);
    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    assert(time_spent < 3.1); // because in practice problems you only submit the output
    return 0;
}
