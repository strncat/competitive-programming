/*
 ID: fatima.1
 PROG: barn1
 LANG: C++11
 */
//
//  Usaco Training
//  1.3 Barn Repair
//
// My solution is the pick M-1 largest differences in the array
// so for (3 4 6 8) (14 15 16 17 21) (25 26 27 30 31) (40 41 42 43)
// the largest differences are 14-8, 25-21, 31-25 and 43-40

// However, looking at the contest solution, they maintain a cows array
// mark the stalls that have cows in them and then find the biggest
// strips of stalls with no cows in them ... somewhat similar to what I did

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

bool compare(const std::pair<int,bool> &a, const std::pair<int,bool> &b) {
    return a.first < b.first;
}

int main() {
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);

    int boards, total, cows;
    scanf("%d %d %d", &boards, &total, &cows);

    std::vector<std::pair<int,bool>> a;
    int temp;
    for (int i = 0; i < cows; i++) {
        scanf("%d", &temp);
        a.push_back({temp, false});
    }

    std::sort(a.begin(), a.end(), compare);

    // find the biggest gaps
    for (int i = 0; i < std::min(boards,cows)-1; i++) {
        int max = 0, index = -1;
        for (int j = 1; j < cows; j++) {
            if (a[j].first - a[j-1].first >= max && !a[j-1].second) {
                max = a[j].first-a[j-1].first;
                index = j-1;
            }
        }
        a[index].second = true;
    }

    // sum the covered the stalls
    int first = a[0].first, stalls = 0;
    for (int i = 0; i < cows; i++) {
        if (a[i].second) {
            //printf("(%d, %d)\n", first, a[i].first);
            stalls += a[i].first - first + 1;
            first = a[i+1].first;
        }
    }
    //printf("(%d, %d)\n", first, a[cows-1].first);
    stalls += a[cows-1].first-first + 1; // last one

    printf("%d\n", stalls);
    return 0;
}
