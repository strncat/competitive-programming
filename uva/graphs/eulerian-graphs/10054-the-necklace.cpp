//
//  10054 - The Necklace
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//  Based on https://algs4.cs.princeton.edu/41graph/EulerianCycle.java
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

#define MAX 55

typedef struct {
    int v;
    int w;
    bool used;
} Edge;

std::vector<std::queue<Edge*>> graph;
std::vector<int> degrees;
std::set<int> vertices;

int other_end(int v, Edge *e) {
    if (v == e->v) {
        return e->w;
    } else {
        return e->v;
    }
}

void dfs() {
    std::stack<int> s;
    int start = *vertices.begin();
    s.push(start); // start with some vertex v

    std::stack<int> cycle; // the actual cycle

    while (!s.empty()) {
        int current_node = s.top(); s.pop(); // pick some node

        // now traverse it's edges
        while (!graph[current_node].empty()) {
            // (a) consider an edge between the current node and any of its neighbors
            Edge *edge = graph[current_node].front();
            graph[current_node].pop(); // remove the edge reference (it will still be in w's queue)

            // (b) if it's used then we'll check another. If it's not then mark it used
            if (edge->used) {
                continue;
            }
            edge->used = true; // mark it used

            // (c) push current_node back on the stack so we can go back to it (backtrack to it)
            s.push(current_node); // push current_node

            // (d) move to the other end of edge to process it
            current_node = other_end(current_node, edge);
            //printf("%d ", current_node);
        }
        // push the current_node which has no edges anymore to traverse
        cycle.push(current_node);
    }

    while (cycle.size() > 1) {
        printf("%d ", cycle.top());
        cycle.pop();
        printf("%d\n", cycle.top());
    }
}

bool hasEulerCycle() {
    for (auto v = vertices.begin(); v != vertices.end(); v++) {
        if (degrees[*v] & 1) { //  odd
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("in.txt" , "r" , stdin);
    int m, tests, test = 1;

    scanf("%d", &tests);
    while (tests--) {
        scanf("%d", &m);

        // start over, clear everything
        graph.clear();
        vertices.clear();
        degrees.clear();

        // initialize graph
        for (int i = 0; i < MAX; i++) {
            graph.push_back(std::queue<Edge*>());
            degrees.push_back(0);
        }

        // read edges
        int v, w;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &v, &w);
            Edge *e = new Edge();
            e->v = v;
            e->w = w;
            e->used = false;
            graph[w].push(e);
            graph[v].push(e);
            degrees[v]++;
            degrees[w]++;
            vertices.insert(w);
            vertices.insert(v);
        }

        printf("Case #%d\n", test++);
        // every vertex must be of even degree, otherwise we don't have a cycle
        if (!hasEulerCycle()) {
            printf("some beads may be lost\n");
        } else { // otherwise, we must have an Eulerian cycle
            dfs(); // find it
        }

        if (tests) {
            printf("\n");
        }
    }
    return 0;
}
