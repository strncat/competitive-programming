//
//  11094 - Continents
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>

#define MAX 25

char land[MAX][MAX];

int dx[4] = {0,-1,1,0};
int dy[4] = {1,0,0,-1};

int n, m;

int bfs(int x, int y, bool visited[MAX][MAX]) {
    std::queue<std::pair<int,int>> q;
    q.push(std::make_pair(x,y));

    visited[x][y] = true;
    int total = 1;
    char l = land[x][y];

    while (!q.empty()) {
        std::pair<int,int> p = q.front();
        int i = p.first;
        int j = p.second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int next_x = i + dx[k];
            int next_y = j + dy[k];

            // columns wrap around
            if (next_y >= n) {
                next_y = 0;
            } else if (next_y < 0) {
                next_y = n-1;
            }
            
            if (next_x < 0 || next_x >= m) { // out of bounds
                continue;
            }

            // visited already or not a piece of land
            if (visited[next_x][next_y] || land[next_x][next_y] != l) {
                continue;
            }

            total++;
            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }
    return total;
}

int main() {
    //freopen("in.txt" , "r" , stdin);
    while (scanf("%d %d\n", &m, &n) != EOF) {
        std::string line;
        for (int i = 0; i < m; i++) {
            std::getline(std::cin, line); // a line here is 123
            // no input, return false (we didn't read anything)
            for (int j = 0; j < n; j++) {
                land[i][j] = line[j];
            }
        }
        int x, y;
        scanf("%d %d", &x, &y); // position
        bool visited[MAX][MAX] = {false};
        
        // THE KING'S INTIAL LAND DOESN'T COUNT
        bfs(x,y,visited);
        
        int best_sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == land[x][y] && !visited[i][j]) {
                    int sum = bfs(i,j,visited);
                    if (sum > best_sum) {
                        best_sum = sum;
                    }
                }
            }
        }
        printf("%d\n", best_sum);
    }
    return 0;
}
