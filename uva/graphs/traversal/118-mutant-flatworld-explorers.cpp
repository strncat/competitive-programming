//
//  118 - Mutant Flatworld Explorers
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <unordered_map>

int main() {
    freopen("in.txt" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    int x, y, m, n;
    bool scent[100][100] = {0};
    char orientation;
    scanf("%d %d", &m, &n);

    // If we're moving right, orientation changes to the following
    std::unordered_map<char,char> right;
    right['N'] = 'E'; right['S'] = 'W'; right['E'] = 'S'; right['W'] = 'N';

    // similarly, if we're moving left, then we turn to the following
    std::unordered_map<char,char> left;
    left['N'] = 'W'; left['S'] = 'E'; left['W'] = 'S'; left['E'] = 'N';

    while (scanf("%d %d %c", &x, &y, &orientation) == 3) {
        std::string s;
        std::cin >> s;
        bool lost = false;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'L') {
                orientation = left[orientation];
            } else if (s[i] == 'R') {
                orientation = right[orientation];
            } else { // FORWARD
                switch (orientation) {
                    case 'N':
                        y++; break;
                    case 'E':
                        x++; break;
                    case 'W':
                        x--; break;
                    case 'S':
                        y--; break;
                }

                // if we fell off, we are either lost or saved by a scent
                // in either case we take a step back to the original position
                if (y > n || x > m || x < 0 || y < 0) {
                    switch (orientation) {
                        case 'N':
                            y--; break;
                        case 'E':
                            x--; break;
                        case 'W':
                            x++; break;
                        case 'S':
                            y++; break;
                    }

                    // if there was no scent, then we are lost and we put a scent
                    if (!scent[x][y]) {
                        lost = true;
                        scent[x][y] = true;
                    }
                }
                if (lost) { break; }
            }
        }
        // done
        if (lost) {
            printf("%d %d %c LOST\n", x, y, orientation);
        } else {
            printf("%d %d %c\n", x, y, orientation);
        }
    }

    return 0;
}
