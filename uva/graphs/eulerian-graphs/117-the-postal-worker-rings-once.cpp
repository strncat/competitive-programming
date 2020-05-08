//
//  117 - The Postal Worker Rings Once
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
#include <unordered_map>

#define MAX 26

typedef struct Edge {
    int v;
    int w;
    bool used;
    Edge(int v, int w) {
        this->v = v;
        this->w = w;
        this->used = false;
    }
} Edge;

std::vector<std::queue<Edge*>> graph;
std::vector<int> degrees;
std::set<int> vertices;
int cost[27][27];

int other_end(int v, Edge *e) {
    if (v == e->v) {
        return e->w;
    } else {
        return e->v;
    }
}

int dfs(int start) {
    std::stack<int> s;
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

    int v, w, total = 0;
    while (cycle.size() > 1) {
        v = cycle.top(); cycle.pop();
        w = cycle.top();
        //printf("%c-%c\n", v+'a'-1, w+'a'-1);
        total += cost[v][w];
    }
    return total;
}

bool hasEulerCycle() {
    for (auto v = vertices.begin(); v != vertices.end(); v++) {
        if (degrees[*v] & 1) { //  odd
            return false;
        }
    }
    return true;
}

void floyd_warshall() { // O(n^3)
    for (auto k = vertices.begin(); k != vertices.end(); k++) {
        for (auto v = vertices.begin(); v != vertices.end(); v++) {
            for (auto w = vertices.begin(); w != vertices.end(); w++) {
                 if (cost[*v][*k] == INT_MAX || cost[*k][*w] == INT_MAX) { continue; }
                 // current distance vs distance though k (from i to k then k to j)
                 cost[*v][*w] = std::min(cost[*v][*w], cost[*v][*k] + cost[*k][*w]);
            }
        }
    }
}

void printCostMatrix() {
    printf("    ");
    for (auto v = vertices.begin(); v != vertices.end(); v++) {
        printf("%c       ", *v+'a'-1);
    }
    printf("\n");

    for (auto v = vertices.begin(); v != vertices.end(); v++) {
        printf("%c  ", *v+'a'-1);
        for (auto w = vertices.begin(); w != vertices.end(); w++) {
            printf("%d      ", cost[*v][*w]);
        }
        printf("\n");
    }
    printf("\n\n");
}

int main() {
    //freopen("in.txt" , "r" , stdin);
    std::string s;

    while (1) {
        // start over, clear everything
        graph.clear();
        vertices.clear();
        degrees.clear();

        // initialize graph
        for (int i = 0; i < MAX; i++) {
            graph.push_back(std::queue<Edge*>());
            degrees.push_back(0);
        }

        // (1) initialize distance matrix
        for (int i = 1; i < MAX; i++) {
            for (int j = 1; j < MAX; j++) {
                if (i == j) {
                    cost[i][j] = 0;
                } else {
                    cost[i][j] = 99; // otherwise infinity
                }
            }
        }

        // read edges
        int count = 0;
        while (std::cin >> s) {
            if (s == "deadend") {
                break;
            }
            count++;
            int v = s[0]-'a'+1;
            int w = s[s.size()-1]-'a'+1;
            Edge *e = new Edge(v, w);
            graph[w].push(e);
            graph[v].push(e);
            degrees[v]++;
            degrees[w]++;
            vertices.insert(w);
            vertices.insert(v);
            int n = (int)s.length();
            cost[v][w] = n;
            cost[w][v] = n;
        }

        if (!count) { break; } // no more cases

        if (hasEulerCycle()) {
            int start_node = *vertices.begin();
            printf("%d\n", dfs(start_node)); // find the eulerian cycle
        } else {
            // find the odd degree vertices
            int start_node = -1, end_node = -1;
            for (auto v = vertices.begin(); v != vertices.end(); v++) {
                if (degrees[*v] & 1) {
                    if (start_node == -1) { //  odd
                        start_node = *v;
                    } else {
                        end_node = *v;
                    }
                }
            }
            // (1) find the eulerian path
            int total = dfs(start_node);

            //printCostMatrix();

            // (2) run floyd warshall on the ends
            floyd_warshall();
            total += cost[start_node][end_node];

            //printCostMatrix();


            // assuming all vertices are of even degree
            printf("%d\n", total); // find the eulerian cycle
        }
    }
    return 0;
}
