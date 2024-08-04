//
//
//  Project Euler
//
//  Created by FB on 8/02/24.
//  Highly Divisible Triangular Number: https://projecteuler.net/problem=12
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#define N 20000

int count_factors(unsigned long long n) {
    unsigned long long sq = sqrt(n);
    int count = 0;
    for (int i = 1; i <= sq; ++i) {
        if (n % i == 0) {
            count++;
            if (i != n/i) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, const char * argv[]) {
    // What is the value of the first triangle number to have over five hundred divisors?

    unsigned long long sum = 0;
    for (int i = 1; i < N; i++) {
        sum += i;
        int f = count_factors(sum);
        if (f > 500) {
            printf("Triangle number #%d = %llu and %d factors\n", i, sum, f);
            break;
        }

    }


    printf("max_product = %llu\n", sum);
    return 0;
}
