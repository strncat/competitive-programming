//
//  Hacker Rank
//  Kruskal (MST): Really Special Subtree
//
//  Created by Fatima B on 12/30/15.
//  Copyright © 2015 Fatima B. All rights reserved.
//


#include <iostream>
#include <vector>
#include <queue>
#include <assert.h>
#include <algorithm>

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
    bool operator<(const Edge &e) const { return weight < e.weight; }
};

class Graph {
public:
    std::vector<Edge> edges;
    int nvertices;
    Graph(int nvertices) {
        this->nvertices = nvertices;
    }
    void insertEdge(int x, int y, int weight) {
        edges.push_back(Edge(x, y, weight));
    }
};


class UnionByRank {
public:
    int *leader;
    int *rank;
    int n;
    int count;
    UnionByRank(int n) {
        this->n = n;
        count = n; // initially the number of components is n
        leader = new int[n];
        rank = new int[n];
        for (int i = 1; i <= n; i++) {
            leader[i] = i; // each item is in its own component
            rank[i] = 0;
        }
    }
    int findOP(int x) { // O(log(n))
        while (leader[x] != x) { // go up the tree
            leader[x] = leader[leader[x]]; // path compression
            x = leader[x];
        }
        return x;
    }
    int connected(int x, int y) {
        return findOP(x) == findOP(y);
    }
    void combine(int x, int y) {
        int rootX = findOP(x);
        int rootY = findOP(y);
        if (rootX == rootY) { return; }

        // both have the same size, you're putting one under the other so the rank goes up by one
        if (rank[rootX] == rank[rootY]) {
            leader[rootX] = rootY;
            rank[rootY]++;
        } else if (rank[rootX] < rank[rootY]) { // otherwise rank doesn't change
            leader[rootX] = rootY;
        } else {
            leader[rootY] = rootX;
        }
        count--;
    }
};

int kruskal(Graph g, int start) {
    std::sort(g.edges.begin(), g.edges.end());
    UnionByRank ur = UnionByRank(g.nvertices);

    // consider each edge
    int sum = 0;
    for (std::vector<Edge>::iterator i = g.edges.begin(); i != g.edges.end(); i++) {
        // if they are not in the same set, we combine them
        if (ur.findOP(i->x) != ur.findOP(i->y)) {
            ur.combine(i->x, i->y);
            sum += i->weight;
        }
    }
    return sum;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    Graph g(n);
    int x, y, weight, start;
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &weight);
        g.insertEdge(x, y, weight);
    }
    scanf("%d", &start);
    printf("%d\n", kruskal(g, start));
    return 0;
}
