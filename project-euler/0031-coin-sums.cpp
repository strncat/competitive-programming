//
//
//  Project Euler
//
//  Created by FB on 01/13/25.
//  Problem 31: Coin Sums https://projecteuler.net/problem=31
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <functional>
#include <utility>
#define N 250
#define C 10


int main(int argc, const char * argv[]) {
    // for a description of the solution see https://strncat.github.io/jekyll/update/2020/05/10/coin-change.html
    // (1) coins available are 1,2,5,10,20,50,100,200
    int coins[C] = {0,1,2,5,10,20,50,100,200}; // the first coin represents no coins
    // (2) amount can be up to 200 for this specific problem
    int table[C][N] = {0};
    // table[c][amount]:
    // c refers to the coins we can use. So c = 0, means we can only use coin[0]
    // c = 1, means we can use coin[0] and coin[1] etc

    // table[0][amount]: for any valid amount > 0, if we have 0 coins, then the total number of ways is 0
    for (int amount = 1; amount < N; amount++) {
        table[0][amount] = 0;
    }

    // table[c][0]: if the amount is 0, then the number of ways is always 1 for the base case
    for (int c = 0; c < C; c++) {
        table[c][0] = 1;
    }

    for (int c = 1; c < C; c++) {
        for (int amount = 1; amount < N; amount++) {
            // the number of ways to make change for amount should include the number of ways
            // to make change for this amount using all the previous coins
            table[c][amount] += table[c-1][amount];

            // in addition to that, if the current amount is greater than c
            // then we can also use the currrent coin c to make change
            if (amount >= coins[c]) {
                table[c][amount] += table[c][amount-coins[c]];
            }
        }
    }

    printf("%d\n", table[8][200]);



    /*
    std::unordered_map<std::pair<int,int>, int> map;

    for (int a = 2; a <= 5; a++) {
        for (int b = 2; b <= 5; b++) {
            // instead of computing a^b, we'll save both values in a pair
            std::pair<int,int> p = {a,b};
            map[p] = 1;
        }
    }

    // Output the stored pairs
    for (const auto& entry : map) {
        std::cout << "(" << entry.first.first << ", " << entry.first.second << "): " << entry.second << std::endl;
    }

    printf("%d\n", map.size());
     */
    return 0;
}

