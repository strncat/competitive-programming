#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

/* 1112 - Mice and Maze
 
 4 # number of cells (nodes)
 2 # exit cell (end node)
 1 # Time
 8 # number of edges (directed)

 Sample Input
 1
 
 4
 2
 1
 8
 1 2 1
 1 3 1
 2 1 1
 2 4 1
 3 1 1
 3 4 1
 4 2 1
 4 3 1
 Sample Output
 3
 */

/*--------------------------------- PQ --------------------------------------*/
#define PQ_SIZE 30000

long int min;
int x_min;

typedef struct {
    int x;
    long int cost;
} record;

typedef struct {
    record q[PQ_SIZE + 1];
    int n;             /* number of queue elements */
} priority_queue;

void pq_init(priority_queue *pq) {
    pq->n = 0;
}

int left_child(int parent_index) {
    return (2 * parent_index);
}

int right_child(int parent_index) {
    return (2 * parent_index) + 1;
}

int pq_parent(int child_index) {
    
    if (child_index == 1) /* root */
        return -1;
    
    return ((int) child_index/2); /* floor is implicit */
}

void bubble_up(priority_queue *p, int child_index) {
    
    int temp2, parent_index = pq_parent(child_index);
    long int temp;
    
    if (parent_index == -1) /* root! */
        return;
    
    else if (p->q[parent_index].cost > p->q[child_index].cost) { /* swap */
        
        temp = p->q[child_index].cost;
        p->q[child_index].cost = p->q[parent_index].cost;
        p->q[parent_index].cost = temp;
        
        temp2 = p->q[child_index].x;
        p->q[child_index].x = p->q[parent_index].x;
        p->q[parent_index].x = temp2;
        
        bubble_up(p, parent_index);
    }
}

void bubble_down(priority_queue *p, int parent_index) {
    
    int child_index, i, min_index, temp2;
    long int temp;
    
    child_index = left_child(parent_index);
    
    min_index = parent_index; /* so far */
    
    for (i = 0; i <= 1; i++) /* test whether the left child or the right child is smaller than the parent */
        if ((child_index + i) <= p->n) /* child exist */
            if (p->q[min_index].cost > p->q[child_index + i].cost) /* parent is less than child */
                min_index = child_index + i;
    
    
    if (min_index != parent_index) {
        
        temp = p->q[min_index].cost;
        p->q[min_index].cost = p->q[parent_index].cost;
        p->q[parent_index].cost = temp;
        
        temp2 = p->q[min_index].x;
        p->q[min_index].x = p->q[parent_index].x;
        p->q[parent_index].x = temp2;
        
        bubble_down(p, min_index);
    }
}

void extract_min(priority_queue *p) {
    
    min = p->q[1].cost;
    x_min = p->q[1].x;
    
    p->q[1].cost = p->q[p->n].cost;
    p->q[1].x = p->q[p->n].x;
    
    (p->n)--;
    
    bubble_down(p, 1);
}

void pq_insert(priority_queue *p, int x, long int i) { /* O(log n) */
    
    (p->n)++;
    p->q[p->n].cost = i;
    p->q[p->n].x = x;
    bubble_up(p, p->n);
}


/* ------------------------------- Graph ------------------------------- */

#define MAXV 20000

typedef struct edgenode {
    int y;
    int weight;
    struct edgenode *next;
} edgenode;

typedef struct graph {
    edgenode *edges[MAXV+1];
    int nvertices;
    bool directed; /* Is the graph directed? */
} graph;

void initialize_graph(graph *g, bool directed) {
    
    int i;
    g->nvertices = 0;
    g->directed = directed;
    
    for (i = 1; i <= MAXV; i++)
        g->edges[i] = NULL;
}

void insert_edge(graph *g, int x, int y, int weight, bool directed) {
    
    edgenode *p;
    
    p = malloc(sizeof(edgenode));
    
    p->weight = weight;
    p->y = y;
    p->next = g->edges[x];
    
    g->edges[x] = p;
    
    if (directed == false)
        insert_edge(g, y, x, weight, true);
}

void print_graph(graph *g) {
    
    int i;
    struct edgenode *p;
    
    for (i = 1; i <= g->nvertices; i++) {
        printf("%d: ", i);
        p = g->edges[i];
        while (p != NULL) {
            printf(" %d (%d) ", p->y, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

/* ------------------------------- Djkstra ------------------------------- */

int visited[MAXV];
int distance[MAXV];

void dijkstra(graph *g, int start, int end, priority_queue *q) {
    
    int i, v, w, weight;
    edgenode *p;
    
    for (i = 1; i <= g->nvertices; i++) {
        visited[i] = 0;
        distance[i] = INT_MAX;
    }
    
    distance[start] = 0;
    v = start;
    pq_insert(q, start, 0);
    
    while (q->n) {
        
        extract_min(q); /* min and x_min set */
        v = x_min;
        visited[v] = 1;
        p = g->edges[v];
        
        if (v == end)
            break;
        
        while (p != NULL) {
            
            w = p->y;
            weight = p->weight;
            
            if (distance[w] > distance[v] + weight) {
                distance[w] = distance[v] + weight;
                if (!visited[w])
                    pq_insert(q, w, distance[w]);
            }
            p = p->next;
        }
    }
}

/* ------------------------------- Main ------------------------------- */

int main() {
    
    int i, test_cases, end, edges, x, y, weight, time, total;
    graph *g = malloc(sizeof(graph));
    priority_queue *q = malloc(sizeof(priority_queue));
    
    scanf("%d", &test_cases);
    
    while(test_cases--) {
        
        initialize_graph(g, true);
        
        scanf("%d", &(g->nvertices));
        scanf("%d", &end);
        scanf("%d", &time);
        scanf("%d", &edges);
        
        for (i = 0; i < edges; i++) {
            scanf("%d %d %d", &x, &y, &weight);
            insert_edge(g, x, y, weight, true);
        }
        
        total = 0;
        for (i = 1; i <= g->nvertices; i++) {
            pq_init(q);
            dijkstra(g, i, end, q);
            
            if (distance[end] <= time)
                total++;
        }
        printf("%d\n", total);
        
        if (test_cases)
            printf("\n");
    }
    return 0;
}