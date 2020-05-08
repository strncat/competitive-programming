//
//  main.cpp
//  uhunt
//
//  11991 - Easy Problem from Rujia Liu?
//  2017/02/14
//

#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
    //freopen("sample.in", "r", stdin);
    std::unordered_map<int, std::vector<int>> d;
    int n, m, a, k, v;

    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 0; i < n; i++) {
            scanf("%d", &a);
            if (d.find(a) == d.end()) {
                d[a] = std::vector<int>();
            }
            d[a].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            scanf("%d %d", &k, &v);
            if (d.find(v) == d.end() || k > d[v].size()) {
                printf("0\n");
                continue;
            }
            printf("%d\n", d[v][k-1]+1);
        }
    }
    return 0;
}