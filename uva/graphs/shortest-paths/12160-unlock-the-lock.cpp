//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/17/19.
//  12160 - Unlock the Lock
//

#include <iostream>
#include <queue>

#define MAX 10000

int count(int t, int *parent) {
    int total = 0;
    while (parent[t] != -1) {
        total++;
        t = parent[t];
    }
    return total;
}

// assuming start is a valid point
int bfs(int start, int end, int *codes, int n) {
    char visited[MAX] = {0};
    std::queue<int> q;
    int parent[MAX];

    q.push(start);
    visited[start] = 1;
    parent[start] = -1;

    while(!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == end) {
            return count(cur, parent);
        }

        // all possible additions
        for (int i = 0; i < n; i++) {
            int next = (cur + codes[i]) % 10000;
            if (!visited[next]) {
                visited[next] = 1;
                q.push(next);
                parent[next] = cur;
            }
        }

    }
    return -1;
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    int codes[100]; // number of codes
    int L, U, R, test = 1;

    while (1) {
        scanf("%d %d %d\n", &L, &U, &R);
        if (L == 0 && U == 0 && R == 0) {
            break;
        }
        for (int i = 0; i < R; i++) {
            scanf("%d", &codes[i]);
        }

        int t = bfs(L, U, codes, R);
        if (t != -1) {
            printf("Case %d: %d\n", test++, t);
        } else {
            printf("Case %d: Permanently Locked\n", test++);
        }
    }
}
