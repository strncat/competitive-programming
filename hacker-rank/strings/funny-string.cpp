//
//  Hackerrank - Funny String
//

#include <iostream>
#include <string>
#include <math.h>

int is_funny(std::string s) {
    int n = (int) s.length();
    for (int i = 1; i < n; i++) {
        if (abs(s[i] - s[i-1]) != abs(s[n-i-1] - s[n-i])) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int cases;
    std::string s;
    scanf("%d", &cases);
    while (cases--) {
        std::cin >> s;
        if (is_funny(s)) {
            std::cout << "Funny" << std::endl;
        } else {
            std::cout << "Not Funny" << std::endl;
        }
    }
    return 0;
}
