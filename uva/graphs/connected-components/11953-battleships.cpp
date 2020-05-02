//
//  11953 - Battleships
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

#define MAX 101

char grid[MAX][MAX];

int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};

int n;

int bfs(int x, int y, bool visited[MAX][MAX]) {
    std::queue<std::pair<int,int>> q;
    q.push(std::make_pair(x,y));

    visited[x][y] = true;
    int total = 1;

    while (!q.empty()) {
        std::pair<int,int> p = q.front();
        int i = p.first;
        int j = p.second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int next_x = i + dx[k];
            int next_y = j + dy[k];
            
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n) { // out of bounds
                continue;
            }

            // visited already
            if (visited[next_x][next_y]) {
                continue;
            }
            
            // ship parts
            if (grid[next_x][next_y] == 'x' || grid[next_x][next_y] == '@') {
                total++;
                visited[next_x][next_y] = true;
                q.push({next_x, next_y});
            }
        }
    }
    return total;
}

int main() {
    //freopen("in.txt" , "r" , stdin);
    int tests;
    scanf("%d", &tests);
    for (int test = 1; test <= tests; test++) {
        scanf("%d\n", &n);
        std::string line;
        for (int i = 0; i < n; i++) {
            std::getline(std::cin, line); // a line here is 123
            // no input, return false (we didn't read anything)
            for (int j = 0; j < n; j++) {
                grid[i][j] = line[j];
            }
        }
        
        bool visited[MAX][MAX] = {false};

        int total_ships = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 'x') {
                    bfs(i,j,visited);
                    total_ships++;
                }
            }
        }
        printf("Case %d: %d\n", test, total_ships);
    }
    return 0;
}
