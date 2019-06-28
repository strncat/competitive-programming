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

// assuming start is a valid point
int bfs(int start, int end, int *codes, int n) {
    char visited[MAX] = {0};
    std::queue<std::pair<int,int>> q;
    int parent[MAX];

    q.push(std::make_pair(start, 0));
    visited[start] = 1;
    parent[start] = -1;

    while(!q.empty()) {
        int cur = q.front().first;
        int d = q.front().second;
        q.pop();

        if (cur == end) {
            return d;
        }

        // all possible additions
        for (int i = 0; i < n; i++) {
            int next = (cur + codes[i]) % 10000;
            if (!visited[next]) {
                visited[next] = 1;
                q.push(std::make_pair(next, d+1));
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
