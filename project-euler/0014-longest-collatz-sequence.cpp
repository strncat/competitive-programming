//
//
//  Project Euler
//
//  Created by FB on 8/02/24.
//  14 Longest Collatz Sequence: https://projecteuler.net/problem=14
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <unordered_map>
#define N 1000001

std::unordered_map<unsigned long long, int> map;

int collatz_count(unsigned long long n) {
    if (map.find(n) != map.end()) {
        return map[n];
    }

    if (n == 1) { // we're done, base case
        return 1;
    } else if (n > 1) {
        if ((n&1) == 0) { // even
            map[n] = collatz_count(n/2) + 1;
        } else { // odd
            map[n] = collatz_count(3*n + 1) + 1;
        }
    }
    return map[n];
}

int main(int argc, const char * argv[]) {
    // Which starting number, under one million, produces the longest chain?
    map[1] = 1;
    map[2] = 2;

    int index = 0, max_count = 0, count = 0;
    for (int n = 1; n <= 1000000; n++) {
        count = collatz_count(n);
        if (count > max_count) {
            max_count = count;
            index = n;
        }
    }
    printf("index = %d, max_count = %d\n", index, max_count);
    return 0;
}
// index = 837799, max_count = 525
