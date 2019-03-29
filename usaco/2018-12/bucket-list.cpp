//
//  main.cpp
//  uhunt
//
//  Created by FB on 12/14/18.
//  Copyright © 2018 FB. All rights reserved.
//

#include <iostream>
#include <stdio.h>

int main() {
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);

    int m[100][1001] = {0};

    int n;
    scanf("%d\n", &n);

    int s, t, b;
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d\n", &s, &t, &b);
        for (int j = s; j <= t; j++) {
            m[i][j] = b;
        }
    }

    int max = 0;
    for (int j = 1; j <= 1000; j++) { // time 1 to 1001
        int sum = 0;
        for (int i = 0; i < 100; i++) {
            sum += m[i][j];
        }
        if (sum > max) {
            max = sum;
        }
    }

    printf("%d\n", max);

    return 0;
}
