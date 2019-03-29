//
//  572 - Oil Deposits
//  https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=513
//
//  Created by Fatima Broom on 3/5/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <string>

#define MAX 101

int a[MAX][MAX];
int visited[MAX][MAX];

void bfs(int i, int j, int rows, int columns) {
    // i-1,j-1  i-1,j   i-1,j+1
    // i,j-1    i,j     i,j+1
    // i+1,j-1  i+1,j   i+1,j+1

    // i-1, j-1
    if (i > 0 && j > 0 && a[i-1][j-1] && !visited[i-1][j-1]) {
        visited[i-1][j-1] = 1;
        bfs(i-1, j-1, rows, columns);
    }

    // i-1, j
    if (i > 0 && a[i-1][j] && !visited[i-1][j]) {
        visited[i-1][j] = 1;
        bfs(i-1, j, rows, columns);
    }

    // i-1, j+1
    if (i > 0 && a[i-1][j+1] && j < columns-1 && !visited[i-1][j+1]) {
        visited[i-1][j+1] = 1;
        bfs(i-1, j+1, rows, columns);
    }

    // i, j-1
    if (j > 0 && a[i][j-1] && !visited[i][j-1]) {
        visited[i][j-1] = 1;
        bfs(i, j-1, rows, columns);
    }

    // i, j+1
    if (j < columns-1 && a[i][j+1] && !visited[i][j+1]) {
        visited[i][j+1] = 1;
        bfs(i, j+1, rows, columns);
    }

    // i+1, j-1
    if (i < rows-1 && j > 0 && a[i+1][j-1] && !visited[i+1][j-1]) {
        visited[i+1][j-1] = 1;
        bfs(i+1, j-1, rows, columns);
    }

    // i+1
    if (i < rows-1 && a[i+1][j] && !visited[i+1][j]) {
        visited[i+1][j] = 1;
        bfs(i+1, j, rows, columns);
    }

    // i+1, j+1
    if (i < rows-1 && a[i+1][j+1] && j < columns-1 && !visited[i+1][j+1]) {
        visited[i+1][j+1] = 1;
        bfs(i+1, j+1, rows, columns);
    }

}

int connected_components(int rows, int columns) {
    // reset visited and count
    int c = 0;
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            visited[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (a[i][j] == 1 && !visited[i][j]) {
                visited[i][j] = 1;
                bfs(i, j, rows, columns);
                c++;
            }
        }
    }

    return c;
}

void print(int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << a[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    //freopen("example.in", "r", stdin);
    //freopen("example.out", "w", stdout);

    while (1) {
        int rows, columns;
        scanf("%d %d", &rows, &columns);

        if (rows == 0 && columns == 0) { break; }

        std::string s;
        for (int i = 0; i < rows; i++) {
            std::cin >> s;

            for (int j = 0; j < columns; j++) {
                if (s[j] == '*') { a[i][j] = 0; }
                else { a[i][j] = 1; }
            }
        }
        std::cout << connected_components(rows, columns) << std::endl;
    }
    return 0;
}
