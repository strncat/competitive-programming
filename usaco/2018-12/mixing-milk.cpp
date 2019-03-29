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
    freopen("mixmilk.in", "r", stdin); // mixmilk.in
    freopen("mixmilk.out", "w", stdout); // mixmilk.out

    int n = 3;
    int milk[3] = {0}, capacity[3] = {0};

    for (int i = 0; i < n; i++) {
        scanf("%d %d\n", &capacity[i], &milk[i]);
    }

    int from = 0, to = 1;
    for (int i = 0; i < 100; i++) {
        int new_milk =  milk[from] + milk[to];
        int diff = new_milk - capacity[to];
        if (diff > 0) {
            milk[from] = diff;
            milk[to] = new_milk - diff;
        } else {
            milk[from] = 0;
            milk[to] = new_milk;
        }
        from = (from+1)%n;
        to = (to+1)%n;
    }

    for (int i = 0; i < n; i++) {
        printf("%d\n", milk[i]);
    }

    return 0;
}
