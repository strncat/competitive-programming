//
//  160 - Factors and Factorials
//  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=96
//
//  Created by Fatima Broom on 3/5/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>

#define MAX 105
int primes[MAX];
int count[MAX];

// generate prime numbers up to 100 (max prime factor according to the constraints)
void sieve() {
    for (int i = 0; i < MAX; i++) {
        primes[i] = 1;
    }
    primes[0] = primes[1] = 0;
    for (int i = 2; i <= MAX/2; i++) {
        if (primes[i]) {
            for (int j = i*i; j < MAX; j+=i) {
                primes[j] = 0;
            }
        }
    }
}

// generate the prime factorization of a number n
void prime_factorization(int n) {
    while ((n % 2) == 0) {
        count[2]++;
        n /= 2;
    }
    for (int i = 3; i * i <= n; i+=2) {
        // by the time i = 9 for example this won't be true
        // because we have already evaluated 3 (prime factors of 9)
        while (n % i == 0) {
            count[i]++;
            n = n / i;
        }
    }
    if (n > 2) {
        count[n]++;
    }
}

int main() {
    //freopen("one.in", "r", stdin);
    //freopen("one.out", "w", stdout);

    sieve();
    while (1) {
        int n;
        scanf("%d", &n);

        if (n == 0) { break; }

        // reset counts
        for (int i = 0; i < MAX; i++) {
            count[i] = 0;
        }

        for (int i = n; i > 0; i--) {
            prime_factorization(i);
        }

        int max_factor = 0;
        for (int i = MAX-1; i > 0; i--) {
            if (primes[i] && count[i]) {
                max_factor = i;
                break;
            }
        }

        int c = 0;
        printf("%3d! =", n);
        for (int i = 2; i < MAX; i++) {
            if (primes[i]) { // if a prime
                if (c == 15) {
                    printf("\n      ");
                }
                c++;
                printf("%3d", count[i]);
            }
            if (i == max_factor) {
                break;
            }
        }
        printf("\n");

    }
    return 0;
}
