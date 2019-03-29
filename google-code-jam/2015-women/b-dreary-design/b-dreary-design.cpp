//
//  2015 Women - Problem B. Dreary Design
//  https://code.google.com/codejam/contest/9214486/dashboard#s=p1
//
//  Solution Source: https://code.google.com/codejam/contest/9214486/scoreboard?c=9214486#vf=1
//  Readme.md has more info
//
//  Created by Fatima Broom on 3/4/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <assert.h>

int main() {
    // measure time
    clock_t begin, end;
    double time_spent;
    begin = clock();

    freopen("in-large2.txt" , "r" , stdin);
    freopen("out-large2.txt" , "w" , stdout);

    int test_cases;
    scanf("%d", &test_cases);

    for (int t = 1; t <= test_cases; t++) {
        long long K, V, total = 0;
        scanf("%lld %lld", &K, &V);

        for (long long v = 0; v <= V; v++) {
            if (v == 0) {
                total += K + 1;
            } else if (v == 1) {
                total += K * 6;
            } else {
                total += (K - v + 1) * 6 * v;
            }
        }
        printf("Case #%d: %lld\n", t, total);
    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    assert(time_spent < 3.1); // because in practice problems you only submit the output
    return 0;
}
