/*
 ID: fatima.1
 PROG: milk2
 LANG: C++11
 */
//
//  Usaco Training
//  1.2 Milking Cows
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.first < b.first;
}

int main() {
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);

    std::vector<std::pair<int, int>> farmers, merged;
    int n;
    int start, end;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &start, &end);
        farmers.push_back({start, end});
    }

    std::sort(farmers.begin(), farmers.end(), compare);

    // merge all intersections
    int previous = 0;
    for (int i = 1; i < farmers.size(); i++) {
        //std::cout << farmers[i].first << " " << farmers[i].second << std::endl;
        if (farmers[i].first <= farmers[previous].second) { // intersect
            farmers[previous].second = std::max(farmers[i].second, farmers[previous].second);
        } else {
            merged.push_back(farmers[previous]);
            previous = i;
        }
    }

    merged.push_back(farmers[previous]);

    //for (int i = 0; i < merged.size(); i++) {
    //    std::cout << merged[i].first << " " << merged[i].second << std::endl;
    //}

    // find maxes
    int milkMax = merged[0].second - merged[0].first;
    int nomilkMax = 0;
    for (int i = 1; i < merged.size(); i++) {
        if (merged[i].second - merged[i].first > milkMax) {
            milkMax = merged[i].second - merged[i].first;
        }
        if (merged[i].first - merged[i-1].second > nomilkMax) {
            nomilkMax = merged[i].first - merged[i-1].second;
        }
    }
    printf("%d %d\n", milkMax, nomilkMax);
    return 0;
}
