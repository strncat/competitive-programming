//
//  821 - Page Hopping
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <set>

#define MAX 101

int distance[MAX][MAX];

void floyd_warshall(int n) { // O(n^3)
    // dynamic programming recurrence:
    // the shortest path between i and j contains some internal nodes (none repeated, simple path)
    // let k be an internal node, either node k is on the optimal path or it's not
    // if k is on the path => the shortest distance is d[i][k] + d[k][j]
    // if k is not on the optimal path => the shortest distance is dij
    // if k is zero, then the shortest distance is just wij (if it exist) otherwise infinity
    for (int k = 1; k <= n; k++) { // number of internal nodes on the path
        for (int i = 1; i <= n; i++) {
             for (int j = 1; j <= n; j++) {
                 if (distance[i][k] == INT_MAX || distance[k][j] == INT_MAX) { continue; }
                 // current distance vs distance though k (from i to k then k to j)
                 distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
}

int main() {
    //freopen("in.txt" , "r" , stdin);

    int v, w, test = 1;
    while (scanf("%d %d", &v, &w) && v != 0 && w != 0) {

        // (1) initialize distance matrix
        for (int i = 1; i < MAX; i++) {
            for (int j = 1; j < MAX; j++) {
                if (i == j) {
                    distance[i][j] = 0;
                } else {
                    distance[i][j] = INT_MAX; // otherwise infinity
                }
            }
        }

        distance[v][w] = 1;
        // (2) continue reading the graph
        std::set<int> vertices;
        while (scanf("%d %d", &v, &w) && v != 0 && w != 0) {
            distance[v][w] = 1;
            vertices.insert(v);
            vertices.insert(w);
        }

        // (3) run floyd warshall
        floyd_warshall(MAX-1);


        // (4) add all distances from all possible paths
        int sum = 0;
        int count = (int)vertices.size();
        for (auto v = vertices.begin(); v != vertices.end(); v++) {
            for (auto w = vertices.begin(); w != vertices.end(); w++) {
                if (*v != *w) {
                    sum += distance[*v][*w];
                }
            }
        }

        printf("Case %d: average length between pages = %1.3f clicks\n",
               test++, (float) sum / (count*(count-1)));

    }
    return 0;
}
