//
//  Hacker Rank
//  Caesar Cipher
//
//  Created by Fatima B on 12/31/15.
//  Copyright © 2015 Fatima B. All rights reserved.
//

#include <iostream>

int main() {
    int n, k;
    std::string s;
    std::cin >> n >> s >> k;
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            k = k % ('z'-'a'+1);
            if (s[i] + k > 'z') {
                printf("%c", s[i] - ('z'-'a') + (k%('z'-'a'+1))-1);
            } else {
                printf("%c", s[i] + k);
            }
        } else if (s[i] >= 'A' && s[i] <= 'Z') {
            k = k % ('Z'-'A'+1);
            if (s[i] + k > 'Z') {
                printf("%c", s[i] - ('Z'-'A') + k-1);
            } else {
                printf("%c", s[i] + k);
            }
        } else {
            std::cout << s[i];
        }
    }
    printf("\n");
    return 0;
}
