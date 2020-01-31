//
//  main.cpp
//  stars
//
//  Created by Fatima Broom on 12/4/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>
#include <stack>

char g[102][102];
int r, c;
bool visited[102][102];
int dx[] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};

int bfs(int i, int j) {
    int size = 1;
    std::stack<std::pair<int,int>> s;
    s.push(std::pair<int,int>(i,j));
    visited[i][j] = true;

    while (!s.empty()) {
        int cur_i = s.top().first;
        int cur_j = s.top().second;
        s.pop();

        for (int k = 0; k < 8; k++) {
            int new_i = cur_i + dx[k];
            int new_j = cur_j + dy[k];

            if (new_i < 0 || new_i >= r || new_j < 0 || new_j >= c) {
                continue;
            }

            if (!visited[new_i][new_j] && g[new_i][new_j] == '*') {
                visited[new_i][new_j] = true;
                s.push(std::pair<int,int>(new_i,new_j));
                size++;
            }
        }
    }

    return size;
}

int connected_components() {
    int components = 0;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (g[i][j] == '*' && visited[i][j] == false) {
                int size = bfs(i, j);
                if (size == 1) { components++; }
            }
        }
    }

    return components;
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt", "r", stdin);

    while (scanf("%d %d\n", &r, &c) == 2) {
        if (r == 0 && c == 0) {
            break;
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                scanf("%c", &g[i][j]);
            }
            scanf("\n");
        }
        scanf("\n");

//        for (int i = 0; i < r; i++) {
//            for (int j = 0; j < c; j++) {
//                printf("%c", g[i][j]);
//            }
//            printf("\n");
//        }
        printf("%d\n", connected_components());
    }
}
