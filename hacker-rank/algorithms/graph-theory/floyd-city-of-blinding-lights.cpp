//
//  Hacker Rank
//  Floyd : City of Blinding Lights
//
//  Created by Fatima B on 01/01/16.
//  Copyright © 2015 Fatima B. All rights reserved.


#include <iostream>
#include <algorithm>
#include <limits.h>

#define N 1002
int distance[N][N];

void print(int a[N][N], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 100) {
                printf("*\t");
            } else {
                printf("%d\t", a[i][j]);
            }
        }
        printf("\n");
    }
}

int minimum(int a[N][N], int n) {
    int minimum = INT_MAX;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] < minimum) {
                minimum = a[i][j];
            }
        }
    }
    return minimum;
}

void print(int *distance, int n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 1; i <= n; i++) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}

void floydWarshall(int n) { // O(n^3)
    // dynamic programming recurrence:
    // the shortest path between i and j contains some internal nodes (node: those nodes can't be repeated)
    // let k be an internal node, either node k is on the optimal path or it's not
    // if k is on the path => the shortest distance is d[i][k] + d[k][j]
    // if k is not on the optimal path => the shortest distance is dij
    // if k is zero, then the shortest distance is just wij (if it exist) otherwise infinity
    for (int k = 1; k <= n; k++) { // number of internal nodes on the path        for (int i = 1; i <= n; i++) {            for (int j = 1; j <= n; j++) {
                if (distance[i][k] == INT_MAX || distance[k][j] == INT_MAX) { continue; }
                // current distance vs distance though k (from i to k then k to j)                distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    // checking for negative cycles
    for (int i = 1; i <= n; i++) {
        if (distance[i][i] < 0) {
            printf("negative cycle detected\n");
            return; // we should not use the distance matrix if negative cycles were detected
        }
    }
}

int main() {
    int n, m, v, w, q, d;

    scanf("%d %d", &n, &m);

    // initalize everything to INT_MAX
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) { // distance from a node to itself is zero
                distance[i][j] = 0;
            } else {
                distance[i][j] = INT_MAX;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &v, &w, &d);
        distance[v][w] = d;
    }
    // run floyd warshall to compute all pairs shortest paths
    floydWarshall(n);

    scanf("%d", &q);
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &v, &w);
        if (distance[v][w] == INT_MAX) {
            printf("-1\n");
        } else {
            printf("%d\n", distance[v][w]);
        }
    }
    return 0;
}
