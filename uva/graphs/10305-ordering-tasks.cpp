//
//  main.cpp
//  uhunt
//
//  10305 - Ordering Tasks
//  2017/02/25
//
//

#include <iostream>
#include <vector>
#include <stack>

using std::vector;

void topological_sort(vector<vector<int>> graph) {
    int indegree[110] = {0};
    vector<int> order;
    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph[i].size(); j++) {
            indegree[graph[i][j]]++;
        }
    }
    std::stack<int> s;
    for (int i = 0; i < graph.size(); i++) {
        if(indegree[i] == 0) {
            s.push(i);
        }
    }
    while (s.size()) {
        int t = s.top();
        s.pop();
        order.push_back(t+1);
        for (int i = 0; i < graph[t].size(); i++) {
            int v = graph[t][i];
            indegree[v]--;
            if (indegree[v] == 0) {
                s.push(v);
            }
        }
    }
    printf("%d", order[0]);
    for (int i = 1; i < order.size(); i++) {
        printf(" %d", order[i]);
    }
    printf("\n");
}


int main() {
    //freopen("sample.in", "r", stdin);
    int n, m;

    while (scanf("%d %d", &n, &m)) {
        if (n == 0 && m == 0) { break; }

        vector<vector<int>> graph;
        for (int i = 0; i < n; i++) {
            graph.push_back(vector<int>());
        }

        int p, q;
        for (int i = 0; i < m; i++) {
            scanf("%d %d", &p, &q);
            graph[p-1].push_back(q-1);
        }
        topological_sort(graph);
    }
}
