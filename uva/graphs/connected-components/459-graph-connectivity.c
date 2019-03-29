#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/* 459 - Graph Connectivity
 Input formatting is hard :(
 Sample Input
 1
 
 E
 AB
 CE
 DB
 EC
 
 A
 AB
 BC
 
 Sample Output
 
 2 */

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
    
    for (i=1; i<=MAXV; i++) {
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

/* ------------------------------- BFS ------------------------------- */

bool discovered[MAXV+1];

void bfs(graph *g, int start) {
    
    int v, y;
    edgenode *p;
    queue q;
    
    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = true;
    
    while(empty_queue(&q) == false) {
        
        v = dequeue(&q);
        p = g->edges[v];
        
        while (p != NULL) {
            y = p->y;
            if (discovered[y] == false) {
                enqueue(&q, y);
                discovered[y] = true;
            }
            p = p->next;
        }
    }
}

/* ------------------------------- Connected Components ------------------------------- */

int connected_components(graph *g) {
    
    int c, i;
    
    for (i=1; i<=g->nvertices; i++)
        discovered[i] = false;
    
    c=0;
    for (i=1; i<=g->nvertices; i++)
        if (discovered[i] == false) {
            c++;
            bfs(g, i);
        }
    return c;
}

/* ------------------------------- Main ------------------------------- */

int main() {
    
    graph *g = malloc(sizeof(graph));
    int largest, test_cases;
    char x, y, line[10];
    
    scanf("%d", &test_cases);
    getchar();
    getchar();
    
    while (test_cases--) {
        
        initialize_graph(g);
        
        while (gets(line) && line[0]) {
            
            if(!line[1]) {
                largest = line[0] - 'A' + 1;
                g->nvertices = largest;
            }
            else {
                x = line[0] - 'A' + 1;
                y = line[1] - 'A' + 1;
                
                insert_edge(g, x, y);
                insert_edge(g, y, x);
            }
        }
        printf("%d\n", connected_components(g));
        
        if (test_cases)
            printf("\n");
    }
    return 0;
}