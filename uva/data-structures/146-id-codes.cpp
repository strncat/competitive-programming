//
//  146 ID Codes
//  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=82
//
//  Created by Fatima Broom on 3/5/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>

int main() {
    //freopen("example.in", "r", stdin);
    //freopen("example.out", "w", stdout);
    std::string s;

    while (std::cin >> s) {
        if (s[0] == '#') {
            break;
        }
        std::string p = s;
        std::next_permutation(std::begin(p),std::end(p));

        if (s == p || s[0] > p[0]) {
            std::cout << "No Successor" << std::endl;
        } else {
            std::cout << p << std::endl;
        }
    }
    return 0;
}
