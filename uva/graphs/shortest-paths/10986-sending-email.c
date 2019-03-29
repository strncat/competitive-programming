#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/* 10986 - Sending email
 Sample Input
 3
 2 1 0 1
 0 1 100
 3 3 2 0
 0 1 100
 0 2 200
 1 2 50
 2 0 0 1
 Sample Output
 Case #1: 100
 Case #2: 150
 Case #3: unreachable
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
} graph;

void initialize_graph(graph *g) {
    
    int i;
    g->nvertices = 0;
    
    for (i = 0; i < MAXV; i++)
        g->edges[i] = NULL;
}

void insert_edge(graph *g, int x, int y, int weight) {
    
    edgenode *p = malloc(sizeof(edgenode));
    
    p->weight = weight;
    p->y = y;
    p->next = g->edges[x];
    
    g->edges[x] = p;
}

/* ------------------------------- Djkstra ------------------------------- */

int visited[MAXV];
long int distance[MAXV];

void dijkstra(graph *g, int start, int end, priority_queue *q) {
    
    int i, v, w, weight;
    edgenode *p;
    
    for (i = 0; i < g->nvertices; i++) {
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
    
    int i, test_cases, start, end, edges, x, y, weight, counter = 0;
    graph *g = malloc(sizeof(graph));
    priority_queue *q = malloc(sizeof(priority_queue));
    
    scanf("%d", &test_cases);
    
    while(test_cases--) {
        
        initialize_graph(g);
        
        pq_init(q);
        
        scanf("%d %d %d %d", &(g->nvertices), &edges, &start, &end);
        
        for (i = 0; i < edges; i++) {
            scanf("%d %d %d", &x, &y, &weight);
            insert_edge(g, x, y, weight);
            insert_edge(g, y, x, weight);
        }
        
        dijkstra(g, start, end, q);
        
        if (distance[end] != INT_MAX)
            printf("Case #%d: %ld\n", ++counter, distance[end]);
        else
            printf("Case #%d: unreachable\n", ++counter);
    }
    return 0;
}