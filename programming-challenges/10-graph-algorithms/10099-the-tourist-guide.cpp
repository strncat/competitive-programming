//
//  10099 - The Tourist Guide
//  100 days challenge
//
//  Created by FB on 9/22/17.
//  Copyright © 2017 FB. All rights reserved.
//

// my first idea was to do dfs and get all the paths and find the best one (with pruning paths by tracking a global min)
// my approach TLEd obviously and I eventually wanted to use prim or kruskal and then on top do a bfs agh
// I came across this modification though which is brilliant, really pretty oh my god fabulous I should say
// while doing Kruskal just stop whenever both nodes are connected and at that point you know that this edge
// is the lowest possible which is the value you want anyway! nice

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

class Edge {
public:
    int x;
    int y;
    int weight;
    Edge(int x, int y, int weight) {
        this->x = x;
        this->y = y;
        this->weight = weight;
    }
};

typedef std::vector<Edge> graph;

bool comp(Edge e1, Edge e2) {
    return e1.weight > e2.weight;
}

int findComponentLeader(int *leader, int x) { // O(log*(n))
    while (leader[x] != x) { // go up the tree
        leader[x] = leader[leader[x]]; // path compression
        x = leader[x];
    }
    return x;
}

void unionNodes(int u, int v, int *leader, int *followers) {
    if (followers[u] <= followers[v]) {
        leader[u] = v;
        followers[v]++;
    } else {
        leader[v] = u;
        followers[u]++;
    }
}

int kruskal(graph &g, int n, int source, int dest) {
    std::sort(g.begin(), g.end(), comp);

    int leader[105];
    int followers[105];
    for (int i = 0; i < n; i++) {
        leader[i] = i; // each node is in its own component/group initially
        followers[i] = 0; // initially no followers
    }

    // go through the edges sorted (largest first)
    for (int i = 0; i < g.size(); i++) {

        int u = findComponentLeader(leader, g[i].x);
        int v = findComponentLeader(leader, g[i].y);

        if (u != v) {
            unionNodes(u, v, leader, followers);
        }

        int sourceGroup = findComponentLeader(leader, source);
        int destGroup = findComponentLeader(leader, dest);

        if (sourceGroup == destGroup) {
            // we're finally connected and this is our weakest link
            return g[i].weight;
        }
    }
    return 0;
}

int main() {
    //freopen("example.in", "r", stdin);
    int n, e, test_case = 1;
    while (scanf("%d %d", &n, &e)) {
        if (n == 0 && e == 0) { break; }

        graph g;
        int u, v, capacity;
        for (int i = 0; i < e; i++) {
            scanf("%d %d %d", &u, &v, &capacity);
            g.push_back(Edge(u-1, v-1, capacity));
        }

        int source, dest, tourists;
        scanf("%d %d %d", &source, &dest, &tourists);

        int MaxMin = kruskal(g, n, source-1, dest-1);

        printf("Scenario #%d\n", test_case++);
        printf("Minimum Number of Trips = %d\n\n", (int)ceil(tourists*1.0/(MaxMin-1)));
    }
    return 0;
}
