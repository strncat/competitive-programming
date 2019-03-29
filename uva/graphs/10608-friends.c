#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 10608 - Friends */
int components[30001];

/* Graph Structure */

#define MAXV 500000 /* maximum number of vertices */

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
    
    for (i=1; i<=MAXV; i++) {
        g->degree[i] = 0;
        g->edges[i] = NULL;
    }
}

void insert_edge(graph *g, int x, int y, bool directed) {
    
     edgenode *p;
    
    p = malloc(sizeof(edgenode));
    
    p->weight = 0; /* NULL */
    p->y = y;
    p->next = g->edges[x];
    
    g->edges[x] = p;
    g->degree[x]++;
    
    if (directed == false)
        insert_edge(g, y, x, true);
    else
        g->nedges++;
    
}

void read_graph(graph *g, bool directed) {
    
    int i, m, x, y;
    
    initialize_graph(g, directed);
    
    scanf("%d %d", &(g->nvertices), &m);
    
    for (i=1; i<=m; i++) {
        scanf("%d %d", &x, &y);
        insert_edge(g, x, y, directed);
    }
}

void print_graph(graph *g) {
    
    int i;
    struct edgenode *p;
    
    for (i=1; i<=g->nvertices; i++) {
        printf("%d: ", i);
        p = g->edges[i];
        while (p != NULL) {
            printf(" %d", p->y);
            p = p->next;
        }
        printf("\n");
    }
}

/* Queue */

#define QUEUESIZE 500000

typedef struct {
    int q[QUEUESIZE+1];	/* body of queue */
    int first;                      /* position of first element */
    int last;                       /* position of last element */
    int count;                      /* number of queue elements */
} queue;

void init_queue(queue *q)
{
    q->first = 0;
    q->last = QUEUESIZE-1;
    q->count = 0;
}

void enqueue(queue *q, int x)
{
    if (q->count >= QUEUESIZE)
		printf("Warning: queue overflow enqueue x=%d\n",x);
    else {
        q->last = (q->last+1) % QUEUESIZE;
        q->q[ q->last ] = x;
        q->count = q->count + 1;
    }
}

int dequeue(queue *q) {
    int x=0;
    
    if (q->count <= 0) printf("Warning: empty queue dequeue.\n");
    else {
        x = q->q[ q->first ];
        q->first = (q->first+1) % QUEUESIZE;
        q->count = q->count - 1;
    }
    
    return(x);
}

int headq(queue *q) {
	return( q->q[ q->first ] );
}

int empty_queue(queue *q) {
    if (q->count <= 0) return (true);
    else return (false);
}

void print_queue(queue *q) {
    int i;
    
    i=q->first;
    
    while (i != q->last) {
        printf("%d ",q->q[i]);
        i = (i+1) % QUEUESIZE;
    }
    
    printf("%2d ",q->q[i]);
    printf("\n");
}

/* Breadth-First-Search BFS */

bool processed[MAXV+1];
bool discovered[MAXV+1];
int parent[MAXV+1];

void initialize_search(graph *g) {
    
    int i;
    
    for (i=1; i<=g->nvertices; i++) {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
    }
}

void process_vertex_late(int v) {
    
}

void process_vertex_early(int v, int c) {
    
    components[c]++;
}

void process_edge(int x, int y) {
    
}

void bfs(graph *g, int start, int c) {
    
    int v, y;
    edgenode *p;
    queue q;
    
    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = true;
    
    while(empty_queue(&q) == false) {
        
        v = dequeue(&q);
        process_vertex_early(v, c);
        processed[v] = true;
        p = g->edges[v];
        
        while (p != NULL) {
            y = p->y;
            
            if (processed[y] == false || g->directed)
                process_edge(v, y);
            if (discovered[y] == false) {
                enqueue(&q, y);
                discovered[y] = true;
                parent[y] = v;
            }
            p = p->next;
        }
        process_vertex_late(v);
    }
     
}

/*  Connected Components Parts */

void connected_components(graph *g) {
    
    int c, i;
    
    initialize_search(g);
    
    c=0;
    for (i=1; i<g->nvertices; i++)
        if (discovered[i] == false) {
            c++;
            bfs(g, i, c);
        }
}

int main() {
    
    int i, max=0, test_cases=0;
    
    graph *g = (graph *)malloc(sizeof(*g));
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        max = 0;
        
        for (i=1; i<=30000; i++)
            components[i]=0;
        
        read_graph(g, false);
        connected_components(g);
        
        for (i=1; i<=30000; i++)
            if (max < components[i])
                max = components[i];
        
        printf("%d\n", max);
    }
    
    return 0;
}

