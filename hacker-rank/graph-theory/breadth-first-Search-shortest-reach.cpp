//
//  Breadth First Search: Shortest Reach
//
//  Created by Fatima B on 12/28/15.
//  Copyright © 2015 Fatima B. All rights reserved.
//

#include <iostream>
#include <queue>

#define N 2000

typedef struct edge {
    int y;
    edge *next;
} edge;

typedef struct graph {
    int nvertices;
    edge *edges[N]; // pointers to edges
} graph;

void init_graph(graph *g, int n) {
    g->nvertices = n;
    for (int i = 1; i <= n; i++) {
        g->edges[i] = NULL;
    }
}

void insert(graph *g, int x, int y) {
    edge *e = new edge();
    e->y = y;
    e->next = g->edges[x];
    g->edges[x] = e;
}

void bfs(graph *g, int start) {
    int distance[N];
    int visited[N];
    for (int i = 1; i <= g->nvertices; i++) {
        distance[i] = 0;
        visited[i] = 0;
    }
    std::queue<int> q;
    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        edge *e = g->edges[node];
        while (e != NULL) {
            if (!visited[e->y]) {
                visited[e->y] = 1;
                distance[e->y] = distance[node] + 6;
                q.push(e->y);
            }
            e = e->next;
        }
    }
    for (int i = 1; i <= g->nvertices; i++) {
        if (start != i) {
            if (distance[i] == 0) {
                printf("-1 ");
            } else {
                printf("%d ", distance[i]);
            }
        }
    }
    printf("\n");
}

int main() {
    int n, m, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        graph g;
        int x, y, start;
        init_graph(&g, n);
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            insert(&g, x, y);
            insert(&g, y, x);
        }
        scanf("%d", &start);
        bfs(&g, start);
    }
    return 0;
}
