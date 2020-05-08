//
//  main.cpp
//  12455 - Bars
//
//  Created by FB on 7/12/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>

// try all possible combinations, brune whenever sum goes below zero
bool subset_sum(int *a, int i, int n, int p) {
    if (n == 0) {
        return true;
    } else if (n < 0 || i > p-1) {
        return false;
    }
    return subset_sum(a, i+1, n-a[i], p) || subset_sum(a, i+1, n, p);
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int p;
        scanf("%d", &p);

        int a[20];
        for (int i = 0; i < p; i++) {
            scanf("%d", &a[i]);
        }

        // we want to find if any subset in a sums to n
        if (subset_sum(a, 0, n, p)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
