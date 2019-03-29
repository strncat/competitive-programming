//
//  Google Code Jam Round 1A 2010
//  Problem A. Rotate
//

#include <iostream>

# define MAX 55

void rotate90(char a[MAX][MAX], int n) {
    for (int layer = 0; layer < n / 2; layer++) {
        int first = layer;
        int last = n - layer - 1;

        for (int i = first; i < last; i++) {
            int offset = i - first;
            int temp = a[first][i];
            a[first][i] = a[last - offset][first]; // top left
            a[last - offset][first] = a[last][last - offset]; // bottom left
            a[last][last - offset] = a[i][last]; // bottom right
            a[i][last] = temp; // top right
        }
    }
}

void shiftDown(char a[MAX][MAX], int n) {
    for (int j = n - 1; j >= 0; j--) { // for each column
        int k = n - 1; // shift each character, k is the write index
        for (int i = n - 1; i >=0; i--) {
            if (a[i][j] != '.') { a[k--][j] = a[i][j]; }
        }
        for (int m = 0; m <= k; m++) { // fill the rest with '.'
            a[m][j] = '.';
        }
    }
}

std::string row(char a[MAX][MAX], int n, int k) { // check rows for a solution
    std::string winners;
    for (int i = 0; i < n; i++) {
        int count = 0;
        for (int j = 0; j < n - 1; j++) {
            a[i][j] == a[i][j + 1] && a[i][j] != '.' ? count++ : count = 0;
            if (count == k - 1) { winners += a[i][j]; }
        }
    }
    return winners;
}

std::string column(char a[MAX][MAX], int n, int k) { // check rows for a solution
    std::string winners;
    for (int j = 0; j < n; j++) {
        int count = 0;
        for (int i = 0; i < n - 1; i++) {
            a[i][j] == a[i + 1][j] && a[i][j] != '.' ? count++ : count = 0;
            if (count == k - 1) { winners += a[i][j]; }
        }
    }
    return winners;
}

std::string diagonal(char a[MAX][MAX], int n, int k) { // check both diagonals for a solution
    std::string winners;
    for (int slice = 0; slice < 2*n - 1; slice++) {
        int count = 0;
        int z = slice < n ? 0 : slice - n + 1;
        for (int j = z, m = slice - j; j <= slice - z; m--, j++) {
            a[j][m] == a[j + 1][m - 1] && a[j][m] != '.' ? count++ : count = 0;
            if (count == k - 1) { winners += a[j][m]; count = 0; }
        }
        //printf("\ncount = %d\n", count);
    }

    for (int slice = 0; slice < 2*n - 1; slice++) {
        int z = slice < n ? 0 : slice - n + 1;
        int m = slice < n ? n - slice - 1 : 0;
        int count = 0;
        for (int j = z; j <= slice - z; j++, m++) {
            a[j][m] == a[j + 1][m + 1] && a[j][m] != '.' ? count++ : count = 0;
            if (count == k - 1) { winners += a[j][m]; count = 0; }
        }
    }
    return winners;
}

int main() {
    freopen("in-large.txt" , "r" , stdin);
    freopen("out-large.txt" , "w" , stdout);

    int tests, N, K;
    char a[MAX][MAX];
    scanf("%d", &tests);

    for (int t = 1; t <= tests; t++) {
        scanf("%d %d\n", &N, &K);

        // reset
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                a[i][j] = '.';
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%c", &a[i][j]);
            }
            scanf("\n");
        }

        rotate90(a, N);
        shiftDown(a, N);
        //print(a, N);

        std::string winners = column(a, N, K);
        winners += row(a, N, K);
        winners += diagonal(a, N, K);
        bool red = false, blue = false;

        for (int i = 0; i < winners.length(); i++) {
            if (winners[i] == 'R') {
                red = true;
            } else if (winners[i] == 'B') {
                blue = true;
            }
        }
        if (red && blue) {
            printf("Case #%d: Both\n", t);
        } else if (red) {
            printf("Case #%d: Red\n", t);
        } else if (blue) {
            printf("Case #%d: Blue\n", t);
        } else {
            printf("Case #%d: Neither\n", t);
        }
    }
    return 0;
}
