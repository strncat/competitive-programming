//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/19/19.
//  11624 - Fire!
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits.h>
#include <set>

#define MAX 1003
#define INF 1000000

int R, C, joe_i, joe_j;
char m[MAX][MAX];

int dx[4] = {1 , 0 , -1 , 0};
int dy[4] = {0 , 1 , 0 , -1};
std::vector<std::pair<int,int>> fires;
int fire_distance[MAX][MAX];
int joe_distance[MAX][MAX];
bool visited[MAX][MAX];

void print_distance(int d[MAX][MAX]) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (d[i][j] == INF) {
                printf("-1\t");
            } else {
                printf("%d\t", d[i][j]);
            }
        }
        printf("\n");
    }
}

int multi_source_bfs() {
    std::queue<std::pair<int, int>> q;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            fire_distance[i][j] = INF;
            visited[i][j] = 0;
        }
    }

    // we may have multiple fires, set all distances to zero
    for (int i = 0; i < fires.size(); i++) {
        q.push(fires[i]);
        fire_distance[fires[i].first][fires[i].second] = 0;
        visited[fires[i].first][fires[i].second] = true;
    }

    // your good old bfs
    while (!q.empty()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        for (int k = 0; k < 4; k++) {
            int next_x = x + dx[k];
            int next_y = y + dy[k];
            if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C
                || visited[next_x][next_y] || m[next_x][next_y] == '#') {
                continue;
            }
            visited[next_x][next_y] = true;
            fire_distance[next_x][next_y] = fire_distance[x][y] + 1;
            q.push({next_x, next_y});
        }
    }

    // now we can use the above to reduce the search scope for Joe
    // TRUST ME I tried many other approaches, they all TIMED OUT
    // simple bfs
    std::queue<std::pair<int, int>> bq;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            visited[i][j] = 0;
        }
    }

    // first node
    if (joe_i == 0 || joe_i == R-1 || joe_j == 0 || joe_j == C-1) { return 1; } //success

    visited[joe_i][joe_j] = true;
    bq.push(std::make_pair(joe_i, joe_j));
    joe_distance[joe_i][joe_j] = 1;

    while(!bq.empty()) {
        int x = bq.front().first;
        int y = bq.front().second;
        bq.pop();

        if (x == 0 || x == R-1 || y == 0 || y == C-1) {
            return joe_distance[x][y];
        } //success

        for (int k = 0; k < 4; k++) {
            int next_x = x + dx[k];
            int next_y = y + dy[k];

            if (next_x < 0 || next_x >= R || next_y < 0 || next_y >= C) { // bounds
                continue;
            }

            if (joe_distance[x][y]+1 > fire_distance[next_x][next_y]) { // fire is already there
                continue;
            }

            if (visited[next_x][next_y] || m[next_x][next_y] == '#') { // visited or wall
                continue;
            }

            visited[next_x][next_y] = true;
            bq.push({next_x, next_y});
            joe_distance[next_x][next_y] = joe_distance[x][y]+1;
        }
    }
    return -1;
}

//int counter = 1;
// read the input, my least favorite part agh :(
void read_board() {
    scanf("%d %d\n", &R, &C);

    //printf("counter %d: %d %d\n", counter++, R, C);
    //if (counter == 79) {exit(0);}

    char line[MAX];
    for (int i = 0; i < R; i++) {
        fgets(line, MAX, stdin);
        for (int j = 0; j < C; j++) {
            m[i][j] = line[j]; // put each char in its cell
            if (line[j] == 'J') { // Joe's position
                joe_i = i;
                joe_j = j;
            }
            if (m[i][j] == 'F') { // add a fire to the list of fires
                fires.push_back(std::make_pair(i, j));
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    //freopen("in.txt" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    int tests;
    scanf("%d", &tests);


    while (tests--) {
        fires.clear();

        read_board();

        int best_distance = multi_source_bfs();
        if (best_distance == -1) {
            printf("IMPOSSIBLE\n");
        } else {
            printf("%d\n", best_distance);
        }
    }

    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f", time_spent);
    return 0;
}
