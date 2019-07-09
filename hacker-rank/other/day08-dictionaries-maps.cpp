#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore();
    std::unordered_map<std::string, int> map;
    while (n--) {
        std::string s;
        int t;
        std::getline(std::cin, s);
        std::cin >> t;
        std::cin.ignore();
        map[s] = t;
    }
    std::string q;
    while (std::getline(std::cin, q)) {
        if (q.size() == 0) { break; }
        auto search = map.find(q);
        if (search != map.end()) {
            std::cout << search->first << "=" << search->second << std::endl;;
        } else {
            std::cout << "Not found\n";
        }
    }
    return 0;
}