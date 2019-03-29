/*
 ID: fatima.1
 PROG: speeding
 LANG: C++11
 */

// http://www.usaco.org/index.php?page=viewproblem2&cpid=568
// USACO December 2015 Bronze
// Speeding Ticket

/* basically since the range is only [0,100]
   we can just record the speed limit at every mile
   and then record bessie's speed at every mile as well
   now we just compare in O(n) the difference in their speeds
*/

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stdio.h>

int main() {
    int miles, speed, n, m, limit[101], bessie[101];
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);
    std::cin >> n >> m;

    // speed limit
    int start = 1, total = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> miles >> speed;
        total += miles;
        for (int j = start; j <= total; j++) {
            limit[j] = speed;
        }
        start += miles;
    }

    start = 1; total = 0;
    for (int i = 0; i < m; i++) {
        std::cin >> miles >> speed;
        total += miles;
        for (int j = start; j <= total; j++) {
            bessie[j] = speed;
        }
        start += miles;
    }

    int max = 0;
    for (int i = 1; i <= 100; i++) {
        if (max < bessie[i] - limit[i]) {
            max = bessie[i] - limit[i];
        }
    }

    std::cout << max << std::endl;
}