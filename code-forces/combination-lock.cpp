//
//  Codeforces Round #301 (Div. 2)
//  A. Combination Lock
//

#include <iostream>
#include <stdio.h>

int main() {
    //freopen("in.txt", "r", stdin);
    int n, ticks = 0;
    std::string state, key;
    scanf("%d", &n);
    std::cin >> state >> key;

    for (int i = 0; i < n; i++) {
        int s = state[i] - '0', k = key[i] - '0';
        if (s > k) {
            ticks += std::min(s-k, 10-s+k);
        } else {
            ticks += std::min(k-s, 10-k+s);
        }
    }
    printf("%d\n", ticks);
    return 0;
}
