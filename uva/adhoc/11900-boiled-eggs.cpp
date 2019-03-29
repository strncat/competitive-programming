//
//  main.cpp
//  uhunt
//
//  11900 - Boiled Eggs
//  2017/02/07
//

#include <iostream>
#include <vector>
#include <algorithm> // sort

int main() {
    //freopen("sample.in", "r", stdin);
    int test_cases, n, p, q, w;
    std::vector<int> eggs;

    scanf("%d", &test_cases);

    for (int t = 1; t <= test_cases; t++) {
        scanf("%d %d %d", &n, &p, &q);

        eggs.clear();
        for (int i = 0; i < n; i++) {
            scanf("%d", &w);
            eggs.push_back(w);
        }

        std::sort(eggs.begin(), eggs.end());

        int total = 0, weight = 0;
        for (int i = 0; i < eggs.size(); i++) {
            if (weight + eggs[i] <= q && total + 1 <= p) {
                total++;
                weight += eggs[i];
            }
        }
        printf("Case %d: %d\n", t, total);
    }
    return 0;
}