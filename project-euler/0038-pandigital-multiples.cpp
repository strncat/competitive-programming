//
//
//  Project Euler
//
//  Created by FB on 01/16/25.
//  Problem 38: Pandigit Multiplies https://projecteuler.net/problem=38
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


bool is_pandigital(int k) {
    int digits[10] = {0};
    // In each iteration, we will multiply k by a value from the range (1,...,n).
    // Since we only have 9 digits, we won't ever need more than 9 products.
    for (int n = 1; n < 9; n++) {
        int product = k * n;

        // (1) count the digits of this product and exit any time we see a repeated digit
        while (product > 0) {
            int remainder = product % 10;
            digits[remainder]++;
            product /= 10;
            if (digits[remainder] > 1) {
                return false; // no need to test further since we have a repeated digit
            }
        }
        // (2) before checking the next product, check if we reached the pandigital state
        int i = 1;
        while (i < 10 && digits[i++] == 1) {}
        if (i == 10 && digits[0] == 0) {
            return true; // we are a pandigital number, let's exit
        }
    }
    return false; // we failed but we should not reach this state with the above checks
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();

    int max = -1;
    for (int i = 9999; i >= 1; i--) {
        if (is_pandigital(i)) {
            max = i;
            break;
        }
    }
    int count = 0, temp = max;
    while (temp) { // count the digits in max
        count++;
        temp /= 10;
    }
    printf("largest pandigital number is ");
    for (int i = 1; i <= 9/count; i++) {
        printf("%d", max*i);
    }
    printf("\n");

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
