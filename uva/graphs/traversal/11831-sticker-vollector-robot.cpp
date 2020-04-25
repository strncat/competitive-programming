//
//  11831 - Sticker Collector Robot
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <unordered_map>

int main() {
    //freopen("in.txt" , "r" , stdin);

    // If we're moving right, orientation changes to the following
    std::unordered_map<char,char> right, left;
    right['N'] = 'E'; right['S'] = 'W'; right['E'] = 'S'; right['W'] = 'N';
    left['N'] = 'W'; left['S'] = 'E'; left['W'] = 'S'; left['E'] = 'N';

    // THE KEY TO THIS PROBLEM IS THIS
    // When a robot tries to move into a cell which contains a pillar he stalls,
    // remaining in the cell where he was, with the same orientation.
    // The same happens when a robot tries to leave the arena.
    // THIS MEANS THAT WHEN A ROBOT FACES a # OR a BOUNDARY, WE JUST STOP MOVING
    // UNTIL WE MOVE DIRECTIONS, IT DOESN'T MEAN WE EXIT.


    int m, n, c;
    char grid[102][102];
    while (scanf("%d %d %d\n", &m, &n, &c) == 3) {
        if (m == 0 && n == 0 && c == 0) {
            break;
        }
        // read the grid
        int x = 0, y = 0;
        char orientation = 'N';
        std::string line;
        for (int i = 0; i < m; i++) {
            std::getline(std::cin, line); // a line here is 123
            // no input, return false (we didn't read anything)
            if (line.size() == 0) { break; }
            for (int j = 0; j < n; j++) {
                grid[i][j] = line[j];
                if (grid[i][j] == 'N' || grid[i][j] == 'S' || grid[i][j] == 'L' ||
                    grid[i][j] == 'O' ) { // starting cells, can have multiple
                    x = i;
                    y = j;
                    orientation = grid[i][j];
                }
            }
        }

        // print the fucking board
        //for (int i = 0; i <= m+1; i++) {
        //    for (int j = 0; j <= n+1; j++) {
        //        printf("%c", grid[i][j]);
        //    }
        //    printf("\n");
        //}

        // I just prefer East and West!
        if (orientation == 'L') { orientation = 'E';
        } else if (orientation == 'O') { orientation = 'W'; }

        // read moves
        std::string moves;
        std::getline(std::cin, moves);

        // traverse moves
        int stickers = 0;
        for (int i = 0; i < moves.size(); i++) {
            if (moves[i] == 'E') { // left
                orientation = left[orientation];
            } else if (moves[i] == 'D') { // right
                orientation = right[orientation];
            } else { // FORWARD
                if (orientation ==  'N' && x-1 >= 0 && grid[x-1][y] != '#') {
                    x--;
                } else if (orientation == 'S' && x+1 < m && grid[x+1][y] != '#') {
                    x++;
                } else if (orientation == 'W' && y-1 >= 0 && grid[x][y-1] != '#') {
                    y--;
                } else if (orientation == 'E' && y+1 < n && grid[x][y+1] != '#') {
                    y++;
                }

                // collect sticker if any
                if (grid[x][y] == '*') {
                    stickers++;
                    grid[x][y] = '.'; // stickers are not replacable
                }
            }
        }
        // done
        printf("%d\n", stickers);
    }

    return 0;
}
