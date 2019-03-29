//
//  2014 1A Problem B. Full Binary Tree
//  https://code.google.com/codejam/contest/2984486/dashboard#s=p1
//
//  Solution (idea at least) from https://www.go-hero.net/jam/14/name/squark
//
//  Created by Fatima Broom on 3/5/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <assert.h>
#include <vector>
#include <stack>

/* I had an initial solution where I perform a dfs on each node and then
 check the total nodes reachable while pruning those with 1 child BUT
 my solution kept getting rejected and by looking at one of the solutions
 from go-hero I discovered that some nodes might actually have more than
 2 children :( and those shouldn't be counted, you need to always pick
 the two children with the maximum number of nodes
*/

std::vector<int> graph[1002];
int f[1002]; // carries the size of the full binary tree for that subtree
bool visited[1002];

int dfs(int root) {
    visited[root] = true;
    std::vector<int> t;
    for (int j = 0; j < graph[root].size(); j++) {
        if (!visited[graph[root][j]]) {
            dfs(graph[root][j]);
            t.push_back(f[graph[root][j]]);
        }
    }
    if (t.size() >= 2) { // the number of children
        std::sort(t.begin(), t.end(), std::greater<int>()); // sort to pick the best two children
        f[root] = t[0] + t[1] + 1;
    } else {
        f[root] = 1;
    }
    return f[root]; // biggest full binary tree
}

int dfs_main(int i) {
    memset(visited, 0, sizeof(visited));
    return dfs(i);
}

int main() {
    // measure time
    clock_t begin, end;
    double time_spent;
    begin = clock();

    freopen("in-large.txt" , "r" , stdin);
    freopen("out-large.txt" , "w" , stdout);

    int test_cases;
    scanf("%d", &test_cases);

    for (int t = 1; t <= test_cases; t++) {
        int n;
        scanf("%d", &n); // n vertices

        for (int i = 0; i < n-1; i++) { // n-1 edges
            int x, y;
            scanf("%d %d", &x, &y);
            x--; y--;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        // try for each node to be a root

        int current, max = 0;
        for (int i = 0; i < n; i++) {
            current = dfs_main(i);
            if (current > max) {
                max = current;
            }
        }
        printf("Case #%d: %d\n", t, n-max); // minimum nodes to be deleted
        // reset graph
        for (int i = 0; i < n; i++) {
            graph[i].clear();
        }
    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    assert(time_spent < 3.1); // because in practice problems you only submit the output
    return 0;
}
