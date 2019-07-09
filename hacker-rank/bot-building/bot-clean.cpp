//
//  BotClean
//
//  Created by Fatima B on 10/6/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <vector>

void next_move(std::vector<std::string> grid, int n, int x, int y) {
    if (grid[x][y] == 'd') {
        printf("CLEAN\n");
        return;
    }

    // find the closest bot
    int d=99, opt_x=0, opt_y=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'd') {
                if (abs(i-x) + abs(j-y) < d) {
                    d = abs(i-x) + abs(j-y);
                    opt_x = i;
                    opt_y = j;
                }
            }
        }
    }

    // go toward the closest x/y
    if (abs(opt_x - x) > abs(opt_y - y)) {
        if (x < opt_x && x < n-1) {
            printf("DOWN\n");
        } else {
            printf("UP\n");
        }
    } else {
        if (y < opt_y && y < n-1) {
            printf("RIGHT\n");
        } else {
            printf("LEFT\n");
        }
    }
}

void tests() {
    std::vector<std::string> grid = {"b---d",
        "-d--d",
        "--dd-",
        "--d--",
        "----d"};
    next_move(grid, 5, 0, 0);
}

int main() {
    //tests();
    int n = 5, x, y;
    std::vector<std::string> grid;
    scanf("%d %d", &x, &y);
    for(int i = 0; i < n; i++) {
        std::string s; std::cin >> s;
        grid.push_back(s);
    }
    next_move(grid, n, x, y);
    return 0;
}
