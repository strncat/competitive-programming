//
//
//  Project Euler
//
//  Created by FB on 7/25/24.
//  Special Pythagorean Triplet: https://projecteuler.net/problem=9
//
//

#include <iostream>
#define N 1000000

int main(int argc, const char * argv[]) {
    // A Pythagorean triplet is a set of three natural numbers a < b < c for which,
    // a^2 + b^2 = c^2
    // There exists exactly one Pythagorean triplet for which a + b + c = 1000
    // Find the product abc.
    //
    unsigned long long int a, b, c, max_product = 0;
    a = 1; b = 0; c = 0;

    for (a = 1; a < 1000 / 3; a++) {
        for (b = a+1; b < (1000 - a); b++) {
            c = 1000 - a - b;
            if (c*c == a*a + b*b) {
                max_product = a*b*c;
                printf("current max product %llu * %llu * %llu = %llu\n", a, b, c, max_product);
            }
        }
    }
    printf("max product = %llu\n", max_product);
    return 0;
}
