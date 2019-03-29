/*
 ID: fatima.1
 PROG: ride
 LANG: C++11
 */
//
//  usaco training
//  1.1 Your Ride Is Here
//

#include <iostream>
#include <stdio.h>

int main() {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);

    std::string s, t;
    std::cin >> s >> t; // max length is 6 and max product is 26^6

    int sResult = 1;
    for (int i = 0; i < s.length(); i++) {
        sResult *= (s[i] - 'A' + 1);
    }

    int tResult = 1;
    for (int i = 0; i < t.length(); i++) {
        tResult *= (t[i] - 'A' + 1);
    }

    if (tResult%47 == sResult%47) {
        printf("GO\n");
    } else {
        printf("STAY\n");
    }
    return 0;
}
