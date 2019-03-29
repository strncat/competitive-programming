#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

/* Reference: 11631 - Dark roads
 Sample Input
 7 11
 0 1 7
 0 3 5
 1 2 8
 1 3 9
 1 4 7
 2 4 5
 3 4 15
 3 5 6
 4 5 8
 4 6 9
 5 6 11
 0 0
 Sample Output
 51
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
    
    for (i = 0; i < MAXV; i++) {
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

/* ------------------------------- PRIM ------------------------------- */

int distance[MAXV+1];
int parent[MAXV+1];

void prim(graph *g, int start) {
        int i;    edgenode *p;    bool intree[MAXV+1];    int v;    int w;    int weight;    int dist;    for (i = 0; i < g->nvertices; i++) {        intree[i] = false;
        distance[i] = INT_MAX;        parent[i] = -1;
    }
    
    distance[start] = 0;    v = start;
        while (intree[v] == false) {        intree[v] = true;        p = g->edges[v];        while (p != NULL) {            w = p->y;            weight = p->weight;            if ((distance[w] > weight) && (intree[w] == false)) {
                distance[w] = weight;                parent[w] = v;            }        p = p->next;        }
        
        v = 1;        dist = INT_MAX;        for (i = 0; i < g->nvertices; i++)            if ((intree[i] == false) && (dist > distance[i])) {                dist = distance[i];                v = i;
            }
    }}

/* ------------------------------- Main ------------------------------- */

int main() {
    
    int  i, dist, m, n, x, y, weight, total;
    graph *g = malloc(sizeof(graph));
    
    while (scanf("%d %d", &n, &m) == 2) {
        
        if (!m && !n)
            break;
    
        initialize_graph(g, false);
        
        g->nvertices = n;
        
        total = 0;
        for (i = 0; i < m; i++) {
            scanf("%d %d %d", &x, &y, &weight);
            insert_edge(g, x, y, weight, false);
            total += weight;
        }
        
        prim(g, 1);
            
        dist = 0;
        for (i = 0; i < g->nvertices; i++)
            dist += distance[i];
            
        printf("%d\n", total - dist);
    }
    return 0;
}