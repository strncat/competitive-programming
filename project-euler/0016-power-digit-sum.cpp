//
//
//  Project Euler
//
//  Created by FB on 8/04/24.
//  16 Power Digit Sum https://projecteuler.net/problem=16
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#define N 500

int main(int argc, const char * argv[]) {
    // 2^50 = 1,125,899,906,842,624
    // 2^1000?

    clock_t begin, end;
    double time_spent;
    int q;
    begin = clock();

    int s[N], carry = 0;
    memset(s, 0, sizeof(s));
    s[N-1] = 2;

    for (int m = 1; m < 1000; m++) {
        // multiply 2
        int i = N-1;
        for (; i >= 0; i--) {
            int sum = s[i] * 2;
            s[i] = (sum + carry) % 10;
            carry = sum / 10;
        }
        s[i] += carry;
        carry = 0;
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        sum += s[i];
    }
    printf("sum = %d\n", sum);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("%f", time_spent);
        
    return 0;
}
//
