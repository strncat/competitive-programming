#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* 10004 - Bicoloring
 Sample Input
 3
 3
 0 1
 1 2
 2 0
 9
 8
 0 1
 0 2
 0 3
 0 4
 0 5
 0 6
 0 7
 0 8
 0
 Sample Output
 NOT BICOLORABLE.
 BICOLORABLE.
 */

/* ------------------------------- Graph ------------------------------- */

#define MAXV 1000 /* maximum number of vertices */

typedef struct edgenode {
    int y;
    struct edgenode *next;
} edgenode;

typedef struct graph {
    edgenode *edges[MAXV+1];
    int nvertices;
} graph;

void initialize_graph(graph *g) {
    
    int i;
    g->nvertices = 0;
    
    for (i=0; i < MAXV; i++)
        g->edges[i] = NULL;
}

void insert_edge(graph *g, int x, int y) {
    
    edgenode *p;
    
    p = malloc(sizeof(edgenode));
    
    p->y = y;
    p->next = g->edges[x];
    
    g->edges[x] = p;
}

void read_graph(graph *g, int n) {
    
    int i, m, x, y;
    
    initialize_graph(g);
    g->nvertices = n;
    
    scanf("%d", &m);
    
    for (i = 0; i < m; i++) {
        scanf("%d %d", &x, &y);
        insert_edge(g, x, y);
        insert_edge(g, y, x);
    }
}
/* ------------------------------- Queue ------------------------------- */

#define QUEUESIZE 1000

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

/* ------------------------------- BFS & Bipartite ------------------------------- */

#define UNCOLORED 0
#define WHITE 1
#define BLACK 2

bool processed[MAXV + 1];
bool discovered[MAXV + 1];
int color[MAXV + 1];

void initialize_search(graph *g) {
    
    int i;
    
    for (i = 0; i < g->nvertices; i++)
        processed[i] = discovered[i] = false;
}

int complement(int color) {
    
    if (color == WHITE) return(BLACK);    if (color == BLACK) return(WHITE);    return(UNCOLORED);
}

int process_edge(int x, int y) {
    
    if (color[x] == color[y])        return 0;
        color[y] = complement(color[x]);
    return 1;
    
}

int bfs(graph *g, int start) {
    
    int v, y;
    edgenode *p;
    queue q;
    
    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = true;
    
    while(empty_queue(&q) == false) {
        
        v = dequeue(&q);
        processed[v] = true;
        p = g->edges[v];
        
        while (p != NULL) {
            y = p->y;
            
            if (processed[y] == false) { /* not yet colored */
                if (process_edge(v, y) == 0)
                    return 0;
            }
            
            if (discovered[y] == false) {
                enqueue(&q, y);
                discovered[y] = true;
            }
            p = p->next;
        }
    }
    return 1;
}

int two_color(graph *g) {
    
    int i;    
    for (i = 0; i < g->nvertices; i++)        color[i] = UNCOLORED;    
    initialize_search(g);    
    for (i = 0; i < g->nvertices; i++) /* for every component */
        if (discovered[i] == false) {            color[i] = WHITE;            if (bfs(g, i) == 0) /* not colorable */
                return 0;        }
    return 1;
}

/* ------------------------------- Main ------------------------------- */

int main() {
    
    int n;
    graph *g = malloc(sizeof(graph));
    
    while (scanf("%d", &n) == 1 && n) {
        
        initialize_graph(g);
        read_graph(g, n);
        
        if (two_color(g) == 0)
            printf("NOT BICOLORABLE.\n");
        else
            printf("BICOLORABLE.\n");
    }
    
    return 0;
}