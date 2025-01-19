//
//
//  Project Euler
//
//  Created by FB on 01/14/25.
//  Problem 32: Pandigital Products https://projecteuler.net/problem=32
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <functional>
#include <utility>
#include <set>


int is_pandigital(int i, int j) {
    int digits[10] = {0};
    int num = i * j;
    while (i > 0) {
        digits[i % 10]++;
        i /= 10;
    }
    while (j > 0) {
        digits[j % 10]++;
        j /= 10;
    }
    while (num > 0) {
        digits[num % 10]++;
        num /= 10;
    }
    for (int i = 1; i < 10; i++) {
        if (digits[i] != 1) {
            return false;
        }
    }
    if (digits[0] != 0) { return false; }
    return true;
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();

    std::unordered_map<int,bool> pandigital;
    int sum = 0;
    for (int i = 1; i < 99; i++) {
        for (int j = 10; j < 9999; j++) {
            if (i*j > 9999) {
                continue;
            }
            if (is_pandigital(i,j)) {
                if (pandigital.find(i*j) == pandigital.end()) {
                    //printf("%d * %d = %d is pandigital\n", i, j, i*j);
                    sum += i*j;
                    pandigital[i*j] = true;
                }
            }
        }
    }
    printf("sum = %d\n", sum);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
