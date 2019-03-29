/*
 ID: fatima.1
 PROG: palsquare
 LANG: C++11
 */
//
//  Usaco Training
//  1.2 Palindromic Squares
//

#include <iostream>
#include <stdio.h>
#include <algorithm>

bool isPalindrome(std::string s) {
    for (int i = 0, j = (int) s.length() - 1; i < j; i++, j--) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

std::string changeBase(int x, int b) {
    std::string ascii = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string s = "";
    while (x/b) {
        s = ascii[x%b] + s;
        x = x/b;
    }
    if (x > 0) { // last remainder
        s = ascii[x%b] + s;
        x = x/b;
    }
    return s;
}

int main() {
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);

    int b;
    scanf("%d", &b);

    for (int i = 1; i <= 300; i++) {
        std::string s = changeBase(i*i, b);
        if (isPalindrome(s)) {
            printf("%s %s\n", changeBase(i, b).c_str(), s.c_str());
        }
    }
    return 0;
}
