//
//  Code Forces
//  Pearls in a Row
//
//  Created by Fatima B on 1/21/16.
//  Copyright © 2016 Fatima B. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <set>

int main() {
    int a[400000], n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    std::vector<std::pair<int,int>> intervals;
    int i = 0;
    while (i < n) {
        // start a new segment at i
        std::set<int> s;
        s.insert(a[i]);

        int j = i+1;
        while (j < n && !s.count(a[j])) {
            s.insert(a[j++]);
        }

        if (j == n) { break; }

        intervals.push_back(std::make_pair(i+1, j+1));

        // either found a segment or didn't
        i = j+1;
    }

    if (intervals.size() > 0) {
        intervals.back().second = std::max(intervals.back().second, n);

        printf("%ld\n", intervals.size());
        for (int i = 0; i < intervals.size(); i++) {
            printf("%d %d\n", intervals[i].first, intervals[i].second);
        }
    } else {
        printf("-1\n");
    }

    return 0;
}
