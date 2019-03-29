//
//  main.cpp
//  uhunt
//
//  ONLY FOR THE SMALL DATASET
//

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using std::vector;

char d[55][50];

void build(int x, int y, int n) {
    for (int i = x; i < x+5; i++) {
        for (int j = y; j < y+5; j++) {
            d[i][j] = 'O';
        }
    }
    switch (n) {
        case 0:
            break;
        case 1:
            d[x+2][y+1] = '/';
            break;
        case 2:
            d[x+1][y+1] = '/';
            d[x+1][y+2] = '/';
            break;
        case 3:
            d[x+1][y+1] = '/';
            d[x+1][y+2] = '/';
            d[x+1][y+3] = '/';
            break;
        case 4:
            d[x+1][y+1] = '/';
            d[x+1][y+2] = '/';
            d[x+1][y+3] = '/';
            d[x+2][y+1] = '/';
            break;
        case 5:
            d[x+1][y+1] = '/';
            d[x+1][y+2] = '/';
            d[x+1][y+3] = '/';
            d[x+2][y+1] = '/';
            d[x+2][y+3] = '/';
            break;
        case 6:
            d[x+1][y+1] = '/';
            d[x+1][y+2] = '/';
            d[x+1][y+3] = '/';
            d[x+2][y+1] = '/';
            d[x+2][y+3] = '/';
            d[x+3][y+1] = '/';
            break;
        case 7:
            d[x+1][y+1] = '/';
            d[x+1][y+2] = '/';
            d[x+1][y+3] = '/';
            d[x+2][y+1] = '/';
            d[x+2][y+3] = '/';
            d[x+3][y+1] = '/';
            d[x+3][y+2] = '/';
            break;
        case 8:
            for (int i = x+1; i < x+4; i++) {
                for (int j = y+1; j < y+4; j++) {
                    d[i][j] = '/';
                }
            }
            break;
    }
    d[x+2][y+2] = 'I';
}

int main() {
    freopen("sample.in", "r", stdin);
    freopen("sample.out", "w", stdout);
    int test_cases;
    scanf("%d", &test_cases);
    for (int t = 1; t <= test_cases; t++) {
        int s, n;
        scanf("%d %d", &n, &s);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                d[i][j] = ' ';
            }
        }
        printf("Case #%d:\n", t);

        bool fill = false;
        int N = 5, M = 5;
        if (s == 0) {
            printf("O\n");
            continue;
        } else {
            int i = 0;
            int j = 0;
            int total = s;
            while (1) {
                if (j >= 49) {
                    i += 5;
                    j = 0;
                    N += 5;
                    fill = true;
                }
                if (M < 48) {
                    M += 5;
                }
                if (total < 8) {
                    build(i, j, total);
                } else {
                    build(i, j, 8);
                }
                total -= 8;
                j += 5;
                if (total <= 0) {

                    if (fill) {
                        while (j < 48) {
                            build(i, j, 0);
                            j+=5;
                        }
                    }

                    break;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("%c", d[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
