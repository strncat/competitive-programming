#include <iostream>

int main() {
    std::string s;
    int tests;
    std::cin >> tests;
    while (tests--) {
        std::cin >> s;
        int deletions = 0;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                deletions++;
            }
        }
        std::cout << deletions << std::endl;
    }
    return 0;
}
