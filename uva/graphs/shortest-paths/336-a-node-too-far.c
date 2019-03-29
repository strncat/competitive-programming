#include <stdio.h>
#include <stdlib.h>

/* 336 - A Node Too Far
 Sample Input
 16
 10 15   15 20   20 25   10 30   30 47   47 50   25 45   45 65
 15 35   35 55   20 40   50 55   35 40   55 60   40 60   60 65
 35  2   35  3    0  0
 
 14
 1 2   2 7   1 3   3 4   3 5   5 10   5 11
 4 6   7 6   7 8   7 9   8 9   8  6   6 11
 1 1   1 2   3 2   3 3   0 0
 
 0
 Sample Output
 Case 1: 5 nodes not reachable from node 35 with TTL = 2.
 Case 2: 1 nodes not reachable from node 35 with TTL = 3.
 Case 3: 8 nodes not reachable from node 1 with TTL = 1.
 Case 4: 5 nodes not reachable from node 1 with TTL = 2.
 Case 5: 3 nodes not reachable from node 3 with TTL = 2.
 Case 6: 1 nodes not reachable from node 3 with TTL = 3.
*/

int map[30];

/* --------------------- QUEUE --------------------- */

#define QUEUE_SIZE 100

typedef struct {
    int count;
    int first;
    int last;
    int q[QUEUE_SIZE];
} queue;

void init_queue(queue *q) {
    q->first = 0;
    q->last = -1;
    q->count = 0;

}

void enqueue(queue *q, int key) {
    
    if (q->count >= QUEUE_SIZE)
        return; /* FULL */
    
    q->last = (q->last + 1) % QUEUE_SIZE;
    q->q[q->last] = key;
    q->count++;
}

int dequeue(queue *q) {
    
    int x;
    
    if (q->count <= 0)
        return -1; /* EMPTY */
    
    x = q->q[q->first];
    q->first = (q->first + 1) % QUEUE_SIZE;
    q->count--;
    
    return x;
}

int empty_queue(queue *q) {
    if (q->count)
        return 0;
    return 1;
}

/* --------------------- BFS --------------------- */

int bfs(int g[30][30], int k, int start, int depth) {
    
    int i, u, discovered[30], level[30], total_nodes_seen = 0;
    queue *q = malloc(sizeof(queue));
    
    for (i = 0; i < k; i++)
        discovered[i] = 0;
    
    for (i = 0; i < k; i++)
        level[i] = 0;
    
    init_queue(q);
    discovered[start] = 1;
    enqueue(q, start);
    
    while(!empty_queue(q)) {
        
        u = dequeue(q);
        total_nodes_seen++;
        
        for (i = 0; i < k; i++) {
            if (g[u][i] == 1 && discovered[i] == 0) {
                discovered[i] = 1;
                level[i] = level[u] + 1;
                
                if (level[i] <= depth)
                    enqueue(q, i);
            }
        }
    }
    return total_nodes_seen;
}

/* --------------------- MAP --------------------- */

int find_node_index(int *map, int n, int node_id) {
    
    int i;
    
    for (i = 0; i < n; i++)
        if (map[i] == node_id)
            return i;
    return -1;
}


int main() {

    int g[30][30], nedges, i, k, x, y, x_index, y_index, ttl, not_reachable, counter=1;
    
    /* only 30 nodes!! a matrix would be good enough */
    
    while (scanf("%d", &nedges) == 1 && nedges) {
        
        /* Reset */
        for (i = 0; i < 30; i++)
            for (k = 0; k < 30; k++)
                g[i][k] = 0;
        k = 0;
        
        for (i = 0; i < nedges; i++) {
            
            scanf("%d %d", &x, &y);
            
            x_index = find_node_index(map, k, x);
            
            if (x_index == -1) {
                x_index = k;
                map[k++] = x;
            }
            y_index = find_node_index(map, k, y);
            
            if (y_index == -1) {
                y_index = k;
                map[k++] = y;
            }
            
            g[x_index][y_index] = 1;
            g[y_index][x_index] = 1;
        }

        while (scanf("%d %d", &x, &ttl) == 2) {
            
            if (x == 0 && ttl == 0)
                break;
            
            x_index = find_node_index(map, k, x);
            
            not_reachable = k - bfs(g, k, x_index, ttl);
            
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", counter++, not_reachable, map[x_index], ttl);
        }
    }
    return 0;
}