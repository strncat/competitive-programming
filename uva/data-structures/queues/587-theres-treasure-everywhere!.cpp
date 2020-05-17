//
//  587 - There's treasure everywhere!
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include <stack>
#include <unordered_map>

int main() {
    //freopen("in.txt" , "r" , stdin);

    // this map just keeps track of the direction
    std::unordered_map<std::string, std::pair<int,int>> map;
    map["N"] = std::make_pair(0,1);
    map["NE"] = std::make_pair(1,1);
    map["E"] = std::make_pair(1,0);
    map["SE"] = std::make_pair(1,-1);
    map["S"] = std::make_pair(0,-1);
    map["SW"] = std::make_pair(-1,-1);
    map["W"] = std::make_pair(-1,0);
    map["NW"] = std::make_pair(-1,1);

    std::string s;
    int test = 1;
    while (std::cin >> s) {
        if (s == "END") {
            break;
        }
        // (1) strip commas and last period
        std::vector<std::string> directions;
        std::stringstream s_stream(s); //create string stream from the string
        while (s_stream.good()) {
            std::string substr;
            getline(s_stream, substr, ','); //get first string delimited by comma
            directions.push_back(substr);
        }
        directions[directions.size()-1].pop_back();

        // (2) apply directions
        double x = 0.0, y = 0.0;
        for (auto d = directions.begin(); d != directions.cend(); d++) {
            int distance = std::stoi(*d);
            std::string t = std::to_string(distance);
            std::string dir = d->substr(t.size());
            std::pair<int,int> action = map[dir];

            // for N, S, W and E we just multiply the distance by the direction
            if (dir.size() == 1) {
                x += (action.first * distance);
                y += (action.second * distance);
            } else {
                // otherwise, if we're going into SE, NW, SW or NE
                // the distance from 0,0 to 1,1 or -1,1, or 1,-1 or -1,-1 is actually sqrt(2)
                // therefore, we if we want to know the actual coordinate position, we need
                // to divide the distance by sqrt(2)
                x += (distance / sqrt(2)) * action.first;
                y += (distance / sqrt(2)) * action.second;
            }
        }

        printf("Map #%d\n", test++);
        printf("The treasure is located at (%.3f,%.3f).\n", x, y);
        printf("The distance to the treasure is %.3f.\n\n", sqrt(x*x+y*y));

    }

    return 0;
}
