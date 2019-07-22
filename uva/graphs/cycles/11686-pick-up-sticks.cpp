//
//  main.cpp
//  11686 Pick up sticks
//
//  Created by FB on 7/12/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>
#include <stack>
#include <vector>

#define MAX 100000
enum colors {black, gray, white};

typedef std::vector<std::vector<int>> graph;
bool cycle = false;

void dfs(graph& g, int v, int *color, std::stack<int> &ordered) {
    color[v] = gray;
    for (auto i = 0; i < g[v].size(); i++) {
        int u = g[v][i];
        if (color[u] == black) {
            dfs(g, u, color, ordered);
        } else if (color[u] == gray) {
            // CYCLE
            cycle = true;
        }
    }
    color[v] = white;
    ordered.push(v); // node is done, we can push it on the ordered stack
}

void topological_sort(graph& g) {
    std::stack<int> ordered;
    int color[MAX] = {false}; // initially all black
    // perform dfs until there are no more unvisited nodes
    for(int i = 0; i < g.size(); i++) {
        if (color[i] == black) { // first time
            dfs(g, i, color, ordered);
            if (cycle) { break; }
        }
    }

    if (cycle) {
        printf("IMPOSSIBLE\n");
    } else {
        while (!ordered.empty()) {
            printf("%d\n", ordered.top()+1);
            ordered.pop();
        }
    }
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt", "r", stdin);
    int n, m;

    while (scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) {
            break;
        }

        graph g;
        for (int i = 0; i < n; i++) {
            g.push_back(std::vector<int>());
        }

        int u, v;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &u, &v);
            u--; v--;
            g[u].push_back(v);
        }
        cycle = false;
        topological_sort(g);
    }
    return 0;
}
