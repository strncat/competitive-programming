/*
 ID: fatima.1
 PROG: dualpal
 LANG: C++11
 */
//
//  Usaco Training
//  1.2 Dual Palindromes
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <limits.h>

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
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);

    int n, s, palindromicBases, total = 0;
    scanf("%d %d", &n, &s);

    for (int i = s + 1; i <= INT_MAX; i++) {
        palindromicBases = 0;
        for (int b = 2; b <= 10; b++) {
            if (isPalindrome(changeBase(i, b))) {
                palindromicBases++;
            }
            if (palindromicBases == 2) {
                printf("%d\n", i);
                total++;
                break;
            }
        }

        if (total == n) {
            break;
        }
    }
    return 0;
}
