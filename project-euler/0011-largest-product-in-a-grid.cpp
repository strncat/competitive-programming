//
//
//  Project Euler
//
//  Created by FB on 8/02/24.
//  11 Largest Product in a Grid: https://projecteuler.net/problem=11
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#define N 20

int main(int argc, const char * argv[]) {
    // What is the greatest product of four adjacent numbers in the same direction 
    // (up, down, left, right, or diagonally) in the grid?

    unsigned long long a[N][N] = {
        8, 2, 22, 97, 38, 15, 0, 40, 0, 75, 4, 5, 7, 78, 52, 12, 50, 77, 91, 8,              // 0
        49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48, 4, 56, 62, 0,        // 1
        81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53, 88, 30, 3, 49, 13, 36, 65,       // 2
        52, 70, 95, 23, 4, 60, 11, 42, 69, 24, 68, 56, 1, 32, 56, 71, 37, 2, 36, 91,         // 3
        22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40, 28, 66, 33, 13, 80,      // 4
        24, 47, 32, 60, 99, 03, 45, 02, 44, 75, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50,      // 5
        32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70, 66, 18, 38, 64, 70,      // 6
        67, 26, 20, 68, 02, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40, 91, 66, 49, 94, 21,
        24, 55, 58, 05, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14, 88, 34, 89, 63, 72,
        21, 36, 23, 9, 75, 0, 76, 44, 20, 45, 35, 14, 0, 61, 33, 97, 34, 31, 33, 95,         // 9
        78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 04, 62, 16, 14, 9, 53, 56, 92,
        16, 39, 05, 42, 96, 35, 31, 47, 55, 58, 88, 24, 0, 17, 54, 24, 36, 29, 85, 57,
        86, 56, 0, 48, 35, 71, 89, 07, 05, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58,
        19, 80, 81, 68, 05, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77, 04, 89, 55, 40,      // 13
        4, 52, 8, 83, 97, 35, 99, 16, 07, 97, 57, 32, 16, 26, 26, 79, 33, 27, 98, 66,
        88, 36, 68, 87, 57, 62, 20, 72, 03, 46, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69,
        4, 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18, 8, 46, 29, 32, 40, 62, 76, 36,
        20, 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74, 4, 36, 16,
        20, 73, 35, 29, 78, 31, 90, 01, 74, 31, 49, 71, 48, 86, 81, 16, 23, 57, 5, 54,
        01, 70, 54, 71, 83, 51, 54, 69, 16, 92, 33, 48, 61, 43, 52, 01, 89, 19, 67, 48};     // 19

    unsigned long long product = 0, max_product = 0;
    int m = N; int n = N;
    int i = 0, j = 0, count = 0;

    // (1) left to right direction, part a
    for (int i = 0; i < m; i++) {
        int k = i;
        int j = 0;
        while (k < m-3 && j < n-3) {
            product = a[k][j] * a[k+1][j+1] * a[k+2][j+2] * a[k+3][j+3];
            if (max_product < product) {
                //printf("diagonal, index (%d, %d), %llu * %llu * %llu * %llu = %llu\n", k, j, a[k][j], a[k+1][j+1], a[k+2][j+2], a[k+3][j+3], product);
                max_product = product;
            }
            k++; j++;
        }
    }

    // (2) left to right, part b
    for (int j = 1; j < n; j++) {
        int s = j;
        int i = 0;
        while (i < m-3 && s < n-3) {
            product = a[i][s] * a[i+1][s+1] * a[i+2][s+2] * a[i+3][s+3];
            if (max_product < product) {
                max_product = product;
            }
            i++;
            s++;
        }
    }

    // (3) right to left, part a
    for (int i = 0; i < m; i++) {
        int k = i, j = 0;
        while (k >= 3 && j < n-3) {
            product = a[k][j] * a[k-1][j+1] * a[k-2][j+2] * a[k-3][j+3];
            if (max_product < product) {
                max_product = product;
            }
            k--;
            j++;
        }
    }

    // (4) right to left, part b
    for (int j = 1; j < n; j++) {
            int i = m - 1, s = j;
            while (i >= 3 && s < n-3) {
                product = a[i][s] * a[i-1][s+1] * a[i-2][s+2] * a[i-3][s+3];
                if (max_product < product) {
                    max_product = product;
                }
                i--;
                s++;
            }
        }

    // row check
    for (int i = 0; i < N; i++) {
        product = 1;
        for (int j = 0; j < N - 3; j++) {
            product = a[i][j] * a[i][j+1] * a[i][j+2] * a[i][j+3];
            if (max_product < product) {
              //  printf("row %d, index %d, %llu * %llu * %llu * %llu = %llu\n", i, j, grid[i][j], grid[i][j+1], grid[i][j+2], grid[i][j+3], product);
                max_product = product;
            }
        }
    }

    // column check
    for (int j = 0; j < N; j++) {
        product = 1;
        for (int i = 0; i < N - 3; i++) {
            product = a[i][j] * a[i+1][j+1] * a[i+2][j] * a[i+3][j];
            if (max_product < product) {
             //   printf("col %d, index %d, %llu * %llu * %llu * %llu = %llu\n", i, j, grid[i][j], grid[i+1][j], grid[i+2][j], grid[i+3][j], product);
                max_product = product;
            }
        }
    }


    printf("max_product = %llu\n", max_product);
    return 0;
}
