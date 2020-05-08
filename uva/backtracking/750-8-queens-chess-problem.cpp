//
//  main.cpp
//  uhunt
//
//  750 - 8 Queens Chess Problem
//  2017/03/01
//
//

#include <iostream>
#include <vector>

using std::vector;

void construct_candidate(int *a, int k, int n, int *c, int *ncandidates, int row, int col) {
    for (int i = 1; i <= n; i++) { // possible rows
        bool legal_move = true;
        for (int j = 1; j < k; j++) {
            if (a[j] == i) { // row threat
                legal_move = false;
            }
            if (abs(a[j] - i) == abs(j - k)) { // diagonal threat
                legal_move = false;
                break;
            }
        }

        // also check the extra preset position
        if (i == row || abs(i - row) == abs(k - col)) { // fixed position threat
            legal_move = false;
        }


        if (legal_move == true) {
            c[(*ncandidates)++] = i;
        }
    }
}

int counter = 1;
void backtrack(int *a, int k, int n, int row, int col) {
    if (n == k) { // solution
        printf("%2d      ", counter++);
        for (int i = 1; i < n ; i++) {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[n]);
        return;
    }

    int c[n];
    int ncandidates = 0;

    k = k + 1;
    if (k == col) { // skip this col since a queen is already placed in it (given to us constraint r,c)
        backtrack(a, k, n, row, col);
    } else {
        construct_candidate(a, k, n, c, &ncandidates, row, col);
        for (int i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            backtrack(a, k, n, row, col);
        }
    }
}

void nqueens(int n, int row, int col) {
    int a[n+1];
    a[col] = row;
    counter = 1;
    backtrack(a, 0, n, row, col);
}

int main() {
    //freopen("sample.in", "r", stdin);
    int t, r, c;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &r, &c);
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");
        nqueens(8, r, c);
        if (t) { printf("\n"); }
    }
    return 0;
}
