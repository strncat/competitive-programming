/*
 ID: fatima.1
 PROG: paint
 LANG: C++11
 */

// http://www.usaco.org/index.php?page=viewproblem2&cpid=567

#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stdio.h>

int main() {
    int a, b, c, d;
    freopen("paint.in", "r", stdin);
    freopen("paint.out", "w", stdout);
    std::cin >> a >> b >> c >> d;

    // 7 9    1 9    4 5
    // 4 8    4 5    1 9
    if (a <= d && c <= b) { // they intersect
        int min = a < c ? a : c;
        int max = b > d ? b : d;
        std::cout << max - min << std::endl;
    }
    // 1 2    4 5
    // 4 5    1 2
    else { // no intersection
        std::cout << (d - c) + (b - a) << std::endl;;

    }
}