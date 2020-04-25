//
//  567 Risk
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>

#define MAX 21

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

    int v, n, w, test = 1;
    while (scanf("%d", &n) != EOF) {

        v = 1; // this is begining of a test case, v is initialized to 1

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
        // there are 19 lines per each test case
        // each ith line contains the nodes that the ith node is neighbors with
        while (v < 20) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &w);
                distance[v][w] = 1;
                distance[w][v] = 1;
            }
            if (v == 19) { break; } // last input
            v++;
            scanf("%d", &n); // the number of neighbors on the next line
        }

        // (3) run floyd warshall
        floyd_warshall(20);


        // (4) read the vertices we need to investigate and print results
        int count;
        printf("Test Set #%d\n", test++);
        scanf("%d", &count);
        for (int i = 0; i < count; i++) {
            scanf("%d %d", &v, &w);
            printf("%2d to %2d: %d\n", v, w, distance[v][w]);
        }
        printf("\n");
    }
    return 0;
}
