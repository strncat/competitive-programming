//
//
//  Project Euler
//
//  Created by FB on 01/17/25.
//  37 Truncatable Primes https://projecteuler.net/problem=37
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <cassert>
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

bool is_truncatable_left(int p, int d) {
    // for example for 3797, we want to check 379 -> 37 -> 3
    int m = p;
    while (m > 0) {
        if (!prime[m]) {
            return false;
        }
        m /= 10;
    }
    return true;
}

bool is_truncatable_right(int p, int d) {
    // 797 -> 97 -> 7
    int i = 0;
    while (p > 0) { //example: suppose p = 3797
        int divisor = pow(10, d-1-i); // divisor = 10^3 = 1000
        if (divisor <= 1) {break;}
        int most_sig = p/divisor; // 3797/1000 = 3
        int new_p = p - divisor * most_sig; // r = 3797 - 3*1000 = 797
        if (!prime[new_p]) {
            return false;
        }
        p = new_p;
        i++;
    }
    return true;
}

bool is_truncatable(int p) {
    // we must end with 3 or 7 only
    if (p % 10 != 3 && p % 10 != 7) {
        return false;
    }
    int d = floor(log10(p)) + 1;
    
    // (1) check the left to right direction
    if (!is_truncatable_left(p, d)) {
        return false;
    }
    // (2) now the other direction
    // 797 -> 97 -> 7
    if (!is_truncatable_right(p, d)) {
        return false;
    }
    return true;
}


int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    sieve();
    int sum = 0;
    // we start from 4 because 2, 3, 5 and 7 are not truncatable by definition
    for (int i = 4; i < prime_numbers.size(); i++) {
        if (is_truncatable(prime_numbers[i])) {
            printf("%d is truncatable\n", prime_numbers[i]);
            sum += prime_numbers[i];
        }
    }
    printf("sum = %d\n", sum);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    
    return 0;
}

