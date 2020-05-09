//
//  10452 - Marcus
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

void dfs(std::vector<std::string> grid,
         std::queue<std::string>& path,
         std::string stones_order,
         int index,
         int x, int y) {
    if (grid[x][y] == '#') { // reached destination
        printf("%s", path.front().c_str());
        path.pop();
        while (!path.empty()) {
            printf(" %s", path.front().c_str());
            path.pop();
        }
        printf("\n");
        return;
    }

    // forth (up)
    if (x > 0 && grid[x-1][y] == stones_order[index]) {
        path.push("forth");
        dfs(grid, path, stones_order, index+1, x-1, y);
    }

    // right
    if (y < grid[0].size() && grid[x][y+1] == stones_order[index]) {
        path.push("right");
        dfs(grid, path, stones_order, index+1, x, y+1);
    }

    // left
    if (y > 0 && grid[x][y-1] == stones_order[index]) {
        path.push("left");
        dfs(grid, path, stones_order, index+1, x, y-1);
    }
}

int main() {
    //freopen("in.txt" , "r" , stdin);

    int tests, n, m, x = 0, y = 0;
    scanf("%d\n", &tests);
    std::vector<std::string> grid;
    std::string line;

    while (tests--) {
        grid.clear();
        scanf("%d %d\n", &m, &n);
        for (int i = 0; i < m; i++) {
            std::getline(std::cin, line);
            grid.push_back(line);
            // find starting position
            for (int j = 0; j < n; j++) {
                if (line[j] == '@') {
                    x = i;
                    y = j;
                }
            }
        }
        // must go through the stones in a specific order!
        std::string stones_order = "IEHOVA#";
        std::queue<std::string> path;
        std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
        dfs(grid, path, stones_order, 0, x, y);
    }
    return 0;
}
