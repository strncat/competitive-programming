//
//  jam-template
//  Important: go to Product -> Scheme -> Edit Scheme
//  -> Options -> Working Directory (set it to the project directory)
//
//  Created by Fatima Broom on 2/27/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <assert.h>

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
    // measure time helpful for practice mode
    clock_t begin, end;
    double time_spent;
    begin = clock();

    freopen("example.in" , "r" , stdin);
    freopen("example.out" , "w" , stdout);

    int test_cases;
    scanf("%d", &test_cases);

    for (int t = 1; t <= test_cases; t++) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: Hello World %d", t, n);
    }

    // because in practice problems you only submit the output
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    assert(time_spent < 3.1);
    return 0;
}
