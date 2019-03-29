//
//  Hacker Rank
//  ACM ICPC Team
//
//  Created by Fatima B on 12/29/15.
//  Copyright © 2015 Fatima B. All rights reserved.
//

#include <iostream>
#include <vector>

int main() {
    int n, m, num_topics[501];
    std::string s;
    std::vector<std::string> a;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        std::cin >> s; // s can be at max 500 characters
        a.push_back(s);
    }

    for (int i = 0; i <= m; i++) {
        num_topics[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {

            int count = 0;
            for (int k = 0; k < m; k++) {
                if (a[i][k] == '1' || a[j][k] == '1') {
                    count++; // they know topic k
                }
            }
            // they know k topics so increase that count by 1
            num_topics[count]++;
        }
    }

    for (int i = m; i >= 0; i--) {
        if (num_topics[i] != 0) {
            printf("%d\n%d\n", i, num_topics[i]);
            break;
        }
    }
    return 0;
}
