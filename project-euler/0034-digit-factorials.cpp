//
//
//  Project Euler
//
//  Created by FB on 01/14/25.
//  Problem 34: Digit Factorials https://projecteuler.net/problem=34
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <functional>
#include <utility>

int f[10];

void calc_factorial() {
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i < 10; i++) {
        f[i] = i * f[i-1];
    }
}

void print_expansion(long long num) {
    long long sum = 0;
    long long n = num;
    printf("num = %lld\n", num);
    while (num > 0 && sum <= n) {
        int d = num%10;
        int p = f[d];
        sum += p;
        num /= 10;
        printf("(%d! = %d),", d, p);
    }
    printf("\n\n");
}

int main(int argc, const char * argv[]) {
    calc_factorial();

    // 9! * 10 = 3628800
    // 0! + 0! + 0! + 1! + 1! = 2
    int total_sum = 0;
    for (long long n = 3; n <= 3628800; n++) {
        long long sum = 0;
        long long num = n;
        while (num > 0 && sum <= n) {
            int d = num%10;
            int p = f[d];
            sum += p;
            num /= 10;
        }
        if (sum == n) {
            total_sum += sum;
            print_expansion(n);
        }
    }
    printf("%d\n", total_sum);
    return 0;
}

