//
//
//  Project Euler
//
//  Created by FB on ?
//  Project Euler #7: 10001st prime https://projecteuler.net/problem=7
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#define N 1000000

int primes[N];

void sieve() {
    int s[N];
    // mark all numbers as potential primes
    for (int i = 0; i < N; i++) {
        s[i] = 1;
    }
    s[0] = s[1] = 0;
    int limit = sqrt(N);
    for (int p = 2; p <= limit; p++) {
        if (s[p]) {
            // mark all multiples of p as not prime
            for (int i = p*p; i < N; i += p) {
                s[i] = 0;
            }
        }
    }
    int index = 0;
    for (int i = 0; i < N; i++) {
        if (s[i] == 1) {
            primes[index++] = i;
        }
    }
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
        
    sieve();
    printf("%d\n", primes[10000]);
        
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    
    return 0;
}
