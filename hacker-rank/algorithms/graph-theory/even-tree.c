#include <stdio.h>
#include <stdlib.h>

/* I simply used the connected components algorithm to go over all the nodes
   inside the bfs, I try to cut an edge and count the nodes (with another bfs!) 
    on both sides to see if they stay even
*/

/* Even Tree
Sample Input
10 9
2 1
3 1
4 3
5 2
6 1
7 2
8 6
9 8
10 8
Sample Output
2
*/

#define N 104

int edges[N][N];
int degree[N];
int cut_edges = 0;

typedef struct {
    int q[N+1];
    int first;
    int last;
    int count;
} queue;

void init_queue(queue *q) {
    q->first = 0;
    q->last = N-1;
    q->count = 0;
}

void enqueue(queue *q, int x) {
    
    q->last = (q->last+1) % N;
    q->q[q->last] = x;
    q->count = q->count + 1;
}

int dequeue(queue *q) {
    
    int x=0;
    x = q->q[q->first];
    q->first = (q->first+1) % N;
    q->count = q->count - 1;
    return x;
}

int headq(queue *q) {
    
	return q->q[q->first];
}

int empty_queue(queue *q) {
    
    if (q->count <= 0)
        return 1;
    else return 0;
}

int simple_bfs(int nvertices, int start) {
    
    int v, p, visited[N], total = 0;
    queue q;
    
    for (int i = 1; i <= nvertices; i++)
        visited[i] = 0;
    
    init_queue(&q);
    enqueue(&q, start);
    visited[start] = 1;
    
    while(!empty_queue(&q)) {
        
        v = dequeue(&q);
        total += 1;
        
        for(p = 1; p <= nvertices; p++) {
            if (edges[v][p] == 1 && visited[p] == 0) {
                enqueue(&q, p);
                visited[p] = 1;
            }
        }
    }
    return total;
}

int discovered[N];

void connected_components_core(int nvertices, int start) {
    
    int v, p;
    queue q;
    
    init_queue(&q);
    enqueue(&q, start);
    discovered[start] = 1;
    
    while(!empty_queue(&q)) {
        
        v = dequeue(&q);
        
        for(p = 1; p <= nvertices; p++) {
            if (edges[v][p] == 1 && discovered[p] == 0) {
                
                edges[v][p] = -1;
                edges[p][v] = -1;
                
                int v_total = simple_bfs(nvertices, v);
                int p_total = simple_bfs(nvertices, p);
                
                if (v_total % 2|| p_total % 2) {
                    edges[v][p] = 1;
                    edges[p][v] = 1;
                }
                else {
                    cut_edges++;
                }
        
                enqueue(&q, p);
                discovered[p] = 1;
            }
        }
    }
}

void connected_components(int nvertices) {
    
    for (int i = 1; i <= nvertices; i++)
        discovered[i] = 0;
    
    for (int i = 1; i <= nvertices; i++) {
        if (discovered[i] == 0) {
            connected_components_core(nvertices, i);
        }
    }
}

/* ------------------------------- Main ------------------------------- */

int main() {
    
    int i, j, nvertices, nedges, a, b;
   
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++)
            edges[i][j] = 0;
    
    scanf("%d %d", &nvertices, &nedges);
    
    for (i = 0; i < nedges; i++) {
        scanf("%d %d", &a, &b);
        edges[a][b] = 1;
        edges[b][a] = 1;
    }
    
    connected_components(nvertices);
    printf("%d\n", cut_edges);

    return 0;
}


