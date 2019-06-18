//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/17/19.
//  532 - Dungeon Master
//

#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>

#define MAX 35

char m[MAX][MAX][MAX];
int L, R, C, start_k, start_i, start_j;

void print() {
    for (int k = 0; k < L; k++) {
        // each board
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                printf("%c", m[k][i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void read() {
    char line[MAX];
    // each level
    for (int k = 0; k < L; k++) {
        // each board
        for (int i = 0; i < R; i++) {
            fgets(line, MAX, stdin);
            for (int j = 0; j < C; j++) {
                m[k][i][j] = line[j];
                if (m[k][i][j] == 'S') {
                    start_k = k;
                    start_i = i;
                    start_j = j;
                }
            }
        }
        fgets(line, MAX, stdin);
    }
}


// figuring out the total cells in the path
typedef std::tuple<int, int, int> key;
struct hash : public std::unary_function<key_t, std::size_t> {
    std::size_t operator()(const key& k) const {
        return std::get<0>(k) * 100 + std::get<1>(k) * 10 + std::get<2>(k);
    }
};
typedef std::unordered_map<const key,key,hash,std::equal_to<key>> tuple_map;
tuple_map parent;

int count(key t) {
    int total = 0;
    while (parent.find(t) != parent.end()) {
        total++;
        t = parent[t];
    }
    return total;
}

// assuming start is a valid point
int bfs() {
    char visited[MAX][MAX][MAX] = {0};
    std::queue<key> q;

    visited[start_k][start_i][start_j] = 1;
    q.push(std::make_tuple(start_k,start_i,start_j));
    parent.clear();

    while(!q.empty()) {
        key cur = q.front();
        int ck = std::get<0>(cur), ci = std::get<1>(cur), cj = std::get<2>(cur);
        q.pop();

        if (m[ck][ci][cj] == 'E') {
            return count(cur);
        }

        // 6 places to check on the cube
        // k
        if (ck > 0 && !visited[ck-1][ci][cj] && m[ck-1][ci][cj] != '#') { // can check bottom
            visited[ck-1][ci][cj] = 1;
            key next = std::make_tuple(ck-1, ci, cj);
            q.push(next);
            parent[next] = cur;
        }

        if (ck < L-1 && !visited[ck+1][ci][cj] && m[ck+1][ci][cj] != '#') { // check top
            visited[ck+1][ci][cj] = 1;
            key next = std::make_tuple(ck+1, ci, cj);
            q.push(next);
            parent[next] = cur;
        }

        // i
        if (ci > 0 && !visited[ck][ci-1][cj] && m[ck][ci-1][cj] != '#') { // check up
            visited[ck][ci-1][cj] = 1;
            key next = std::make_tuple(ck, ci-1, cj);
            q.push(next);
            parent[next] = cur;
        }

        if (ci < R-1 && !visited[ck][ci+1][cj] && m[ck][ci+1][cj] != '#') { // check down
            visited[ck][ci+1][cj] = 1;
            key next = std::make_tuple(ck, ci+1, cj);
            q.push(next);
            parent[next] = cur;
        }

        // j
        if (cj > 0 && !visited[ck][ci][cj-1] && m[ck][ci][cj-1] != '#') { // left
            visited[ck][ci][cj-1] = 1;
            key next = std::make_tuple(ck, ci, cj-1);
            q.push(next);
            parent[next] = cur;
        }

        if (cj < C-1 && !visited[ck][ci][cj+1] && m[ck][ci][cj+1] != '#') { // right
            visited[ck][ci][cj+1] = 1;
            key next = std::make_tuple(ck, ci, cj+1);
            q.push(next);
            parent[next] = cur;
        }
    }

    return -1;
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    while (1) {
        scanf("%d %d %d\n", &L, &R, &C);
        if (L == 0 && R == 0 && C == 0) {
            break;
        }
        read();
        //print();

        int t = bfs();
        if (t != -1) {
            printf("Escaped in %d minute(s).\n", t);
        } else {
            printf("Trapped!\n");
        }

    }
}
