//
//  10946 - You want what filled?
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

#define MAX 101

int bfs(int x, int y, std::vector<std::string>& grid, bool visited[MAX][MAX], char letter) {
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    int m = (int) grid.size(); // number of rows
    int n = (int) grid[0].size(); // number of columns

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

            // visited or out of bounds
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited[next_x][next_y]) {
                continue;
            }

            // not the same letter
            if (grid[next_x][next_y] != letter) {
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
    int test = 1, n, m;

    std::vector<std::string> grid;
    std::string line;

    while (scanf("%d %d\n", &m, &n) == 2) {
        if (m == 0 && n == 0) {
            break;
        }

        grid.clear();
        for (int i = 0; i < m; i++) {
            std::getline(std::cin, line);
            grid.push_back(line);
        }

        bool visited[MAX][MAX] = {false};
        std::vector<std::pair<char,int>> holes;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] != '.') {
                    holes.push_back({grid[i][j], bfs(i,j, grid, visited, grid[i][j])});
                }
            }
        }

        // now we have records like {A, 3} {A, 2} and so on
        // we just need to sort them based on the frequency
        std::sort(holes.begin(), holes.end(), [](const std::pair<char,int> &l, const std::pair<char,int> &r) {
            if (l.second == r.second) {
                return l.first < r.first;
            }
            return l.second > r.second;
        });

        printf("Problem %d:\n", test++);
        for (int i = 0; i < holes.size(); i++) {
            printf("%c %d\n", holes[i].first, holes[i].second);
        }
    }
    return 0;
}
