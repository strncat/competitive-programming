//
//  583 - Prime Factors
//  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=524
//
//  Created by Fatima Broom on 3/5/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

bool is_prime(int n) {
    bool negative = false;
    if (n < 0) {
        n *= -1;
        negative = true;
    }
    if (n <= 1 || n % 2 == 0) { return false; } // not prime

    int m = sqrt(n);
    for (int i = 3; i <= m; i += 2) {
        if (n % i == 0) {
            return false; // not prime
        }
    }
    if (negative) {
        printf("-%d = -1 x %d\n", n, n);
    } else {
        printf("%d = %d\n", n, n);
    }
    return true;
}

void prime_factorization(int n) {
    printf("%d = ", n);

    std::vector<int> factors;

    if (n < 0) {
        n *= -1;
        factors.push_back(-1);
    }

    while (n % 2 == 0) {
        factors.push_back(2);
        n = n/2;
    }

    for (int i = 3; i * i <= n; i++) {
        while (n % i == 0) {
            factors.push_back(i);
            n = n / i;
        }
    }

    if (n > 1) {
        factors.push_back(n);
    }

    printf("%d", factors[0]);
    for (int i = 1; i < factors.size(); i++) {
        printf(" x %d", factors[i]);
    }
    printf("\n");
}

int main() {
    //freopen("one.in", "r", stdin);
    //freopen("example.in", "r", stdin);
    //freopen("all.in", "r", stdin);

    while (1) {
        int n;
        scanf("%d\n", &n);
        if (n == 0) { break; }
        bool prime = is_prime(n); // otherwise TLE
        if (!prime) {
            prime_factorization(n);
        }
    }
    return 0;
}
