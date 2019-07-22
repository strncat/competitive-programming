//
//
//  10449 Traffic
//
//  Created by FB on 7/9/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>
#include <vector>

#define MAX 999999

typedef std::vector<std::vector<std::pair<int,int>>> graph;

void BellmanFord(graph& g, int *distance) {
    //int parent[g.size()];
    for (int i = 0; i < g.size(); i++) {
        distance[i] = MAX;
        //parent[i] = -1;
    }
    distance[0] = 0; // source is node 1

    for (int s = 1; s <= (int)g.size() - 1; s++) { // for every possible path size
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
    int h = 2;
    while (h--) {
    for (int i = 0; i < g.size(); i++) { // for every edge in the graph
        for (auto e = g[i].begin(); e != g[i].end(); e++) {
            int y = e->first;
            int weight = e->second;
            if (distance[i] != MAX && distance[i] + weight < distance[y]) {
                distance[y] = -99999;
            }
        }
    }
    }
    return;
}

int main() {
    //freopen("in.txt", "r", stdin);

    int test = 1, n;
    while (scanf("%d", &n) == 1) {
        graph g;
        std::vector<int> busyness;

        for (int i = 0; i < n; i++) {
            g.push_back(std::vector<std::pair<int,int>>());
            busyness.push_back(0);
        }

        // busyness
        for (int i = 0; i < n; i++) {
            scanf("%d", &busyness[i]);
        }

        // roads
        int m;
        scanf("%d", &m);

        int x, y;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            x--; y--;
            int total = busyness[y]-busyness[x];
            g[x].push_back(std::pair<int,int>(y,total*total*total));
        }

        printf("Set #%d\n", test++);

        int distance[g.size()];
        BellmanFord(g, distance); // run bellman ford from the zero point

        // queries
        int q, source;
        scanf("%d", &q);

        for (int i = 0; i < q; i++) {
            scanf("%d", &source);
            source--;
            if (distance[source] < 3 || distance[source] == MAX) {
                printf("?\n");
            } else {
                printf("%d\n", distance[source]);
            }
        }

    }
    return 0;
}

