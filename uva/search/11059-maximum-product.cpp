//
//  11059 - Maximum Product
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include <stack>

long long multiply_range(int *a, int start, int end) {
    long long product = 1;
    for (int i = start; i <= end; i++) {
        product = product * a[i];
    }
    return product;
}


int main() {
    //freopen("in.txt" , "r" , stdin);

    int test = 1, n;
    int a[20];

    while (scanf("%d", &n) != EOF) {

        for (int i = 0; i < n; i++) {
            scanf("%d",&a[i]); // −10 <= a[i] <= 10
        }

        long long max_product = 0;
        long long product = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                product = multiply_range(a, i, j);
                if (product > max_product) {
                    max_product = product;
                }
            }
        }
        printf("Case #%d: The maximum product is %lld.\n\n", test++, max_product);
    }
    return 0;
}
