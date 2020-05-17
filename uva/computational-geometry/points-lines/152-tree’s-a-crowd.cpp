//
//  152 Tree’s a Crowd
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
#include <unordered_map>

int main() {
    //freopen("in.txt" , "r" , stdin);

    int x, y, z, n = 0;
    int points[5001][3];
    while (scanf("%d %d %d", &x, &y, &z)) {
        if (x == 0 && y == 0 && z == 0) {
            break; // end of input
        }
        points[n][0] = x;
        points[n][1] = y;
        points[n][2] = z;
        n++;
    }

    int distance[11] = {0};

    // The trick in this problem is that you need to find the distance to the CLOSEST
    // NEIGHBOR. I additionally avoid using floats/double by using the distance squared

    for (int i = 0; i < n; i++) {
        // find the closest neighbor to points[i]
        int min = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            int xdiff = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]);
            int ydiff = (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
            int zdiff = (points[i][2] - points[j][2]) * (points[i][2] - points[j][2]);
            int sum = xdiff + ydiff + zdiff;
            if (sum < min) {
                min = sum;
            }
        }
        
        if (min < 1) { // less than 1
            distance[1]++;
        } else if (min < 4) { // less than 2
            distance[2]++;
        } else if (min < 9) { // less than 3
            distance[3]++;
        } else if (min < 16) { // less than 4
            distance[4]++;
        } else if (min < 25) {
            distance[5]++;
        } else if (min < 36) {
            distance[6]++;
        } else if (min < 49) {
            distance[7]++;
        } else if (min < 64) {
            distance[8]++;
        } else if (min < 81) {
            distance[9]++;
        } else if (min < 100) {
            distance[10]++;
        }
    }

    for (int i = 1; i <= 10; i++) {
        printf("%4d", distance[i]);
    }
    printf("\n");

    return 0;
}
