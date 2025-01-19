//
//
//  Project Euler
//
//  Created by FB on 01/18/25.
//  43 Sub-string Divisibility https://projecteuler.net/problem=43
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
    
    long sum = 0;
    std::vector<int> d = {0,1,2,3,4,5,6,7,8,9};
    do {
        // (1) d1d2d3
        if (d[3] % 2) { // not divisble by 2
            continue;
        }
        
        // (2) d2d3d4
        int s = d[2] + d[3] + d[4];
        if (s % 3) { // not divisble by 3
            continue;
        }
        
        // (3) d3d4d5
        if (d[5] != 0 && d[5] != 5) { // not divisble by 5
            continue;
        }
        
        // (4) d4d5d6
        int rest = 10*d[4] + d[5];
        if ((d[6]*5 + rest) % 7) { // not divisble by 7
            continue;
        }
        
        // (5) d5d6d7
        rest = 10*d[5] + d[6];
        if ((d[7]*10 + rest) % 11) { // not divisble by 11
            continue;
        }
        
        // (6) d6d7d8
        rest = 10*d[6] + d[7];
        if ((d[8]*4 + rest) % 13) { // not divisble by 13
            continue;
        }
        
        // (6) d7d8d9
        rest = 10*d[7] + d[8];
        if ((d[9]*12 + rest) % 17) { // not divisble by 17
            continue;
        }
        
        long p = d[9];
        long m = 1;
        for (int i = 8; i >= 0; i--) {
            m *= 10;
            p += (d[i] * m);
        }
        sum += p;
        
    }
    while (std::next_permutation(d.begin(), d.end()));
    
    printf("sum is %ld\n", sum);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}

