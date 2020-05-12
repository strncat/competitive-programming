//
//  10908 Largest Square
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


int main() {
    //freopen("in.txt" , "r" , stdin);

    int tests, n, m, q;
    scanf("%d\n", &tests);

    while (tests--) {
        scanf("%d %d %d\n", &m, &n, &q);

        std::vector<std::string> grid;
        std::string line;
        for (int i = 0; i < m; i++) {
            std::getline(std::cin, line);
            grid.push_back(line);
        }

        printf("%d %d %d\n", m, n, q);

        int x, y;

        while (q--) {
            scanf("%d %d", &x, &y);
            char c = grid[x][y];

            // maybe not the best idea but it is a pretty simple one
            // move to the top left corner and loop around to check all the characters
            // we check the positions in the following order
            // 1 2 3
            // 8 c 4
            // 7 6 5
            int distance = 1;
            int largest_side = 1;

            while (1) {
                x--; y--;

                if (x < 0 || y < 0) {
                    break;
                }

                // move right to check the top side of the square "1 2" above
                bool error = false;
                int ds = distance;
                while (ds-- >= 0) {
                    if (y >= n || x < 0 || grid[x][y] != c) { // out of bounds or not the same character
                        error = true;
                        break;
                    }
                    y++; // otherwise increment y
                }
                if (error) { break; }

                // move down to check the right side of the square, "3 4" in the matrix above
                ds = distance;
                while (ds-- >= 0) {
                    if (x >= m || y >= n || grid[x][y] != c) {
                        error = true;
                        break;
                    }
                    x++;
                }
                if (error) { break; }


                // move left to check the bottom side of the square, "5, 6" in the matrix above
                ds = distance;
                while (ds-- >= 0) {
                    if (y < 0 || x >= m || grid[x][y] != c) {
                        error = true;
                        break;
                    }
                    y--;
                }
                if (error) { break; }

                // move up to check the left side of the square, "7, 8" in the matrix above
                ds = distance;
                while (ds-- >= 0) {
                    if (x < 0 || y < 0 || grid[x][y] != c) {
                        error = true;
                        break;
                    }
                    x--;
                }
                if (error) { break; }

                largest_side+=2;
                distance+=2;
            }
            printf("%d\n", largest_side);
        }

    }
    return 0;
}
