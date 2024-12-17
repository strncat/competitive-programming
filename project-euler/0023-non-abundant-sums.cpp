//
//
//  Project Euler
//
//  Created by FB on 12/12/24.
//  23 Non-Abundant Sums https://projecteuler.net/problem=23
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#define N 28124

bool abundant[N];
std::vector<int> abundant_numbers;

bool is_abundant(int n) {
    //printf("n = %d\n", n);
    int max = sqrt(n);
    int divisors_sum = 0;
    for (int i = 1; i <= max; i++) {
        if (n % i == 0) { // it's a divisor
            divisors_sum += i;
            if (n / i != i && i != 1) { // add the other divisor
                divisors_sum += n/i;
            }
        }
    }
    if (divisors_sum > n) {
        return true;
    }
    return false;
}

int main(int argc, const char * argv[]) {
    //freopen("triangle.txt" , "r" , stdin);
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    memset(abundant, 0, sizeof(abundant[0])*N);

    // any number > 28123 can be written as the sum of two abundant numbers
    // BUT
    // the greatest number that cannot be expressed as the sum of two abundant numbers is less
    // than 28123 ...
    // We want the sum of all positive integers that cannot be written as the sum of two abundant numbers
    

    for (int i = 1; i <= N; i++) {
        if (is_abundant(i)) {
            abundant[i] = true;
            abundant_numbers.push_back(i);
        }
    }

    int sum = 0;
    for (int i = 1; i < 28123; i++) {
        // Find if i can be expressed as a sum of two abundant numbers
        bool abundant_sum = false;
        for (int j = 0; j < abundant_numbers.size() && abundant_numbers[j] < i; j++) {
            if (abundant[i - abundant_numbers[j]]) {
                abundant_sum = true;
                printf("%d can be expressed as %d + %d\n", i, abundant_numbers[j], i - abundant_numbers[j]);
                break;
            }
        }
        if (!abundant_sum) {
            sum += i;
        }
    }
    
    printf("%d\n", sum);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
