//
//  423 - MPI Maelstrom
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

// A BFS Should be more than enough but I was lazy
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

    int n;
    while (scanf("%d", &n) != EOF) {

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

        // (2) read the graph
        int d;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (scanf("%d", &d) == 1) {
                    distance[i][j] = distance[j][i] = d;
                } else {
                    scanf("%*c"); // read x
                }
            }
        }

        // (3) run floyd warshall
        floyd_warshall(n);


        // (4) find the max distance from the first node to all other nodes
        int max_distance = 0;
        for (int i = 1; i <= n; i++) {
            if (distance[1][i] > max_distance) {
                max_distance = distance[1][i];
            }
        }
        printf("%d\n", max_distance);
    }
    return 0;
}
