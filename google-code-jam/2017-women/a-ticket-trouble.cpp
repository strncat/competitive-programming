//
//  main.cpp
//  uhunt
//
//  1
//

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>


int main() {
    freopen("sample.in", "r", stdin);
    freopen("sample.out", "w", stdout);
    int test_cases;
    scanf("%d", &test_cases);

    for (int t = 1; t <= test_cases; t++) {
        int f, n;
        scanf("%d %d", &f, &n);

        int g[120][120];

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                g[i][j] = 0;
            }
        }
        int x, y;
        for (int i = 0; i < f; i++) {
            scanf("%d %d", &x, &y);
            g[x][y] = 1;
            g[y][x] = 1;
        }

        int max = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            sum = 0;
            for (int j = 1; j <= n; j++) {
                sum += g[i][j];
            }
            if (sum > max) {
                max = sum;
            }
        }
        printf("Case #%d: %d\n", t, max);

    }
    return 0;
}
