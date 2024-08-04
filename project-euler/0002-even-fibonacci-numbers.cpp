//
//  main.cpp
//  euler
//
//  Created by FB on 3/22/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>

// only calculate even fibonacci numbers
void fibonacci_even(unsigned long long *f) {
    f[0] = 0; f[1] = 2;
    for (int i = 2; i < 80; i++) {
        f[i] = 4*f[i-1] + f[i-2];
    }
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    unsigned long long sum, max, f[80] = {0};
    fibonacci_even(f);

    int tests;
    scanf("%d", &tests);

    while(tests--) {
        scanf("%llu", &max);
        sum = 0;
        int i = 0;
        while (true) {
            if (f[i] > max) {
                break;
            }
            sum += f[i];
            i++;
        }
        printf("%llu\n", sum);
    }
    return 0;
}
