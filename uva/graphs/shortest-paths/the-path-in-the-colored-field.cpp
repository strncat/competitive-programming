//
//  main.cpp
//  uHunt
//
//  Created by FB on 7/02/19.
//  10102 - The path in the colored field
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <tuple>

#define MAX 1000

char g[MAX][MAX];
int n;
std::vector<std::pair<int,int>> start;
int dx[4] = {1 , 0 , -1 , 0};
int dy[4] = {0 , 1 , 0 , -1};


// assuming start is a valid point
int bfs(int start_i, int start_j) {
    std::queue<std::tuple<int, int, int>> q;
    bool visited[MAX][MAX] = {false};

    // first node
    visited[start_i][start_j] = true;
    q.push(std::make_tuple(start_i, start_j, 0));

    while(!q.empty()) {
        std::tuple<int, int, int> cur = q.front();
        q.pop();
        int i = std::get<0>(cur), j = std::get<1>(cur), d = std::get<2>(cur);

        // (1) can exit here OR exit early below
        if (g[i][j] == '3') {
            return d;
        }

        for (int k = 0; k < 4; k++) {
            int next_x = i + dx[k];
            int next_y = j + dy[k];
            if (next_x < 0 || next_x >= n || next_y < 0 || next_y >= n || visited[next_x][next_y]) {
                continue;
            }
            // could exit early here instead! can be much faster depending on the graph
            visited[next_x][next_y] = true;
            q.push({next_x, next_y, d+1});
        }

    }
    return -1;
}

bool read_input() {
    scanf("%d\n", &n);
    std::string line;
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line); // a line here is 123
        if (line.size() == 0) { return false; }
        for (int j = 0; j < n; j++) {
            g[i][j] = line[j];
            if (g[i][j] == '1') { // starting cells, can have multiple
                start.push_back({i,j});
            }
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    //freopen("in.txt" , "r" , stdin);

    while (1) {
        start.clear();
        if (!read_input()) { break; }
        int max = 0;
        for (int i = 0; i < start.size(); i++) {
            int d = bfs(start[i].first, start[i].second);
            if (max < d) {
                max = d;
            }
        }
        printf("%d\n", max);
    }

    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f\n", time_spent); // 0.246944
    return 0;
}
