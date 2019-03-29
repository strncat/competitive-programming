//
//  10420 - List of Conquests
//  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1361
//
//  Created by Fatima Broom on 3/5/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <map>

int main() {
    //freopen("one.in", "r", stdin);
    //freopen("one.out", "w", stdout);

    int n;
    std::string line, country;
    std::map<std::string, int> m;

    scanf("%d\n", &n);

    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);
        country = "";
        for (int i = 0; line[i] != ' ' && i < line.length(); i++) {
            country += line[i];
        }
        m[country]++;
    }

    for (auto i = m.begin(); i != m.end(); i++) {
        std::cout << i->first << " " << i->second << std::endl;
    }
    return 0;
}
