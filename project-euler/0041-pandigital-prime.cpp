//
//
//  Project Euler
//
//  Created by FB on 01/18/25.
//  41 Pandigital Prime https://projecteuler.net/problem=41
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <cassert>
#define N 10000000

int prime[N];

void sieve() {
    // mark all numbers as potential primes
    for (int i = 0; i < N; i++) {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    int limit = sqrt(N);
    for (int p = 2; p <= limit; p++) {
        if (prime[p]) {
            // mark all multiples of p as not prime
            for (int i = p*p; i < N; i += p) {
                prime[i] = 0;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    sieve();
    
    long max = 0;
    std::vector<int> a = {1,2,3,4,5,6,7};
    do {
        long p = a[0];
        int m = 1;
        for (int i = 1; i < 7; i++) {
            m *= 10;
            p += (a[i] * m);
        }
        if (prime[p] && p > max) {
            max = p;
        }
        
    }
    while (std::next_permutation(a.begin(), a.end()));
    
    printf("max pandigital prime is %ld\n", max);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}

