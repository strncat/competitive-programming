#include <iostream>

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        std::string s1, s2;
        int c[26] = {0};
        std::cin >> s1 >> s2;
        std::string common = "NO";
        for (int i = 0; i < s1.length(); i++) {
            c[s1[i] - 'a']++;
        }
        for (int i = 0; i < s2.length(); i++) {
            if (c[s2[i] - 'a']) {
                common = "YES";
            }
        }
        std::cout << common << std::endl;
    }
    return 0;
}

