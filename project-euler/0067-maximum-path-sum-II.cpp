//
//
//  Project Euler
//
//  Created by FB on 8/04/24.
//  67 Maximum Path Sum II https://projecteuler.net/problem=67
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#define N 100

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    freopen("triangle.txt" , "r" , stdin);
    
    int a[N][N];
    unsigned long long sum[N][N];
    memset(sum, 0, sizeof(sum));
   

    int count = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < count; j++) {
            scanf("%d", &a[i][j]);
        }
        a[i][count] = 0;
        count++;
    }

    // base case
    sum[0][0] = a[0][0];
    for (int i = 1; i < N; i++) {
        sum[i][0] = a[i][0] + sum[i-1][0];
    }
    
    // inductive case
    count = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 1; j <= count; j++) {
            sum[i][j] = std::max(sum[i-1][j-1], sum[i-1][j]) + a[i][j];
        }
        count++;
    }

    unsigned long long max_sum = 0;
    for (int j = 0; j < N; j++) {
        if (max_sum < sum[N-1][j]) {
            max_sum = sum[N-1][j];
        }
    }
    // max sum = 7273
    printf("max sum = %llu\n", max_sum);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
