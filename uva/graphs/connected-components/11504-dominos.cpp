//
// Kosaraju's Strongly Connected Components
// 11504 - Dominos
//
//

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <string.h>

typedef std::vector<std::vector<int>> graph;

graph reverse_graph(graph& g) {
    graph reversed;
    for (int i = 0; i < g.size(); i++) {
        reversed.push_back(std::vector<int>());
    }
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            reversed[g[i][j]].push_back(i);
        }
    }
    return reversed;
}

// first pass of dfs to order the node by finishing time
void dfs(graph& g, int v, bool *visited, std::stack<int> &finished) {
    visited[v] = true;
    for (auto i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (visited[u] == false) {
            visited[u] = true;
            dfs(g, u, visited, finished);
        }
    }
    finished.push(v); // bye
}

int dfs(graph& g, int start, bool *visited) {
    std::stack<int> s;
    s.push(start);
    int count = 1;
    visited[start] = true;

    while (!s.empty()) {
        int v = s.top();
        s.pop();
        for (auto i = g[v].begin(); i != g[v].end(); i++)
            if (visited[*i] == false) {
                visited[*i] = true;
                s.push(*i);
                count++;
            }
    }
    return count;
}

int strongly_connected_components(graph& g) {
    // (1) we need to order the nodes by their finishing times
    std::stack<int> finished; // finished will collect the nodes ordered by finishing times
    bool visited[g.size()];
    memset(visited, 0, sizeof(visited[0])*g.size());
    for(int i = 0; i < g.size(); i++) {
        if (!visited[i]) {
            dfs(g, i, visited, finished);
        }
    }

    // SO THIS ISN'T REALLY KOSARAJU
    // It's a slight modification
    // We do want to sort the vertices by finishing time
    // But if vertex 1 pushes 2, we don't care that 2 pushes 1.
    // All we care about is to maximize the number of vertices 1 can push
    // SO we do the second DFS pass in the original graph :)

    // (2) we now reverse all the edges in g
    //graph g_reversed = reverse_graph(g);

    // (3) DFS again but this time by the finished order though
    int count = 0;
    memset(visited, 0, sizeof(visited[0])*g.size());
    while (!finished.empty()) {
        int v = finished.top();
        finished.pop();
        if (!visited[v]) {
            // all the nodes reached from this pass are in one strongly connected component
            dfs(g, v, visited);
            count++;
        }
    }
    return count;
}

int main() {
    //freopen("in.txt", "r", stdin);
    int tests;
    scanf("%d", &tests);

    while (tests--) {
        int n, m;
        scanf("%d %d", &n, &m);
        graph g;
        for (int i = 0; i < n; i++) {
            g.push_back(std::vector<int>());
        }

        int x, y;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &x, &y);
            x--; y--;
            g[x].push_back(y);
        }
        printf("%d\n", strongly_connected_components(g));
    }
    return 0;
}
