//
//  Problem D. Password Security
//  https://code.google.com/codejam/contest/8274486/dashboard#s=p3
//
//  Created by Fatima Broom on 3/12/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <random>

// instead of generating a random shuffle, I was using in my original solution
// next_permutation with the same idea ... I saw in the accepted solutions that
// doing a shuffle every single time is much faster! for about 10000 tries gives
// a correct answer!

int main() {
    freopen("in-small.txt", "r", stdin);
    freopen("out-small.txt", "w", stdout);

    int tests;
    scanf("%d\n", &tests);

    for (int t = 1; t <= tests; t++) {
        int n; // n = number of passwords
        scanf("%d", &n);

        // array for passwords
        std::vector<std::string> passwords;
        for (int i = 0; i < n; i++) {
            std::string password;
            std::cin >> password;
            passwords.push_back(password);
        }

        // begin with a sample password
        std::string s = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

        // 10000 tries
        std::random_device d;
        bool found = false;
        for (int i = 0; i < 10000; i++) {
            // generate a random password
            std::mt19937 g(d());
            std::shuffle(s.begin(), s.end(), g);

            // if any password matches the random password, then we can't use it
            int j = 0;
            for (j = 0; j < passwords.size(); j++) {
                if (s.find(passwords[j]) != std::string::npos) {
                    break;
                }
            }

            // random password didn't match any passwords
            found = false;
            if (j == passwords.size()) {
                found = true;
                break;
            }
        }

        if (found) {
            printf("Case #%d: %s\n", t, s.c_str());
        } else {
            printf("Case #%d: IMPOSSIBLE\n", t);
        }
    }
    return 0;
}
