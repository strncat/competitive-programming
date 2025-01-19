//
//
//  Project Euler
//
//  Created by FB on 01/11/25.
//  27 Quadratic Primes https://projecteuler.net/problem=27
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#define N 1000000

int primes[N];

void sieve() {
    // mark all numbers as potential primes
    for (int i = 0; i < N; i++) {
        primes[i] = 1;
    }
    primes[0] = primes[1] = 0;
    int limit = sqrt(N);
    for (int p = 2; p <= limit; p++) {
        if (primes[p]) {
            // mark all multiples of p as not prime
            for (int i = p*p; i < N; i += p) {
                primes[i] = 0;
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    // table to check quickly whether a number is prime or not
    sieve();
    int max_count = 0, max_a = 0, max_b = 0;
    for (int a = -999; a < 1000; a++) {
        for (int b = -999; b < 1000; b++) {
            // f(n) = n^2 + an + b
            // f(0) = b is the initial value
            int n = 0;
            int fn = b;
            int count = 0;
            while (primes[fn]) {
                count++;
                n++;
                fn = n*n + a*n + b;
            }
            if (count > max_count) {
                max_count = count;
                max_a = a;
                max_b = b;
            }
        }
    }
    printf("a = %d, b = %d, a*b = %d\n", max_a, max_b, max_a * max_b);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}

