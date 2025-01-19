//
//
//  Project Euler
//
//  Created by FB on 01/11/25.
//  35 Circular Primes https://projecteuler.net/problem=35
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#define N 1000000

int prime[N];
std::vector<int> prime_numbers;

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
    for (int i = 0; i < N; i++) {
        if (prime[i]) {
            prime_numbers.push_back(i);
        }
    }
}

int count_digits(int n) {
    int d = 0;
    while (n > 0) {
        n /= 10;
        d++;
    }
    return d;
}
bool is_circular(int p) {
    // we want to rotate the digits n times where n is the number of digits
    // so 197 -> 719 -> 971
    int n = count_digits(p);
    int m = pow(10, n-1);
    for (int i = 0; i < n; i++) {
        int d = p%10; // save the last digit d
        p /= 10; // git rid of d in p
        p += d*m; // add the last digit*m to p
        if (!prime[p]) {
            return false; // not a circular number
        }
    }
    return true;
}


int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    sieve();
    int count = 4; // There are 4 primes < 10
    for (int i = 4; i < prime_numbers.size(); i++) { // prime_numbers[4] = 11
        int p = prime_numbers[i];
        if (is_circular(p)) {
            count++;
        }
    }
    printf("total count = %d\n", count);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    
    return 0;
}

