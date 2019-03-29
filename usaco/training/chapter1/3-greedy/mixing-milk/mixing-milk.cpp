/*
 ID: fatima.1
 PROG: milk
 LANG: C++11
 */
//
//  Usaco Training
//  1.3 Mixing Milk
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int,int> &a, const std::pair<int,int> &b) {
    return (a.first < b.first);
}

int main() {
    freopen("milk.in", "r", stdin);
    freopen("milk.out", "w", stdout);

    int amount, n;
    std::vector<std::pair<int, int>> a;
    scanf("%d %d", &amount, &n);

    int price, count;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &price, &count);
        a.push_back({price, count});
    }
    std::sort(a.begin(), a.end(), compare);

    int total = 0;
    for (auto t = a.begin(); t != a.end(); t++) {
        if (amount == 0) { break; }
        int quantity = std::min(amount, t->second);
        total += (t->first * quantity);
        amount -= quantity;
    }
    printf("%d\n", total);
    return 0;
}
