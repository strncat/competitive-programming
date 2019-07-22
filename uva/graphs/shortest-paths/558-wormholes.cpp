//
//
//  558 - Wormholes
//
//  Created by FB on 7/9/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>
#include <vector>

#define MAX 999999

typedef std::vector<std::vector<std::pair<int,int>>> graph;
/*
void print(int *distance, long n) {
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t\t %d\n", i, distance[i]);
    }
}
*/
bool BellmanFord(graph& g) {
    int distance[g.size()];
    //int parent[g.size()];
    for (int i = 0; i < g.size(); i++) {
        distance[i] = MAX;
        //parent[i] = -1;
    }
    distance[0] = 0; // source is node 1

    // Bellman-Ford Dynamic Programming Recurrence
    // let L(i,v) the minimum length of an s-v path
    // L(i,v) = min {L(i-1,v), min over all u-w paths {L(i-1,v) + weight of v-w}}

    for (int s = 1; s <= g.size() - 1; s++) { // for every possible path size

        // for every edge in the graph // double loop
        for (int i = 0; i < g.size(); i++) {
            for (auto e = g[i].begin(); e != g[i].end(); e++) {
                int y = e->first;
                int weight = e->second;

                // Recurrence
                if (distance[i] != MAX && distance[i] + weight < distance[y]) {
                    distance[y] = distance[i] + weight;
                }
            }
        }
    }

    // check for cycles!
    for (int i = 0; i < g.size(); i++) { // for every edge in the graph
        for (auto e = g[i].begin(); e != g[i].end(); e++) {
            int y = e->first;
            int weight = e->second;
            if (distance[i] != MAX && distance[i] + weight < distance[y]) {
                return false; // negative cycle
            }
        }
    }
    //print(distance, g.size());
    return true;
}

int main() {
    //freopen("in.txt", "r", stdin);

    int tests;
    scanf("%d", &tests);

    while (tests--) {
        graph g;
        int n, m;
        scanf("%d %d", &n, &m);

        for (int i = 0; i < n; i++) {
            g.push_back(std::vector<std::pair<int,int>>());
        }

        int x, y, w;
        for (int i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &w);
            g[x].push_back(std::pair<int,int>(y,w));
        }

        if (BellmanFord(g)) {
            printf("not possible\n");
        } else {
            printf("possible\n");
        }

    }
    return 0;
}

