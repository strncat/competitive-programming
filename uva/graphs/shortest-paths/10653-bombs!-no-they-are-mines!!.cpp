//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/19/19.
//  10653 - Bombs! NO they are Mines!!
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits.h>

#define MAX 1003

int R, C, start_i, start_j, end_i, end_j;
bool g[MAX][MAX];

// assuming start is a valid point
int bfs() {
    if (start_i == end_i && start_j == end_j) { return 0; }
    std::queue<std::tuple<int, int, int>> q;
    bool visited[MAX][MAX] = {false};

    // first node
    visited[start_i][start_j] = true;
    q.push(std::make_tuple(start_i, start_j, 0));

    while(!q.empty()) {
        std::tuple<int, int, int> cur = q.front();
        q.pop();
        int i = std::get<0>(cur), j = std::get<1>(cur), d = std::get<2>(cur);

        if (i == end_i && j == end_j) { return d+1; }

        // go through all neighbors
        // up
        if (i > 0 && !visited[i-1][j] && g[i-1][j]) {
            if (i-1 == end_i && j == end_j) { return d+1; }
            visited[i-1][j] = true;
            q.push(std::make_tuple(i-1, j, d+1));
        }

        // down
        if (i < R && !visited[i+1][j] && g[i+1][j]) {
            if (i+1 == end_i && j == end_j) { return d+1; }
            visited[i+1][j] = true;
            q.push(std::make_tuple(i+1, j, d+1));
        }


        // left
        if (j > 0 && !visited[i][j-1] && g[i][j-1]) {
            if (i == end_i && j-1 == end_j) { return d+1; }
            visited[i][j-1] = true;
            q.push(std::make_tuple(i, j-1, d+1));
        }

        // right
        if (j < C && !visited[i][j+1] && g[i][j+1]) {
            if (i == end_i && j+1 == end_j) { return d+1; }
            visited[i][j+1] = true;
            q.push(std::make_tuple(i, j+1, d+1));
        }

    }
    return -1;
}

// read the input, my least favorite part agh :(
void read_graph() {
    int n;
    scanf("%d\n", &n);

    std::string line;
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);
        if (line.size() == 0) { return; } //hack af
        std::istringstream iss(line);
        int col, row, bombs;
        iss >> row >> bombs;
        for (int j = 0; j < bombs; j++) {
            iss >> col;
            g[row][col] = false; // bomb;
        }
    }
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    while (1) {
        scanf("%d %d\n", &R, &C);
        if (!R && !C) { break; }
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                g[i][j] = true;
            }
        }
        read_graph();

        // read start and end position
        scanf("%d %d %d %d", &start_i, &start_j, &end_i, &end_j);
        printf("%d\n", bfs());
    }

    return 0;
}
