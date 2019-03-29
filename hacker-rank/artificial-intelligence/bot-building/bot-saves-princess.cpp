//
//  main.cpp
//  princess
//
//  Created by Fatima B on 10/6/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <vector>



void find_path_to_princess(std::vector<std::string> grid, int n) {
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

    while (x < p_x) {
        printf("DOWN\n");
        x = x+1;
    }

    while (x > p_x) {
        printf("UP\n");
        x = x-1;
    }

    while (y < p_y) {
        printf("RIGHT\n");
        y = y+1;
    }

    while (y > p_y) {
        printf("LEFT\n");
        y = y-1;
    }
}

void tests() {
    std::vector<std::string> grid = {"---","-m-","p--"};
    find_path_to_princess(grid, 3);
}

int main() {
    //tests();
    int n;
    std::vector<std::string> grid;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        std::string s; std::cin >> s;
        grid.push_back(s);
    }
    find_path_to_princess(grid, n);
    return 0;
}
