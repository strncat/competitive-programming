//
//  469 Wetlands of Florida
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <sstream>

#define MAX 101

void bfs(int x, int y,
        std::vector<std::string>& grid,
        bool visited[MAX][MAX],
        std::vector<std::vector<int>>& totals) {
    int dx[8] = {0,0,-1,-1,-1,1,1,1};
    int dy[8] = {1,-1,0,1,-1,0,1,-1};
    int m = (int) grid.size(); // number of rows
    int n = (int) grid[0].size(); // number of columns

    std::vector<std::pair<int,int>> connected_nodes;
    std::queue<std::pair<int,int>> q;
    q.push(std::make_pair(x,y));
    connected_nodes.push_back(std::make_pair(x,y));
    visited[x][y] = true;
    int total = 1;

    while (!q.empty()) {
        std::pair<int,int> p = q.front();
        int i = p.first;
        int j = p.second;
        q.pop();

        for (int k = 0; k < 8; k++) {
            int next_x = i + dx[k];
            int next_y = j + dy[k];

            // visited or out of bounds
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited[next_x][next_y]) {
                continue;
            }

            // not the same letter
            if (grid[next_x][next_y] != 'W') {
                continue;
            }

            total++;
            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
            connected_nodes.push_back({next_x, next_y});
        }
    }

    // update all the nodes in the connected component with the total
    // number of connected nodes in this component, so if we have 5 total, then
    // we'll update all the 5 components with 5
    for (auto i = connected_nodes.begin(); i != connected_nodes.end(); i++) {
        totals[i->first][i->second] = total;
    }
}

int main() {
    //freopen("in.txt" , "r" , stdin);
    int tests, n, m, x, y;
    scanf("%d\n", &tests);

    std::vector<std::string> grid;
    std::string line;

    while (tests--) {
        grid.clear();

        // found this pretty sweet way of reading the grid (much better than my original)
        // in marioyc's github
        while (1) {
            std::getline(std::cin, line);
            if (line[0] != 'W' && line[0] != 'L') {
                break; // not grid data anymore
            }
            grid.push_back(line);
        }

        m = (int) grid.size(); // number of rows
        n = (int) grid[0].size(); // number of columns

        // a 2d vector to hold all the area totals
        std::vector<std::vector<int>> totals(m, std::vector<int>(n, 0));

        // we need to an intial bfs to cover all cases
        // otherwise we TLE if perform a brand new bfs for each input
        bool visited[MAX][MAX] = {false};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == 'W') {
                    bfs(i, j, grid, visited, totals);
                }
            }
        }

        do {
            if (line.empty()) { break; };
            std::istringstream is(line);
            is >> x >> y;
            printf("%d\n", totals[x-1][y-1]);
        } while (std::getline(std::cin, line));

        if (tests) {
            printf("\n");
        }
    }
    return 0;
}
