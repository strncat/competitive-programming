//
//
//  Project Euler
//
//  Created by FB on 7/25/24.
//  10 Summation of Primes: https://projecteuler.net/problem=10
//
//

#include <iostream>
#define N 2000000

int main(int argc, const char * argv[]) {
    // The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17
    // Find the sum of all the primes below two million.
    //
    // From problem 7, generate all primes here:
    bool primes[N] = {true};
        memset(primes, true, sizeof(bool)*N);
        primes[0] = false;
        primes[1] = false;
        for (long int i = 2; i <= N/2; i++) { // or sqrt(N)
            if (primes[i]) {
                for (long int j = i*i; j < N; j += i) {
                    primes[j] = false;
                }
            }
        }
    unsigned long long sum = 0;
        for (int i = 0; i < N; i++) {
            if (primes[i]) {
                sum += i;
            }
        }

    printf("sum = %llu\n", sum);
    return 0;
}
