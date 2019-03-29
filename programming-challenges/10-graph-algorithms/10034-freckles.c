#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

/* 10034 - Freckles
 Sample Input
 10
 
 2
 1.4 0.4
 1.0 0.3
 
 1
 3.4 5.0
 
 10
 4.2 1.6
 0.3 4.6
 6.2 0.0
 8.9 6.8
 3.9 6.7
 6.0 3.3
 9.7 7.4
 1.5 0.7
 6.5 8.9
 2.1 3.0
 
 1
 6.6 7.3
 
 9
 8.0 3.2
 0.9 9.7
 6.8 7.6
 8.9 2.1
 9.6 6.0
 8.6 6.2
 6.4 9.1
 5.0 8.8
 3.1 1.8
 
 9
 4.0 7.7
 4.4 1.7
 8.3 2.0
 1.8 8.2
 2.8 7.0
 2.4 2.2
 4.4 0.1
 7.9 2.4
 7.3 6.2
 
 2
 0.6 4.0
 9.1 8.5
 
 6
 8.0 3.4
 7.7 5.4
 7.7 4.6
 9.9 0.3
 8.7 6.9
 3.4 1.6
 
 1 
 6.7 7.5 
 
 4 
 9.1 0.8 
 8.0 9.0 
 9.0 9.1 
 7.5 5.1
 Sample Output
 0.41
 
 0.00
 
 23.94
 
 0.00
 
 20.06
 
 18.22
 
 9.62
 
 12.42
 
 0.00
 
 9.52
 */

/*--------------------------------- PQ --------------------------------------*/

#define PQ_SIZE 200

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
    double temp;
    
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
    double temp;
    
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

void pq_insert(priority_queue *p, int x, double i) { /* O(log n) */
    
    (p->n)++;
    p->q[p->n].cost = i;
    p->q[p->n].x = x;
    bubble_up(p, p->n);
}

/* ------------------------------- Graph ------------------------------- */

#define MAXV 150

typedef struct edgenode {
    int y;
    double weight;
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

void insert_edge(graph *g, int x, int y, double weight) {
    
    edgenode *p = malloc(sizeof(edgenode));
    
    p->weight = weight;
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
            printf(" %d (w = %lf)", p->y, p->weight);
            p = p->next;
        }
        printf("\n");
    }
}

/* ------------------------------- Prim ---------------------------------- */
double distance[MAXV + 1];
bool visited[MAXV+1];

void prim(graph *g, int start, priority_queue *q) {
    
    int i, v, w;
    double weight;
    edgenode *p;
  
    pq_insert(q, start, 0);
    
    for (i = 1; i <= g->nvertices; i++) {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    
    distance[start] = 0;
    v = start;
    pq_insert(q, start, 0);
    
    while (q->n) {
        
        extract_min(q); /* min and x_min set */
        v = x_min;
        visited[v] = true;
        
        p = g->edges[v];
        
        while (p != NULL) {
            w = p->y;
            weight = p->weight;
            if ((distance[w] > weight) && (visited[w] == false)) {
                distance[w] = weight;
                if (!visited[w])
                    pq_insert(q, w, distance[w]);
            }
            p = p->next;
        }
    }
}

/* ------------------------------- Main ------------------------------- */

int main() {
    
    int i, j, test_cases;
    double x[200], y[200], d, sum, min_sum;
    graph *g = malloc(sizeof(graph));
    priority_queue *pq = malloc(sizeof(priority_queue));
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        /* read graph */
        initialize_graph(g);

        scanf("%d", &(g->nvertices));
        
        for (i = 1; i <= g->nvertices; i++)
            scanf("%lf %lf", &x[i], &y[i]);
        
        /* Insert edges */
        for (i = 1; i <= g->nvertices; i++) {
            for (j = i + 1; j <= g->nvertices; j++) {
                
                /* calculate the distance from vertex i to j */
                d = sqrt ((y[i] - y[j]) * (y[i] - y[j]) + (x[i] - x[j]) * (x[i] - x[j]));
                
                insert_edge(g, i, j, d);
                insert_edge(g, j, i, d);
            }
        }
        /* Minimum Spanning Tree using Prim */
        
        /* got so many WA when I constantly chose 1 as the start node although it shouldn't matter ??????? 
         Needs revision here although already accepted :((( */
        
        min_sum = INT_MAX;
        for (i = 1; i <= g->nvertices; i++) {
        
            prim(g, i, pq);
            
            sum = 0;
            for (j = 1; j <= g->nvertices; j++)
                sum += distance[j];
            
            if (sum < min_sum)
                min_sum = sum;
        }
    
    
        printf("%.2lf\n", min_sum);
        if(test_cases)
            printf("\n");
    }
    return 0;
}