//
//  main.cpp
//  10154 - Weights and Measures
//
//  Created by FB on 3/22/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>

typedef struct tutle {
    int strength;
    int weight;
    tutle(int s, int w) {
        strength = s;
        weight = w;
    }
} turtle;

bool compare(const turtle& a, const turtle& b) {
    return (a.strength < b.strength) ||
    (a.strength == b.strength && a.weight < b.weight);
}

int longest_increasing_subsequence(std::vector<turtle>& t) {
    int dp[5700];
    // this is weight of the maximum subsequence of length i
    for (int i = 0; i < t.size(); i++) {
        dp[i] = INT_MAX;
    }

    int max = 0;
    for (int i = 0; i < t.size(); i++) {
        for (int j = max; j >= 0; j--) {
            // can turtle i carry the stack of weight dp[j]
            // if yes, is the new weight smaller?
            if (t[i].weight + dp[j] <= t[i].strength && t[i].weight + dp[j] < dp[j+1]) {
                // now now turtle i extends the subsequence of length j into a new subsequence of length j+1
                // or turtle i is a better turtle than the one carrying the stack of length j+1
                dp[j+1] = dp[j] + t[i].weight;
                if (max < j+1) {
                    max = j+1;
                }
            }
        }
    }
    return max;
}

int main() {
    freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int w, s;
    std::vector<turtle> turtles;

    while (scanf("%d %d", &w, &s) == 2) {
        turtles.push_back(turtle(s, w));
    }

    std::sort(turtles.begin(), turtles.end(), compare);

    printf("%d\n", longest_increasing_subsequence(turtles));

    return 0;
}
