//
//  main.cpp
//  uhunt
//
//  541 - Error Correction
//  2017/02/20
//
//

#include <iostream>
#include <string.h>

int main() {
    //freopen("sample.in", "r", stdin);
    int n, a, row[101], col[101];
    while(scanf("%d", &n) == 1 && n != 0) {

        memset(row, 0, sizeof(row));
        memset(col, 0, sizeof(col));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a);
                if (a) {
                    row[i]++;
                    col[j]++;
                }
            }
        }

        int sum_rows = 0;
        int sum_cols = 0;
        int odd_row = -1;
        int odd_col = -1;

        int i = 0;
        for (i = 0; i < n; i++) {
            if (row[i] % 2) { sum_rows++; odd_row = i;}
            if (col[i] % 2) { sum_cols++; odd_col = i;}
            if (sum_rows > 1 || sum_cols > 1) {
                break;
            }
        }

        if (i < n) {
            printf("Corrupt\n");
        } else if (sum_rows == 0 && sum_cols == 0) {
            printf("OK\n");
        } else {
            printf("Change bit (%d,%d)\n", odd_row+1, odd_col+1);
        }
    }
    return 0;
}