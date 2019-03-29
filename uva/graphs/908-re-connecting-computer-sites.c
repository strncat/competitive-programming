#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

/* 908 - Re-connecting Computer Sites
 Sample Input
 5
 1 2 5
 1 3 5
 1 4 5
 1 5 5
 1
 2 3 2
 6
 1 2 5
 1 3 5
 1 4 5
 1 5 5
 3 4 8
 4 5 8
 Sample Output
 20
 17
 */

/* ------------------------------- Graph ------------------------------- */

#define MAXV 1000001 /* maximum number of vertices */

typedef struct edgenode {
    int y; /* adjacency info */
    int weight; /* edge weight, if any */
    struct edgenode *next; /* next edge in list */
} edgenode;

typedef struct graph {
    edgenode *edges[MAXV+1];
    int degree[MAXV+1]; /* outdegree of each vertex */
    int nvertices; /* number of vertices in the graph */
    int nedges; /* number of edges in the graph */
    bool directed; /* Is the graph directed? */
} graph;

void initialize_graph(graph *g, bool directed) {
    
    int i;
    g->nvertices = 0;
    g->nedges = 0;
    g->directed = directed;
    
    for (i = 1; i <= MAXV; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}

void insert_edge(graph *g, int x, int y, int weight, bool directed) {
    
    edgenode *p;
    
    p = malloc(sizeof(edgenode));
    
    p->weight = weight;
    p->y = y;
    p->next = g->edges[x];
    
    g->edges[x] = p;
    g->degree[x]++;
    
    if (directed == false)
        insert_edge(g, y, x, weight, true);
    else
        g->nedges++;
    
}

void read_edges(graph *g, int total_edges, bool directed) {
    
    int i, x, y, weight;
    
    for (i = 1; i <= total_edges; i++) {
        scanf("%d %d %d", &x, &y, &weight);
        insert_edge(g, x, y, weight, directed);
    }
}

void print_graph(graph *g) {
    
    int i;
    struct edgenode *p;
    
    for (i = 1; i <= g->nvertices; i++) {
        printf("%d: ", i);
        p = g->edges[i];
        while (p != NULL) {
            printf("[%d %d]", p->y, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

/* ------------------------------- PRIM ------------------------------- */

int distance[MAXV+1];
int parent[MAXV+1];

void prim(graph *g, int start) {
        int i;    edgenode *p;    bool intree[MAXV+1];    int v;    int w;    int weight;    int dist;    for (i = 1; i <= g->nvertices; i++) {        intree[i] = false;
        distance[i] = INT_MAX;        parent[i] = -1;
    }
    
    distance[start] = 0;    v = start;
        while (intree[v] == false) {        intree[v] = true;        p = g->edges[v];        while (p != NULL) {            w = p->y;            weight = p->weight;            if ((distance[w] > weight) && (intree[w] == false)) {
                distance[w] = weight;                parent[w] = v;            }        p = p->next;        }
        
        v = 1;        dist = INT_MAX;        for (i = 1; i <= g->nvertices; i++)            if ((intree[i] == false) && (dist > distance[i])) {                dist = distance[i];                v = i;
            }
    }}

/* ------------------------------- Main ------------------------------- */

int main() {
    
    int counter = 0, n, i, dist, x, y, z;
    graph *g = malloc(sizeof(graph));
    
    while (scanf("%d\n", &n) == 1) {
        
        if (counter)
            printf("\n");
        counter++;
        
        /* read_edges(g, n - 1, false); *//* followed by N-1 lines */
        /* trash it? */
        dist = 0;
        for (i = 1; i <= n - 1 ; i++) {
            scanf("%d %d %d", &x, &y, &z);
            dist += z;
        }
        
        printf("%d\n", dist);
        
        /* initialize graph and scan new edges */
        
        initialize_graph(g, false);
        g->nvertices = n;
        scanf("%d\n", &n);
        read_edges(g, n, false);
        
        scanf("%d\n", &n); /* scan old edges */
        read_edges(g, n, false);
        
        prim(g, 1);
        
        dist = 0;
        for (i = 1; i <= g->nvertices; i++)
            dist += distance[i];
        
        printf("%d\n", dist);
    }
    return 0;
}