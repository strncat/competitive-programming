//
//
//  Project Euler
//
//  Created by FB on 01/13/25.
//  23 Digit Fifth Powers https://projecteuler.net/problem=30
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <functional>
#include <utility>


int main(int argc, const char * argv[]) {

    // 9^5 + 9^5 + 9^5 + 9^5 + 9^5 = 5*9^5 = 295,245
    // 0^5 + 0^5 + 0^5 + 1^5 + 1^5 = 2
    int total_sum = 0;
    for (int n = 2; n <= 295245; n++) {
        long sum = 0;
        int num = n;
        while (num > 0 && sum <= n) {
            int d = num%10;
            int p = pow(d, 5);
            sum += p;
            num /= 10;
        }
        if (sum == n) {
            total_sum += sum;
        }
    }
    printf("%d\n", total_sum);
    return 0;
}

