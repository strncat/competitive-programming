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

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    long long sum = 0;
    long long mod_value = 10000000000; // we want 10 digits
    for (int exponent = 1; exponent <= 1000; exponent++) {
        long long base = 1;
        for (int i = 1; i <= exponent; i++) {
            base = (base * exponent) % mod_value;
        }
        //printf("(%d)^(%d) mod 10^10 = %lld\n", exponent, exponent, base);
        sum += base;
    }
    printf("%lld\n", sum % mod_value);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}

