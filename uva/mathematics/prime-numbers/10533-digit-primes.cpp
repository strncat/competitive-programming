//
//  10533 - Digit Primes
//
//  Created by Fatima B on 10/10/15.
//  Copyright © 2015 nemo. All rights reserved.

#include <iostream>
#include <math.h>
#include <assert.h>

#define MAX 1000001

bool prime[MAX];
int numprimes[MAX];;

int digit_sum(int n) {
    int sum = 0;
    while (n) {
        sum += (n%10);
        n /= 10;
    }
    return sum;
}

void sieve() {
    for (int i = 0; i < MAX; i++) { prime[i] = true; }
    prime[0] = prime[1] = false;

    int squareroot = sqrt(MAX) + 1;
    for (int i = 2; i < squareroot; i++) {
        if (prime[i]) {
            for (int j = i*i; j < MAX; j+=i) {
                prime[j] = false;
            }
        }
    }

    int n = 0;
    for (int i = 2; i < MAX; i++) {
        if (prime[i] && prime[digit_sum(i)]) { // is a digit prime
            n++;
        }
        numprimes[i] = n; // number of digit primes betwee 0 and i (inclusive)
    }
}

void tests() {
    int a[9][2] = {{1193, 2731}, {2467, 4390}, {5210, 9157}, {4390, 7878},
        {4392, 7890}, {13, 13}, {6571, 7121}, {6572, 6871}, {87, 567}};
    int correct[9] = {104, 114, 199, 186, 186, 0, 30, 15, 42};
    for (int i = 0; i < 9; i++) {
        assert(numprimes[a[i][1]] - numprimes[a[i][0]-1] == correct[i]);
    }
}

int main() {
    int test_cases, t1, t2;
    std::string s;

    sieve(); // 30,123 items
    //tests();

    scanf("%d", &test_cases);
    while (test_cases--) {
        scanf("%d %d", &t1, &t2);
        printf("%d\n", numprimes[t2] - numprimes[t1 - 1]); // t1-1 because t1 should be included
    }
    return 0;
}
