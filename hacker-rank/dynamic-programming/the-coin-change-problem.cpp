//
//  The Coin Change Problem
//  https://www.hackerrank.com/challenges/coin-change
//
//  Created by Fatima Broom on 3/5/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>

long long dp[251][251];

long long make_change_bottom_up(int *c, int n, int amount) {
    // base case for amount = 0, there is 1 way to make change no matter what coin it is
    for (int i = 0; i < n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 0; i < n; i++) { // for each coin
        for (int j = 1; j <= amount; j++) { // for each amount

            // dp[n][amount] = dp[n-1][amount] + dp[n][amount-c[n]]

            dp[i][j] = (i == 0) ? 0 : dp[i-1][j];

            dp[i][j] += (j-c[i] < 0) ? 0 : dp[i][j-c[i]];
        }
    }
    return dp[n-1][amount];
}

int main() {
    //freopen("all.in", "r", stdin);
    int n, m, coins[53];

    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &coins[i]);
    }
    printf("%lld", make_change_bottom_up(coins, m, n));

    return 0;
}
