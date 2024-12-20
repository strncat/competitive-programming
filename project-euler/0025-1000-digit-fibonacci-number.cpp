//
//
//  Project Euler
//
//  Created by FB on 12/15/24.
//  1000 Digit Fibonacci Number https://projecteuler.net/problem=25
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#define N 100000

int add_two_arrays(int *a, int *b, int *sum, int an, int bn) {
    // least significant digit is at index 0
    int max = std::max(an, bn);
    int i = 0;
    int carry = 0;
    for (; i < max; i++) {
        int total = a[i] + b[i] + carry;
        sum[i] = total % 10;
        carry = total / 10;
    }
    sum[i] = carry;
    if (carry == 0) {
        return i;
    }
    return i+1;
}

int main(int argc, const char * argv[]) {
    // Find the sum of the digits in the number 100!
    
    int f1[N] = {0}, f2[N] = {0}, sum[N] = {0};
    memset(f1, 0, sizeof(f1[0])*N);
    memset(f2, 0, sizeof(f2[0])*N);
    
    f1[0] = 1;
    f2[0] = 1;
    int an = 1, bn = 1;
    
    for (int k = 0; k < 5000; k++) {
        int n = add_two_arrays(f1, f2, sum, an, bn);
        
        if (n == 1000) {
            printf("we are done this is index = %d\n", k+3);
            return 0;
        }

        // printing
        //printf("%d: ", k+3);
        //for (int j = n-1; j >= 0; j--) {
        //    printf("%d", sum[j]);
        //}
        //printf("\n");
        
        for (int i = 0; i < n; i++) {
            f1[i] = f2[i];
            f2[i] = sum[i];
        }
        an = bn;
        bn = n;
    }
}

