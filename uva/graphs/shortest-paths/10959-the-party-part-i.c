#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* 10959 - The Party, Part I
 BFS from DON GIOVANI TO ALL OTHER DANCERS
 Sample Input
 1
 5 6
 0 1
 0 2
 3 2
 2 4
 4 3
 1 2
 Sample Output
 1
 1
 2
 2
*/

/* ------------------------------- Graph ------------------------------- */

#define MAXV 1001 /* maximum number of vertices */

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
    
    for (i = 0; i < MAXV; i++) {
        g->edges[i] = NULL;
    }
}

void insert_edge(graph *g, int x, int y) {
    
    edgenode *p;
    
    p = malloc(sizeof(edgenode));
    
    p->y = y;
    p->next = g->edges[x];
    g->edges[x] = p;
}

void print_graph(graph *g) {
    
    int i;
    struct edgenode *p;
    
    for (i = 0; i < g->nvertices; i++) {
        printf("%d: ", i);
        p = g->edges[i];
        while (p != NULL) {
            printf(" %d", p->y);
            p = p->next;
        }
        printf("\n");
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

void init_queue(queue *q) {
    q->first = 0;
    q->last = QUEUESIZE-1;
    q->count = 0;
}

void enqueue(queue *q, int x) {
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

int empty_queue(queue *q) {
    if (q->count <= 0) return (true);
    else return (false);
}

/* ------------------------------- BFS ------------------------------- */

bool discovered[MAXV+1];
int distance[MAXV+1];

void bfs(graph *g, int start) {
    
    int v, y, i;
    edgenode *p;
    queue q;
    
    for (i = 0; i < g->nvertices; i++)
        discovered[i] = false;
    
    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = true;
    distance[start] = 0;
    
    while(empty_queue(&q) == false) {
        
        v = dequeue(&q);
        p = g->edges[v];
        
        while (p != NULL) {
            y = p->y;
            if (discovered[y] == false) {
                enqueue(&q, y);
                distance[y] = distance[v] + 1;
                discovered[y] = true;
            }
            p = p->next;
        }
    }
}
/* ------------------------------- Main ------------------------------- */

int main() {
    
    graph *g = malloc(sizeof(graph));
    int x, y, i, test_cases, edges;
    
    scanf("%d", &test_cases);
   
    while (test_cases--) {
        
        initialize_graph(g);
        
        scanf("%d %d", &(g->nvertices), &edges);
        
        for (i = 0; i < edges; i++) {
            scanf("%d %d", &x, &y);
            insert_edge(g, x, y);
            insert_edge(g, y, x);
        }
        
        /* If a person p is not Don Giovanni himself, and has danced with someone with Giovanni number n, 
         and has not danced with anyone with a Giovanni number smaller than n, then p has Giovanni number n+1 */
        /* Don Giovanni is represented by 0. */
        bfs(g, 0);
        
        for (i = 1; i < g->nvertices; i++) {
            printf("%d\n", distance[i]);
        }
        
        /* The outputs of two consecutive cases will be separated by a blank line. */
        if (test_cases)
            printf("\n");
    }
    return 0;
}