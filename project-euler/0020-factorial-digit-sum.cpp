//
//
//  Project Euler
//
//  Created by FB on 12/11/24.
//  20 Factorial Digit Sum: https://projecteuler.net/problem=20
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#define N 160

void add_one(int *a, int an) {
    // least significant digit is at index 0
    a[0] += 1;
    for (int i = 0; i < an; i++) {
        int sum = a[i];
        if (sum < 10) {
            break;
        }
        a[i] = sum % 10;
        a[i+1] += sum / 10;
    }
}

void multiply(int *a, int an, int *b, int bn, int *result) {
    for (int i = 0; i < N; i++) { // an + bn
        result[i] = 0;
    }
    // least significant digit is at index 0
    for (int i = 0; i < an; i++) {
        for (int j = 0; j < bn; j++) {
            int product = a[i] * b[j];
            int position = i + j;
            int carry_position = i + j + 1;

            int sum = product + result[position];

            result[position] = sum % 10;
            result[carry_position] += sum / 10;
        }
    }
}

int main(int argc, const char * argv[]) {
    // Find the sum of the digits in the number 100!

    int a[N], b[N], result[N+N];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    memset(result, 0, sizeof(result));

    // 2*3*4 = 24
    result[0] = 4;
    result[1] = 2;
    a[0] = 4;

    for (int num = 5; num <= 100; num++) {
        // copy result to b
        for (int i = 0; i < N; i++) {
            b[i] = result[i];
        }
        add_one(a, N);
        multiply(a, N, b, N, result);
    }

    int sum = 0;
    for (int i = N-1; i >= 0; i--) {
        sum += result[i];
    }
    printf("sum = %d\n, ", sum);


    return 0;
}

