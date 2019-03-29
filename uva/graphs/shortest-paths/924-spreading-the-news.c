#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>

/* 924 - Spreading The News
Used BFS with an array to track the day they heard the news on
 Sample Input
 6
 2 1 2
 2 3 4
 3 0 4 5
 1 4
 0
 2 0 2
 3
 0
 4
 5
 Sample Output
 3 2
 0
 2 1
 */

/* ------------------------------- Graph ------------------------------- */

#define MAXV 3000 /* maximum number of vertices */

typedef struct edgenode {
    int y;
    struct edgenode *next;
} edgenode;

typedef struct graph {
    edgenode *edges[MAXV];
    int nvertices;
    int nedges;
} graph;

void initialize_graph(graph *g) {
    
    int i;
    g->nvertices = 0;
    g->nedges = 0;
    
    for (i = 0; i < MAXV; i++)
        g->edges[i] = NULL;
}

void insert_edge(graph *g, int x, int y) {
    
    edgenode *p;
    
    p = malloc(sizeof(edgenode));
    
    p->y = y;
    p->next = g->edges[x];
    
    g->edges[x] = p;
}

/* ------------------------------- Queue ------------------------------- */

#define QUEUESIZE 3000

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

/* ------------------------------- BFS ------------------------------- */

bool processed[MAXV];
bool discovered[MAXV];
int parent[MAXV];
int level[MAXV];
int day[MAXV];
int max_day;
int max;

void initialize_search(graph *g) {
    
    int i;
    
    max = 0;
    max_day = 0;
    
    for (i=0; i < g->nvertices; i++) {
        processed[i] = discovered[i] = false;
        parent[i] = -1;
        level[i] = 0;
        day[i] = 0;
    }
}

void bfs(graph *g, int start) {
    
    int v, y, i, j, d;
    edgenode *p;
    queue q;
    
    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = true;
    level[start] = 0; /* source hears the news */
    
    while(empty_queue(&q) == false) {
        
        v = dequeue(&q);
        processed[v] = true;
        p = g->edges[v];
        
        while (p != NULL) {
            y = p->y;
            
            if (discovered[y] == false) {
                enqueue(&q, y);
                discovered[y] = true;
                parent[y] = v;
                level[y] = level[v]+1; /* this when they heard the news */
                d = level[v]+1;
            }
            p = p->next;
        }
    }
    
    for (i = 1; i <= d; i++) /* sum up values */
        for (j = 0; j < g->nvertices; j++)
            if (level[j] == i)
                day[i]++;
    
    for (i = 1; i <= d; i++) /* find the maximum */
        if (day[i] > max) {
            max = day[i];
            max_day = i;
        }
}

/* ------------------------------- Main ------------------------------- */

int main() {
    
    int  i, n, friends, f, T, test;
    graph *g = malloc(sizeof(graph));
    
    scanf("%d", &n);
    
    initialize_graph(g);
    g->nvertices = n;
    
    for (i = 0; i < n; i++) {
        
        scanf("%d", &friends);
        
        while (friends--) {
            scanf("%d", &f);
            insert_edge(g, i, f);
        }
    }
    scanf("%d", &T);
    
    while (T--) {
        scanf("%d", &test);
        initialize_search(g);
        bfs(g, test);
        if (max == 0 && max_day == 0)
            printf("0\n");
        else
            printf("%d %d\n", max, max_day);
    }
    return 0;
}