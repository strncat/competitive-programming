//
//  10168 - Summation of Four Primes
//  100 days challenge
//
//  Created by FB on 9/22/17.
//  Copyright © 2017 FB. All rights reserved.
//

// well I cheated I kept getting TLE and couldn't figure it out ..... bo

#include <iostream>
#include <math.h>

#define MAX 10000000

int prime[MAX];
int factor[4];

void pre_calculate_primes() {
    for (int i = 0; i < MAX; i++) {
        prime[i] = true;
    }
    prime[0] = prime[1] = false;

    for (int i = 2; i <= MAX/2; i++) {
        if (prime[i]) {
            for (int j = i+i; j < MAX; j+=i) {
                prime[j] = false;
            }
        }
    }
}

// too slow TLE
bool found = false;
void find(int n, int index) {
    if (found) { return; }

    if (index == 4 && n == 0) {
        printf("%d %d %d %d\n", factor[0], factor[1], factor[2], factor[3]);
        found = true;
        return;
    }
    for (int i = n; i >= 0; i--) {
        if (prime[i]) {
            factor[index] = i;
            find(n-i, index+1);
        }
    }
}

void goldback(int n) {
    for (int i = 2; i <= n; i++) {
        if (prime[i] && prime[n-i]) {
            printf("%d %d\n", i, n-i);
            return;
        }
    }
}


int main() {
    //freopen("example.in", "r", stdin);

    pre_calculate_primes();

    int n;
    while (scanf("%d", &n) != EOF) {
        if (n < 8) { printf("Impossible.\n"); continue; }
        if (n % 2) {
            printf("2 3 ");
            goldback(n-5);
        } else {
            printf("2 2 ");
            goldback(n-4);
        }
    }
    return 0;
}
