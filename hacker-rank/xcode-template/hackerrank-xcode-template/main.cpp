//
//  main.cpp
//  hackerrank-xcode-template
//
//  Created by Fatima Broom on 3/5/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

//  Product -> Schemes -> Edit Scheme -> Set Working Directory
//  to Project Directory

#include <iostream>
#include <time.h>
#include <assert.h>

int main() {
    // measure time
    clock_t begin, end;
    double time_spent;
    begin = clock();

    freopen("example.in", "r", stdin);
    freopen("example.out", "w", stdout);

    int tests;
    scanf("%d\n", &tests);

    for (int t = 1; t <= tests; t++) {
        int n;
        scanf("%d", &n);
        printf("%d\n", n);
    }

    // time block
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    assert(time_spent < 3.1); // because in practice problems you only submit the output
    return 0;
}
