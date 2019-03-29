//
//  main.cpp
//  10003 - Cutting Sticks
//
//  Created by FB on 3/22/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>
#include <limits.h>

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int k = 0, n, c[60], opt[60][60];

    while (scanf("%d\n", &k) == 1) {
        if (k == 0) { break; }
        scanf("%d\n", &n);
        c[0] = 0; // cut at the start of the stick
        for (int i = 1; i <= n; i++) {
            scanf("%d", &c[i]);
        }
        n++;
        c[n] = k; // cut at the end of the stick

        // we have cuts 0, c_0, c_1, .... c_n_1, k
        for (int j = 1; j <= n; j++) {
             for (int i = j-1; i >=0; i--) {
                 //printf("range %d, %d\n", i, j);
                 if (j-i == 1) { // no cuts possible
                     opt[i][j] = 0;
                     continue;
                 } else {
                     opt[i][j] = INT_MAX;
                     // all possible cuts for [i,j]
                     for (int k = i+1; k < j; k++) {
                         if (opt[i][j] > opt[i][k] + opt[k][j]) {
                             opt[i][j] = opt[i][k] + opt[k][j];
                         }
                     }
                     opt[i][j] += c[j]-c[i];
                 }
             }
        }
        printf("The minimum cutting is %d.\n", opt[0][n]);
    }

    return 0;
}
