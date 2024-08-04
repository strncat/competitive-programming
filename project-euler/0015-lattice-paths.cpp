//
//
//  Project Euler
//
//  Created by FB on 8/03/24.
//  15 Lattice Paths https://projecteuler.net/problem=15
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#define N 1000001

int main(int argc, const char * argv[]) {

    unsigned long long ways[25][25];
    memset(ways, 0, sizeof(ways));
    
    ways[0][0] = 0;
    ways[1][0] = 1;
    ways[0][1] = 0;
    
    for (int i = 1; i < 25; i++) {
        for (int j = 1; j < 25; j++) {
            ways[i][j] = ways[i-1][j] + ways[i][j-1];
        }
    }
    
    printf("reach(21,21) in %llu steps\n", ways[21][21]);
    return 0;
}

