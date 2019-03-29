//
//  539 - The Settlers of Catan
//  100 days challenge
//
//  Created by FB on 9/22/17.
//  Copyright © 2017 FB. All rights reserved.
//
//  It took me a while to figure this one out because I'm dumbbbbbbb
//  I was trying to model this with an adjaceny data structure
//  It was a pain, like how to keep track of multiple edges and visited edges, took me hours
//  AHHH I couldn't see that the number of nodes is so small, a simple matrix will do!
//  The rest is just backtracking, don't forget to put back the edges after doing a dfs!
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int dfs(int graph[30][30], int n, int u) {
    int max_distance = 0;
    for (int v = 0; v < n; v++) {
        if (graph[u][v]) {
        // remove from current and neigbor
            graph[u][v]--;
            graph[v][u]--;

            int distance = 1 + dfs(graph, n, v);
            if (distance > max_distance) { max_distance = distance; }

            graph[u][v]++;
            graph[v][u]++;
        }
    }
    return max_distance;
}

int main() {
    freopen("example.in", "r", stdin);

    int n, e;
    while (scanf("%d %d", &n, &e) != EOF) {
        if (n == 0 && e == 0) { break; }

        int v, u, graph[30][30];
        for (int i = 0; i < 30; i++) {
            for (int j = 0; j < 30; j++) {
                graph[i][j] = 0;
            }
        }

        for (int i = 0; i < e; i++) {
            scanf("%d %d", &v, &u);
            graph[u][v]++;
            graph[v][u]++;
        }

        int max_distance = 0;
        for (int i = 0; i < n; i++) {
            int distance = dfs(graph, n, i);
            if (distance > max_distance) { max_distance = distance; }
        }
        printf("%d\n", max_distance);
        
    }
    return 0;
}
