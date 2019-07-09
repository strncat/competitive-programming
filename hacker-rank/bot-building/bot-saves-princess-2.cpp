//
//  main.cpp
//  princess
//
//  Created by Fatima B on 10/6/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <vector>



void next_move(std::vector<std::string> grid, int n) {
    int p_x=0, p_y=0, x=0, y=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'p') {
                p_x = i;
                p_y = j;
            }
            if (grid[i][j] == 'm') {
                x = i;
                y = j;
            }
        }
    }

    while (x < n-1 && x < p_x) {
        printf("DOWN\n");
        return;
    }

    while (x > 0 && x > p_x) {
        printf("UP\n");
        return;
    }

    while (y < n-1 && y < p_y) {
        printf("RIGHT\n");
        return;
    }

    while (y < n-1 && y > p_y) {
        printf("LEFT\n");
        return;
    }
}

void tests() {
    std::vector<std::string> grid = {"---","-m-","p--"};
    next_move(grid, 3);
}

int main() {
    //tests();
    int n, x, y;
    std::vector<std::string> grid;
    scanf("%d", &n);
    scanf("%d %d", &x, &y);
    for(int i = 0; i < n; i++) {
        std::string s; std::cin >> s;
        grid.push_back(s);
    }
    next_move(grid, n);
    return 0;
}
