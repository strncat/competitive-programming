/*
 ID: fatima.1
 PROG: gift1
 LANG: C++11
 */
//
//  usaco training
//  1.1 Greedy Gift Givers
//

#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <vector>

int main() {
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);

    int n;
    std::cin >> n;

    std::unordered_map<std::string, int> members;
    std::vector<std::string> ordered;
    std::string s;
    while (n--) {
        std::cin >> s;
        members[s] = 0;
        ordered.push_back(s);
    }

    std::string giver;
    while (std::cin >> giver) {
        int value, m;
        std::cin >> value >> m;

        if (m == 0) { // greedy member
            members[giver] += value;
            continue;
        }

        members[giver] -= value;
        members[giver] += (value%m); // return leftover money

        for (int i = 0; i < m; i++) {
            std::cin >> s;
            members[s] += value / m;
        }
    }

    for (auto t = ordered.begin(); t != ordered.end(); t++) {
        std::cout << *t << " " << members[*t] << std::endl;
    }

    return 0;
}
