//
//  Problem A. Cody's Jams
//  https://code.google.com/codejam/contest/8274486/dashboard#s=p0
//
//  Created by Fatima Broom on 3/12/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <assert.h>
#include <vector>
#include <math.h>
#include <limits.h>

int main() {
    //freopen("in-example.txt", "r", stdin);
    //freopen("out-example.txt", "w", stdout);

    int tests;
    scanf("%d\n", &tests);
    for (int t = 1; t <= tests; t++) {
        int n;
        scanf("%d", &n);

        std::vector<long long int> prices;
        for (int i = 0; i < 2*n; i++) {
            int x;
            scanf("%d", &x);
            prices.push_back(x);
        }

        for (auto i = prices.begin(); i != prices.end(); i++) {
            long long int e = (4 * (*i)) / 3; // original price based on sale price (*i)
            auto t = std::find(prices.begin(), prices.end(), e);
            if (t != prices.end()) {
                prices.erase(t); // delete the original price
            } else {
                i++;
            }
            if (prices.size() == n) {
                break;
            }
        }
        printf("Case #%d: ", t);
        for (int i = 0; i < n; i++) {
            printf("%lld ", prices[i]);
        }
        printf("\n");
    }
    return 0;
}
