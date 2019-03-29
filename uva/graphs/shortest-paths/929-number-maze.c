#include <stdio.h>
#include <limits.h>
#include <stdlib.h>

/*  929 - Number Maze
 Sample Input
 5
 4
 5
 0 3 1 2 9
 7 3 4 9 9
 1 7 5 5 3
 2 3 4 2 5
 1
 6
 0 1 2 3 4 5
 8
 17
 1 4 2 3 2 2 1 6 8 5 7 6 1 8 9 2 7
 9 5 4 3 1 2 3 3 4 1 1 3 8 7 4 2 7
 7 9 3 1 9 8 6 5 0 2 8 6 0 2 4 8 6
 5 0 9 0 0 6 1 3 8 9 3 4 4 6 0 6 6
 1 8 4 9 6 3 7 8 8 2 9 1 3 5 9 8 4
 0 7 6 3 6 1 5 4 2 0 9 7 3 7 2 6 0
 1 6 5 7 5 4 1 2 0 0 1 4 6 0 7 1 7
 7 7 7 3 3 5 9 9 8 1 8 2 6 6 0 3 8
 12
 17
 4 0 6 1 8 9 8 4 1 4 3 9 8 8 0 8 7
 7 8 3 8 3 7 1 0 7 3 4 9 6 5 1 0 9
 9 6 8 3 4 8 4 9 9 2 5 5 3 3 3 7 4
 3 8 0 8 8 0 6 8 1 9 8 9 7 2 2 8 2
 8 9 0 7 8 1 5 8 6 1 2 4 2 5 8 6 2
 6 5 3 9 2 4 6 1 8 2 1 1 9 7 6 2 9
 5 2 0 0 3 9 1 8 1 9 5 3 2 5 2 5 8
 6 7 7 2 2 9 4 1 9 6 9 8 2 5 5 4 9
 1 2 5 0 8 3 9 3 9 6 7 9 9 7 6 9 3
 5 7 6 6 5 8 2 5 4 4 1 6 1 6 3 3 5
 5 3 2 8 2 5 3 6 1 8 6 2 1 4 6 2 9
 1 5 0 3 6 4 9 2 9 3 4 4 0 5 9 6 3
 14
 16
 2 8 0 7 2 2 5 9 1 0 8 5 0 7 9 0
 5 3 4 1 0 4 8 5 9 2 5 4 1 3 9 5
 8 2 7 9 6 1 7 7 1 9 0 3 4 1 7 5
 3 3 2 4 1 2 9 0 8 7 4 5 6 8 0 7
 7 4 3 1 3 6 3 0 1 9 0 4 2 9 3 1
 4 8 2 0 5 5 9 3 2 8 7 4 8 1 4 3
 5 5 2 6 8 9 2 9 5 9 4 5 0 5 8 8
 0 1 3 2 2 2 7 0 3 1 3 3 7 0 9 5
 5 8 3 7 8 3 7 9 3 9 1 8 2 8 0 1
 8 4 8 6 0 9 3 0 0 8 7 6 3 5 6 5
 8 3 9 4 8 3 9 7 6 4 5 8 6 1 5 5
 1 9 6 4 5 4 2 5 3 2 6 8 2 6 6 3
 9 4 5 6 2 5 3 5 6 6 1 4 4 6 2 6
 8 2 5 5 1 0 1 5 1 7 6 0 0 2 4 3
 Sample Output
 24
 15
 59
 88
 76
*/

#define MAX 1000
#define PQ_SIZE 3000

/*--------------------------------- PQ --------------------------------------*/

int min;
int x_min;
int y_min;

typedef struct {
    int x;
    int y;
    int cost;
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
    
    int parent_index = pq_parent(child_index);
    int temp;
    
    if (parent_index == -1) /* root! */
        return;
    
    else if (p->q[parent_index].cost > p->q[child_index].cost) { /* swap */
        
        temp = p->q[child_index].cost;
        p->q[child_index].cost = p->q[parent_index].cost;
        p->q[parent_index].cost = temp;
        
        temp = p->q[child_index].x;
        p->q[child_index].x = p->q[parent_index].x;
        p->q[parent_index].x = temp;
        
        temp = p->q[child_index].y;
        p->q[child_index].y = p->q[parent_index].y;
        p->q[parent_index].y = temp;
        
        bubble_up(p, parent_index);
    }
    
}

void bubble_down(priority_queue *p, int parent_index) {
    
    int child_index, i, min_index, temp;
    
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
        
        temp = p->q[min_index].x;
        p->q[min_index].x = p->q[parent_index].x;
        p->q[parent_index].x = temp;
        
        temp = p->q[min_index].y;
        p->q[min_index].y = p->q[parent_index].y;
        p->q[parent_index].y = temp;
        
        bubble_down(p, min_index);
    }
    
}

void extract_min(priority_queue *p) {
    
    min = p->q[1].cost;
    x_min = p->q[1].x;
    y_min = p->q[1].y;
    
    p->q[1].cost = p->q[p->n].cost;
    p->q[1].x = p->q[p->n].x;
    p->q[1].y = p->q[p->n].y;

    (p->n)--;
    
    bubble_down(p, 1);
}

void pq_insert(priority_queue *p, int i, int x, int y) { /* O(log n) */
    
    (p->n)++;
    p->q[p->n].cost = i;
    p->q[p->n].x = x;
    p->q[p->n].y = y;
    bubble_up(p, p->n);
}

/*--------------------------------- DIJKSTRA --------------------------------------*/

int distance[MAX][MAX];
int cost[MAX][MAX];
int visited[MAX][MAX];

void dijkstra(int N, int M, priority_queue *q) {
    
    int x, y, i, dx, dy, c, direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    x = 0;
    y = 0;
    distance[x][y] = cost[x][y];
    pq_insert(q, cost[x][y], x, y);
    
    while (q->n) {
        
        extract_min(q);
        /* min is set using a global */
        x = x_min;
        y = y_min;
        visited[x][y] = 1;
        
        for(i = 0; i < 4; i++) {
            
            dx = x + direction[i][0];
            dy = y + direction[i][1];
            
            if (dx >= 0 && dx < N && dy >= 0 && dy < M && !visited[dx][dy]) {
                
                c = cost[dx][dy];
                
                if (distance[x][y] + c < distance[dx][dy]) {
                    
                    distance[dx][dy] = distance[x][y] + c;
                    
                    pq_insert(q, distance[dx][dy], dx, dy);
                    
                    /*visited[dx][dy] = 1;*/
                }
            }
        }
    }
}

int main() {
    
    int test_cases, i, j, N, M;
    
    priority_queue *q = malloc(sizeof(priority_queue));
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d\n%d", &N, &M);
        
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) {
                scanf("%d", &cost[i][j]);
                distance[i][j] = INT_MAX;
                visited[i][j] = 0;
            }
        
        pq_init(q);
        
        dijkstra(N, M, q);
        
        printf("%d\n", distance[N-1][M-1]);
    }
    return 0;
}