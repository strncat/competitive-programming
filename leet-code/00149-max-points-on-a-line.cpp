//
//  main.cpp
//  x
//
//  Created by FB on 2/4/20.
//  Copyright © 2020 FB. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <queue>
#include <numeric>

using namespace std;

struct pair_hash {
public:
  template <typename T, typename U>
  std::size_t operator()(const std::pair<T, U> &x) const {
    return std::hash<T>()(x.first) ^ std::hash<U>()(x.second);
  }
};

int gcd(int a, int b) {
  while (b != 0)  {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

// method to find maximum colinear point
int max_points(vector<pair<int,int>> points) {
    int n = (int)points.size();
    if (n < 2) {
        return n;
    }
    int max = 0;
    int cur_max, same_points, vertical_points;

    unordered_map<pair<int,int>, int, pair_hash> slope_map;

    // we compute all possible lines
    // for each point i
    for (int i = 0; i < n; i++) {
        cur_max = 0;
        same_points = 0;
        vertical_points = 0;
        // for each j ... so now we have a possible line with i and j
        for (int j = i + 1; j < n; j++) {
            if (points[i] == points[j]) { // same point
                same_points++;
            } else if (points[i].first == points[j].first) { // vertical line
                vertical_points++;
            } else {
                // slope = y_diff / x_diff
                // before incrementing the count for this slope
                // divide by the gcd
                int y_diff = points[j].second - points[i].second;
                int x_diff = points[j].first - points[i].first;
                int g = gcd(x_diff, y_diff);
                y_diff /= g;
                x_diff /= g;
                slope_map[make_pair(y_diff, x_diff)]++;

                // compute the current max
                cur_max = std::max(cur_max, slope_map[make_pair(y_diff, x_diff)]);
            }
            // which is better?
            // this slope?
            // the current max?
            // the number of vertical points with this current point
            cur_max = std::max(cur_max, vertical_points);
        }

        // global best line
        max = std::max(max, cur_max + same_points + 1);
        slope_map.clear();
    }
    return max;
}

int main(int argc, const char * argv[]) {
    vector<pair<int,int>> points = {make_pair(1,1), make_pair(2,2), make_pair(3,3)};
    std::cout << max_points(points) << std::endl;
    return 0;
}
