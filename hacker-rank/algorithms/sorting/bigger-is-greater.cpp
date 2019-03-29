//
//  Hacker Rank
//  Bigger is Greater
//  https://www.hackerrank.com/challenges/bigger-is-greater/editorial :(
//
//  Created by Fatima B on 12/25/15.
//  Copyright © 2015 Fatima B. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>

int main(void) {
    std::string s;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        std::cin >> s;
        int n = (int)s.length();

        // pick the first letter less than its neighbor
        // starting from the end so that "abc" ... will return b
        // dhck -> will return c, should be dhkc
        // dkhc -> will return d, should be hcdk
        int j = n-2;
        for (; j >= 0; j--) {
            if (s[j] < s[j+1]) {
                break;
            }
        }

        // if no letter was found then there isn't a string
        // lexicographically bigger
        if (j < 0) {
            std::cout << "no answer" << std::endl;
            continue;
        }

        // j is the first letter less than its neighbor j+1
        // but before we swap j and j+1 but we first want to know
        // if there is any letter that is smaller than j+1 on the right of it
        // example: dkhc we first pick d as the smallest letter < k
        // before we swap d and k, we look to find h which is greater than d
        // but also smaller than k

        // find a better smaller letter if possible
        int k = j+1;
        for (int m = k+1; m < n; m++) {
            if (s[m] < s[k] && s[m] > s[j]) {
                k = m;
            }
        }

        // we swap k and j
        char temp = s[k];
        s[k] = s[j];
        s[j] = temp;

        // after we switch the characters from dkhc to hkdc
        // we also need to sort the part starting at j+1 because
        // we want the smallest string possible
        std::partial_sort(s.begin()+j+1, s.end(), s.end());

        std::cout << s << std::endl;
    }
    return 0;
}
