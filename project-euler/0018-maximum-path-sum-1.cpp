//
//
//  Project Euler
//
//  Created by FB on 8/04/24.
//  18 Maximum Path Sum I https://projecteuler.net/problem=18
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#define N 15

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    int sum[N][N];
    memset(sum, 0, sizeof(sum));
    
    /* // example
    int a[5][5] = {{3, 0},
                   {7, 4, 0},
                   {2, 4, 6, 0},
                   {8, 5, 9, 3, 0}};
    */
    

    int a[N][N+1] = {{75},
        {95, 64, 0},
        {17, 47, 82, 0},
        {18, 35, 87, 10, 0},
        {20, 4, 82, 47, 65, 0},
        {19, 1, 23, 75, 3, 34, 0},
        {88, 2, 77, 73, 7, 63, 67, 0},
        {99, 65, 4, 28, 6, 16, 70, 92, 0},
        {41, 41, 26, 56, 83, 40, 80, 70, 33, 0},
        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0},
        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0},
        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0},
        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0},
        {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0},
        {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23, 0}};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    printf("\n\n");
    
    // base case
    sum[0][0] = a[0][0];
    for (int i = 1; i < N; i++) {
        sum[i][0] = a[i][0] + sum[i-1][0];
    }
    
    // inductive case
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            sum[i][j] = std::max(sum[i-1][j-1], sum[i-1][j]) + a[i][j];
        }
    }
    
    // debug
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }

    unsigned long long max_sum = 0;
    for (int j = 0; j < N; j++) {
        if (max_sum < sum[N-1][j]) {
            max_sum = sum[N-1][j];
        }
    }
    // max sum = 1074
    printf("max sum = %llu\n", max_sum);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
        
    return 0;
}
//
