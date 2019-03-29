//
//  main.cpp
//  uhunt
//
//  10252 - Common Permutation
//  2017/03/16
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using std::string;
using std::unordered_map;

int main() {
    //freopen("sample.in", "r", stdin);

    string s1, s2;
    while (getline(std::cin, s1)) {
        getline(std::cin, s2);

        unordered_map<char, int> common;
        for (int i = 0; i < s1.size(); i++) {
            if (common.find(s1[i]) == common.end()) {
                common[s1[i]] = 1;
            } else {
                common[s1[i]]++;
            }
        }
        string c="";
        for (int i = 0; i < s2.size(); i++) {
            if (common.find(s2[i]) != common.end() && common[s2[i]] > 0) {
                common[s2[i]]--;
                c += s2[i];
            }
        }
        std::sort(c.begin(), c.end());
        std::cout << c << std::endl;
    }
    return 0;
}
