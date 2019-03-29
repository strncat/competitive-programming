//
//  code forces
//  B. Dinner with Emma
//
//  Created by Fatima B on 1/11/16.
//  Copyright © 2016 Fatima B. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <limits.h>

int main() {
    long cost, max = 0;
    int n, m;

    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {

        // find minimum per row
        long min_row = LONG_MAX;
        for (int j = 0; j < m; j++) {
            scanf("%ld", &cost);
            if (cost < min_row) {
                min_row = cost;
            }
        }

        // find the maximum minimum
        if (min_row > max) {
            max = min_row;
        }
    }

    printf("%ld\n", max);

    return 0;
}
