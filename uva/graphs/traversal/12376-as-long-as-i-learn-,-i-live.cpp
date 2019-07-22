//
//  main.cpp
//  12376 - As Long as I Learn, I Live
//
//  Created by FB on 7/12/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>

#define MAX 10000
typedef std::vector<std::vector<int>> graph;
int learning_values[MAX];

std::pair<int,int> bfs(graph& g, int v) {
    std::queue<int> q;
    bool visited[MAX] = {false};
    q.push(0);
    int total = 0;
    int last_node = -1;
    while (!q.empty()) {
        int u = q.front();
        last_node = u;
        q.pop();
        total += learning_values[u];
        int max_vertex = -1;
        int max = 0;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (!visited[v] && learning_values[v] > max) {
                max = learning_values[v];
                max_vertex = v;
            }
        }
        if (max_vertex != -1) {
            q.push(max_vertex);
        }
    }
    return {total, last_node};
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt", "r", stdin);
    int t, n, m, value;
    scanf("%d", &t);

    for (int k = 0; k < t; k++) {
        scanf("%d %d", &n, &m);
        graph g;
        for (int i = 0; i < n; i++) {
            scanf("%d", &value);
            g.push_back(std::vector<int>());
            learning_values[i] = value;
        }

        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            g[u].push_back(v);
        }
        std::pair<int,int> p = bfs(g, 0);
        printf("Case %d: %d %d\n", k+1, p.first, p.second);
    }
    return 0;
}
