//
//  195 - Anagram
//
//  Created by Fatima B on 10/10/15.
//  Copyright © 2015 nemo. All rights reserved.

#include <iostream>
#include <algorithm>

bool compare(const char &a, const char &b) {
    // lower(A) == lower(a) but A < a
    return (tolower(a) < tolower(b) || (tolower(a) == tolower(b) && a < b));
}

int main() {
    int test_cases;
    std::string s;
    scanf("%d", &test_cases);
    while (test_cases--) {
        std::cin >> s;
        std::sort(s.begin(), s.end(), compare);
        do {
            std::cout << s << std::endl;
        } while (std::next_permutation(s.begin(), s.end(), compare));
    }
    return 0;
}
