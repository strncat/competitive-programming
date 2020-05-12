//
//  11137 Ingenuous Cubrency
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include <stack>
#include <unordered_map>

#define MAX_AMOUNT 10001

unsigned long long dp[22][MAX_AMOUNT+1];
unsigned long long dp2[MAX_AMOUNT+1];

// bottom up with less memory
void number_of_ways_1d(std::vector<int> coins) {
    dp2[0] = 1; // base case
    for (int i = 1; i < coins.size(); i++) { // for each coin
        for (int amount = coins[i]; amount <= MAX_AMOUNT; amount++) { // for each amount, m needs to be >= c[i], start from c[i]
            dp2[amount] += dp2[amount - coins[i]];
        }
    }
}

void number_of_ways_2d(std::vector<int> coins) {
    // base case for amount = 0, there is 1 way to make change
    for (int i = 0; i < coins.size(); i++) {
        dp[i][0] = 1;
    }
    // otherwise the total number of ways to make change is zero for any amount > 0 with zero coins
    for (int amount = 1; amount <= MAX_AMOUNT; amount++) {
        dp[0][amount] = 0;
    }

    for (int i = 1; i < coins.size(); i++) { // for each coin
        for (int amount = 1; amount <= MAX_AMOUNT; amount++) { // for each amount
            // dp[n][amount] = dp[n-1][amount] + dp[n][amount-c[n]]
            dp[i][amount] = dp[i-1][amount];

            if (amount >= coins[i]) {
                dp[i][amount] += dp[i][amount-coins[i]];
            }
        }
    }
}

int main() {
    freopen("in.txt" , "r" , stdin);

    int n;
    std::vector<int> coins;

    coins.push_back(0);
    for (int i = 1; i <= 21; i++) {
        coins.push_back(i*i*i);
    }

    // pre-calculate all possible number of ways
    //number_of_ways_2d(coins);
    number_of_ways_1d(coins);

    while (scanf("%d", &n) != EOF) {
        printf("%llu\n", dp2[n]);
        //printf("%llu\n", dp[coins.size()-1][n]);
    }

    return 0;
}
