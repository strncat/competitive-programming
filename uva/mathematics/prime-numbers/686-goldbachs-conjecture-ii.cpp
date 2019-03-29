//
//  main.cpp
//  uhunt
//
//  Created by FB on 12/14/18.
//  Copyright © 2018 FB. All rights reserved.
//

#include <iostream>
#include <unordered_map>

std::unordered_map<int,bool> prime;
void sieve(int n) { // Ref: Algorithms in C
    prime[1] = false;
    for (int i = 2; i <= n; i++) {
        prime[i] = true;
    }
    for (int i = 2; i <= n/2; i++) {
        for (int j = 2; j <= n/i; j++) {
            prime[i*j] = false;
        }
    }
}

int main() {
    freopen("example.in", "r", stdin);
    //freopen("example.out", "w", stdout);

    sieve(33000);

    int n;
    while(scanf("%d\n", &n) == 1) {
        if (n == 0) { break; }

        int count = 0;
        for (int i = 0; i < n/2+1; i++) {
            if (prime[i] == true) {
                int p2 = n - i;
                if (prime[p2]) {
                    count++;
                    //printf("%d %d\n", p2, i);
                }
            }
        }
        printf("%d\n", count);
        //printf("%d = %d\n", n, count);
    }

    return 0;
}
