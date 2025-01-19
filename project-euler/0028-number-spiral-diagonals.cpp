//
//
//  Project Euler
//
//  Created by FB on 01/11/25.
//  28 Number Spiral Diagonals https://projecteuler.net/problem=28
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>

int sum_quadrant(int cell, int diff) {
    int add = 8, sum = 0;
    for (int i = 1; i <= 500; i++) {
        sum += cell; // add the cell value
        cell += diff; // cell value will increase by the diff
        diff += add; // the diff will increase by 8 each iteration
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    long total_sum = 0;
    total_sum += sum_quadrant(7, 14); // Top Left Diagonal
    total_sum += sum_quadrant(9, 16); // Top Right Diagonal
    total_sum += sum_quadrant(3, 10); // Bottom Right Diagonal
    total_sum += sum_quadrant(5, 12); // Bottom Left Diagonalå
    printf("%ld\n", total_sum + 1);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    
    return 0;
}

