//
//  main.cpp
//  uhunt
//  Ford–Fulkerson Edmonds-Karp
//  Based on the Algorithms Design Manual
//  Example Problem: https://uva.onlinejudge.org/external/8/820.pdf
//  2017/03/09
//
//

#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::pair;

/* For each edge (i,j) in G with capacity c(i,j) and flow f(i,j), R(G,f) may contain two edges:
    (i) an edge (i,j) with weight c(i,j) − f(i,j), if c(i,j) − f(i,j) > 0 and
   (ii) an edge (j,i) with weight f(i,j), if f(i,j) > 0.
*/

#define MAX 105

bool bfs(int g[MAX][MAX], int n, int start, int end, vector<int>& parent) {
    std::queue<int> q;
    vector<bool> visited;

    for (int i = 0; i < n; i++) {
        visited.push_back(false);
        parent.push_back(-1);
    }
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == end) {
            return true;
        }

        for (int i = 0; i < n; i++) {
            if (g[v][i] > 0 && visited[i] == false) {
                q.push(i);
                visited[i] = true;
                parent[i] = v;
            }
        }
    }
    return false;
}

int find_volume(int g[MAX][MAX], vector<int>& parent, int start, int end) {
    int volume = 2 << 27;
    while (parent[end] != -1) {
        int u = parent[end];
        int v = end;

        if (g[u][v] < volume) {
            volume = g[u][v];
        }
        end = parent[end];
    }
    return volume;
}

void augment(int g[MAX][MAX], vector<int>& parent, int start, int end, int volume) {
    while (parent[end] != -1) {
        int u = parent[end];
        int v = end;
        g[u][v] -= volume; // reduce the residual capacity of edge (i,j)
        g[v][u] += volume; // but increase the residual capacity of edge (j,i)
        end = parent[end];
    }
}

int netflow(int g[MAX][MAX], int n, int source, int sink) {
    int volume = 0, sum = 0;
    vector<pair<int,int>> path;
    vector<int> parent;

    while (1) {
        // (1) Edmonds-Karp uses bfs to select the next shortest path
        parent.clear();
        bool ok = bfs(g, n, source, sink, parent);
        if (!ok) { break; }

        // (2) calculate the volume using the parent array
        volume = find_volume(g, parent, source, sink);
        sum += volume;

        // (3) last step, augment the path with the new volume
        augment(g, parent, source, sink, volume);
    }
    return sum;
}

int main() {
    /* answer = 25
     4
     1 4 5
     1 2 20
     1 3 10
     2 3 5
     2 4 10
     3 4 20
     0
    */
    //freopen("sample.in", "r", stdin);
    int n, network = 1;
    while (scanf("%d", &n) == 1 && n != 0) {
        int s, t, connections;
        scanf("%d %d %d", &s, &t, &connections);

        int g[MAX][MAX];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                g[i][j] = 0;
            }
        }

        int u, v, capacity;
        for (int i = 0; i < connections; i++) {
            scanf("%d %d %d", &u, &v, &capacity);
            g[u-1][v-1] += capacity;
            g[v-1][u-1] += capacity;
        }
        int bandwidth = netflow(g, n, s-1, t-1);

        printf("Network %d\n", network++);
        printf("The bandwidth is %d.\n\n", bandwidth);
    }
    return 0;
}
