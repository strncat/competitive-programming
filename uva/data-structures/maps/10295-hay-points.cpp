//
//  10295 - Hay Points
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//  Based on https://algs4.cs.princeton.edu/41graph/EulerianCycle.java
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include <stack>
#include <unordered_map>

int main() {
    freopen("in.txt" , "r" , stdin);
    std::unordered_map<std::string, int> map;

    int n, m;
    scanf("%d %d", &n, &m);

    // n words in the dictionary
    std::string description;
    int worth;
    for (int i = 0; i < n; i++) {
        std::cin >> description >> worth;
        map[description] = worth;
    }

    // m test cases
    std::string s;
    for (int j = 0; j < m; j++) {
        int salary = 0;
        while (std::cin >> s) {
            if (s[0] == '.') {
                break;
            }
            if (map.find(s) != map.end()) {
                salary += map[s];
            }
        }
        printf("%d\n", salary);
    }
    return 0;
}
