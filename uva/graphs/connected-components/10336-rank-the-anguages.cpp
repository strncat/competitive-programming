//
//  10336 - Rank the Languages
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <unordered_map>
#include <algorithm>

#define MAX 101

void bfs(int x, int y, char grid[MAX][MAX], bool visited[MAX][MAX], int m, int n, char letter) {
    int dx[4] = {0,-1,1,0};
    int dy[4] = {1,0,0,-1};

    std::queue<std::pair<int,int>> q;
    q.push(std::make_pair(x,y));
    visited[x][y] = true;

    while (!q.empty()) {
        std::pair<int,int> p = q.front();
        int i = p.first;
        int j = p.second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int next_x = i + dx[k];
            int next_y = j + dy[k];

            // visited or out of bounds
            if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n || visited[next_x][next_y]) {
                continue;
            }

            // not the same letter
            if (grid[next_x][next_y] != letter) {
                continue;
            }

            visited[next_x][next_y] = true;
            q.push({next_x, next_y});
        }
    }
}

int main() {
    //freopen("in.txt" , "r" , stdin);
    int tests, n, m;
    scanf("%d", &tests);
    char grid[MAX][MAX];

    for (int test = 1; test <= tests; test++) {
        scanf("%d %d\n", &m, &n);
        std::string line;
        for (int i = 0; i < m; i++) {
            std::getline(std::cin, line);
            for (int j = 0; j < n; j++) {
                grid[i][j] = line[j];
            }
        }
        
        bool visited[MAX][MAX] = {false};
        std::unordered_map<char,int> map;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    bfs(i,j, grid, visited, m, n, grid[i][j]);
                    map[grid[i][j]]++;
                }
            }
        }

        std::vector<std::pair<char,int>> letters;
        for (auto key = map.begin(); key != map.end(); key++) {
            letters.push_back(std::make_pair(key->first,key->second));
        }

        std::sort(letters.begin(), letters.end(), [](const std::pair<char,int> &l, const std::pair<char,int> &r) {
            if (l.second == r.second) {
                return l.first < r.first;
            }
            return l.second > r.second;
        });

        printf("World #%d\n", test);
        for (int i = 0; i < letters.size(); i++) {
            printf("%c: %d\n", letters[i].first, letters[i].second);
        }
    }
    return 0;
}
