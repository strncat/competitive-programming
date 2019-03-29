//
//  2015-women Problem D. Googlander
//  https://code.google.com/codejam/contest/9214486/dashboard#s=p3
//
//  Created by Fatima Broom on 3/5/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <assert.h>
#include <unordered_map>
#include <set>

int r, c; // board dimensions
int board[30][30];
std::unordered_map<std::string, int> cache;

// only works for the small test case
long long findPath(int x, int y, char direction) {
    int count = 0;
    board[x][y] = 1; // visits the current square

    // look in the cache first
    //std::string key = direction+std::to_string(x)+std::to_string(y);
    //if (cache.find(key) != cache.end()) {
    //    return cache[key];
    //}

    if (direction == 'n') { // if north we can go east or continue north
        if (x > 0 && board[x - 1][y] == 0) { // fashionable move! stay north
            count += findPath(x - 1, y, direction);
            board[x - 1][y] = 0;
        }
        if (y < c - 1 && board[x][y + 1] == 0) { // will face east now
            count += findPath(x, y + 1, 'e');
            board[x][y + 1] = 0;
        }
    }

    else if (direction == 'e') { // if east we can go south or continue east
        if (y < c - 1 && board[x][y + 1] == 0) { // stay east
            count += findPath(x, y + 1, direction);
            board[x][y + 1] = 0;
        }

        if (x < r - 1 && board[x + 1][y] == 0) {
            count += findPath(x + 1, y, 's'); // facing south now
            board[x + 1][y] = 0;
        }
    }

    else if (direction == 's') { // if south, we can go west or continue south
        if (x < r - 1 && board[x + 1][y] == 0) {
            count += findPath(x + 1, y, direction);
            board[x + 1][y] = 0;
        }

        if (y > 0 && board[x][y - 1] == 0) {
            count += findPath( x, y - 1, 'w'); // facing west now
            board[x][y - 1] = 0;
        }
    }

    else if (direction == 'w') {
        if (y > 0 && board[x][y - 1] == 0) {
            count += findPath(x, y - 1, direction);
            board[x][y - 1] = 0;
        }

        if (x > 0 && board[x - 1][y] == 0) {
            count += findPath(x - 1, y, 'n');
            board[x - 1][y] = 0;
        }
    }

    // store it in the cache

    if (count > 0) {
        //cache[key] = count; // caching doesn't work we could have e92=1 and e92=4
        // because it really depends what squares are taken from the board
        return count;
    }

    // reached a dead end, count one path
    return 1;
}

// source for the following two solutions which work for both case
// https://code.google.com/codejam/contest/9214486/scoreboard?c=9214486#vt=1&vf=1
long long int dp[30][30];
long long int dp_main(int r,int c) {
    if (dp[r][c] != 0) { return dp[r][c]; }
    if (r == 1 || c == 1) { return dp[r][c] = 1; }
    for(int i = r; i > 0; i--) {
        dp[r][c] += dp_main(c - 1, i);
    }
    return dp[r][c];
}
long long dp_sol(int r, int c) {
    for (int i = 0; i < 30; i++) {
        for(int j = 0; j < 30; j++) {
            dp[i][j] = 0;
        }
    }
    return dp_main(r,c);
}

int main() {
    // measure time
    clock_t begin, end;
    double time_spent;
    begin = clock();

    freopen("in-large.txt", "r", stdin);
    freopen("out-large.txt", "w", stdout);
    int tests;
    scanf("%d\n", &tests);
    for (int t = 1; t <= tests; t++) {
        scanf("%d %d\n", &r, &c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                board[i][j] = 0;
            }
        }
        cache.clear();
        //printf("Case #%d: %lld\n", t, findPath(r - 1, 0, 'n'));
        printf("Case #%d: %lld\n", t, dp_sol(r, c));

    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    assert(time_spent < 3.1); // because in practice problems you only submit the output
    return 0;
}
