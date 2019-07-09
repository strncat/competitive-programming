//
// Hacker Rank
// Prim's (MST) : Special Subtree
//
//

#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>

#define PQ_SIZE 100000

struct min_heap {
    int nodes[PQ_SIZE+1];
    int values[PQ_SIZE+1];
    int n;
};

void init_heap(min_heap *q) {
    q->n = 0;
}

bool empty(min_heap *q) {
    return (q->n == 0);
}

int left_child(int parent) {
    return (2 * parent);
}

int right_child(int parent) {
    return (2 * parent) + 1;
}

int get_parent(int child) {
    if (child == 1) {
        return -1;
    }
    return child/2;
}

void swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void bubble_up(min_heap *q, int child) {
    int parent = get_parent(child);
    if (parent == -1) {
        return;
    } else if (q->values[parent] > q->values[child]) {
        swap(&q->values[child], &q->values[parent]);
        swap(&q->nodes[child], &q->nodes[parent]);
        bubble_up(q, parent);
    }
}

void bubble_down(min_heap *q, int parent) {
    int child = left_child(parent);
    int min = parent;

    for (int i = 0; i <= 1; i++) {
        if ((child + i) <= q->n) {
            if (q->values[min] > q->values[child + i]) {
                min = child + i;
            }
        }
    }
    if (min != parent) {
        swap(&q->values[min], &q->values[parent]);
        swap(&q->nodes[min], &q->nodes[parent]);
        bubble_down(q, min);
    }
}

int extract_min(min_heap *q) {
    //int minimum = q->values[1];
    int minimum_node = q->nodes[1];

    q->values[1] = q->values[q->n];
    q->nodes[1] = q->nodes[q->n];

    (q->n)--;
    bubble_down(q, 1);
    return minimum_node;
}

void insert(min_heap *q, int node, int value) {
    (q->n)++;
    q->values[q->n] = value;
    q->nodes[q->n] = node;
    bubble_up(q, q->n);
}

void decrease_key(min_heap *q, int node, int value) {
    for (int i = 1; i <= q->n; i++) {
        if (q->nodes[i] == node) {
            q->values[i] = value;
            bubble_up(q, i); // bubble it up!
        }
    }
}

#define N 5000

typedef struct edge {
    int y;
    int weight;
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

void insert(graph *g, int x, int y, int weight) {
    edge *e = new edge();
    e->y = y;
    e->weight = weight;
    e->next = g->edges[x];
    g->edges[x] = e;
}

int dijkstra(graph *g, int start) {
    // INIT DISTANCE ARRAY
    int distance[N];
    int visited[N];
    for (int i = 1; i <= g->nvertices; i++) {
        distance[i] = INT_MAX;
        visited[i] = 0;
    }

    // INIT MIN_HEAP AND INSERT START NODE
    min_heap h;
    init_heap(&h);
    distance[start] = 0;
    insert(&h, start, distance[start]);

    while (!empty(&h)) {
        int node = extract_min(&h);
        visited[node] = 1; // WE WON'T CHECK THIS NODE EVER AGAIN

        edge *e = g->edges[node];
        while (e != NULL) {
            if (!visited[e->y]) {
                if (distance[e->y] > e->weight) {
                    if (distance[e->y] == INT_MAX) { // FIRST TIME
                        distance[e->y] = e->weight;
                        insert(&h, e->y, distance[e->y]);
                    } else {
                        // KEY ALREADY EXIST, UPDATE ITS VALUE
                        distance[e->y] = e->weight;
                        decrease_key(&h, e->y, distance[e->y]);
                    }
                }
            }
            e = e->next;
        }
    }
    int sum = 0;
    for (int i = 1; i <= g->nvertices; i++) {
        sum += distance[i];
    }
    return sum;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    graph g;
    int x, y, weight, start;
    init_graph(&g, n);
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &weight);
        insert(&g, x, y, weight);
        insert(&g, y, x, weight);
    }
    scanf("%d", &start);
    printf("%d\n", dijkstra(&g, start));
    return 0;
}
