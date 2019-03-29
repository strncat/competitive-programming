/*
 ID: fatima.1
 PROG: friday
 LANG: C++11
 */
//
//  Usaco Training
//  1.1 Friday the Thirteenth
//

#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

int main() {
    freopen("friday.in", "r", stdin);
    //freopen("friday.out", "w", stdout);

    int n;
    std::cin >> n;

    int dist[7] = {0}; // Saturday, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    int day = 2; // we start on Monday
    for (int y = 1900; y < 1900 + n; y++) { // for every year

        // leap year or not?
        if (y%4 == 0 && (y % 100 != 0 || y % 400 == 0)) {
            months[1] = 29;
        } else {
            months[1] = 28;
        }

        // for every month starting January 1st
        for (int m = 0; m < 12; m++) {
            dist[(day + 12) % 7]++; // the 13th!
            day = (day + months[m]) % 7; // add the number of days
        }
    }

    for (int i = 0; i < 6; i++) {
        printf("%d ", dist[i]);
    }
    printf("%d\n", dist[6]);
    return 0;
}
