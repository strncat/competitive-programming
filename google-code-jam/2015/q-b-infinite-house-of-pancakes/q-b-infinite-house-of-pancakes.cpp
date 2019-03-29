//
//  2015 Problem B. Infinite House of Pancakes
//  https://code.google.com/codejam/contest/6224486/dashboard#s=p1
//
//  Created by Fatima Broom on 3/5/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <assert.h>
#include <vector>
#include <math.h>
#include <limits.h>

int min_time(std::vector<int> &plates) {
    int max = 0;
    for (int i = 0; i < plates.size(); i++) {
        if (max < plates[i]) {
            max = plates[i];
        }
    }

    // given 8,8,7,6,4,4 how to know if we should divide
    // take 8/2 = 4 as a new height for that height to be effective, everything else should be at this height
    // so we need to divide 8,8,7,6 (4 divisions) 4 + (8/2 = new height) = 8 so it won't matter if we divide
    // we can select another height = 6, for that we need 3 divisions 8,8,7 => 3 + 6 = 9 so we shouldn't divide

    int total = INT_MAX;
    for (int h = 1; h < max; h++) {
        int d = 0;
        for (int i = 0; i < plates.size(); i++) {
            if (plates[i] > h)  { // we have to divide
                d += ceil(plates[i]/(double)h) - 1;
            }
        }
        if (d + h < total) {
            total = d + h;
        }
    }
    if (max < total) { return max; }
    return total;
}

int main() {
    // measure time
    clock_t begin, end;
    double time_spent;
    begin = clock();

    freopen("in-large.txt", "r", stdin);
    freopen("out-large.txt", "w", stdout);

    int tests;
    scanf("%d\n", &tests);
    for (int t = 1; t <= tests; t++) {
        int n;
        scanf("%d", &n);
        std::vector<int> plates;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            plates.push_back(x);
        }
        printf("Case #%d: %d\n", t, min_time(plates));
    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    assert(time_spent < 3.1); // because in practice problems you only submit the output
    return 0;
}
