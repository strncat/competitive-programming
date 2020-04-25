//
//  280 - Vertex
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//
//  A Vanilla approach (aka BFS) doesn't work (TLE)
//  I used Floyd Warshall instead which was enough

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

#define MAX 102

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

    int n, v, w;
    while (scanf("%d\n", &n) == 1 && n != 0) {
        // (1) initialize distance matrix
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                distance[i][j] = INT_MAX; // otherwise infinity
            }
        }

        // (2) read graph, each line starts with the starting vertex v
        // each node that comes after that w, indicates there is an edge v->w
        while (scanf("%d", &v) && v != 0) {
            while (scanf("%d", &w) && w != 0) {
                distance[v][w] = 1; // SOME CONSTANT THAT's NOT INFINITY
            }
        }

        // (3) run floyd warshall
        floyd_warshall(n);

        // (4) find all unreachable nodes
        std::vector<std::vector<int>> unreachable;
        for (int i = 0; i <= n; i++) {
            unreachable.push_back(std::vector<int>());
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) { // check against all nodes
                if (distance[i][j] == INT_MAX) {
                    unreachable[i].push_back(j);
                }
            }
        }

        // (5) read the vertices we need to investigate and print results
        int count;
        std::vector<int> q;
        scanf("%d", &count);
        for (int i = 0; i < count; i++) {
            scanf("%d", &v);
            int num_unreachable = (int)unreachable[v].size();
            printf("%d", num_unreachable);
            for (int j = 0; j < num_unreachable; j++) {
                printf(" %d", unreachable[v][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
