//
//  main.cpp
//  uhunt
//
//  10267 - Graphical Editor
//  2017/03/13
//

#include <iostream>
#include <sstream>
#include <algorithm>

char g[300][300];

void clear(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            g[i][j] = 'O';
        }
    }
}

void print(int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            printf("%c",g[i][j]);
        }
        printf("\n");
    }
}

void fill_col(int x, int y1, int y2, int m, int c) {
    if (y1 > y2) { std::swap(y1, y2); }
    for (int i = y1; i <= y2; i++) {
        for (int j = 1; j <= m; j++) {
            if (j == x) {
                g[i][j] = c;
            }
        }
    }
}

void fill_row(int y, int x1, int x2, int n, int c) {
    if (x1 > x2) { std::swap(x1, x2); }
    for (int j = x1; j <= x2; j++) {
        for (int i = 1; i <= n; i++) {
            if (i == y) {
                g[i][j] = c;
            }
        }
    }
}

void fill_rect(int x1, int y1, int x2, int y2, int c) {
    if (y1 > y2) { std::swap(y1, y2); }
    if (x1 > x2) { std::swap(x1, x2); }
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            g[i][j] = c;
        }
    }
}

void fill_region(int x, int y, int c, int old_c, int n, int m) {
    if (g[y][x] != old_c) { return; }
    g[y][x] = c;

    if (x > 1) {
        fill_region(x-1, y, c, old_c, n, m);
    }

    if (y > 1) {
        fill_region(x, y-1, c, old_c, n, m);
    }

    if (x < m) {
        fill_region(x+1, y, c, old_c, n, m);
    }

    if (y < n) {
        fill_region(x, y+1, c, old_c, n, m);
    }
}

int main() {
    //freopen("sample.in", "r", stdin);

    std::string line;
    char name[100];
    int n = 0, m = 0, x = 0, y = 0;
    int y1 = 0, y2 = 0, x1 = 0, x2 = 0;
    char t, c = 'O';
    clear(300,300);

    while (std::getline(std::cin, line)) { //  '\r'
        if (line[0] == 'X') { break; }

        if (line[0] == 'I') {
            sscanf(line.c_str(), "%c %d %d", &t, &m, &n);
            clear(n,m);
        }

        else if (line[0] == 'L') {
            sscanf(line.c_str(), "%c %d %d %c", &t, &x, &y, &c);
            g[y][x] = c;
        }

        else if (line[0] == 'C') {
            clear(n, m);
        }

        else if (line[0] == 'V') {
            sscanf(line.c_str(), "%c %d %d %d %c", &t, &x, &y1, &y2, &c);
            fill_col(x, y1, y2, m, c);
        }

        else if (line[0] == 'H') {
            sscanf(line.c_str(), "%c %d %d %d %c", &t, &x1, &x2, &y, &c);
            fill_row(y, x1, x2, n, c);
            //print(n, m);
        }

        else if (line[0] == 'K') {
            sscanf(line.c_str(), "%c %d %d %d %d %c", &t, &x1, &y1, &x2, &y2, &c);
            fill_rect(x1, y1, x2, y2, c);
        }

        else if (line[0] == 'F') {
            sscanf(line.c_str(), "%c %d %d %c", &t, &x, &y, &c);
            if (c == g[y][x]) { continue; }
            fill_region(x, y, c, g[y][x], n, m);
        }

        else if (line[0] == 'S') {
            sscanf(line.c_str(), "%c %s", &t, name);
            printf("%s\n", name);
            print(n, m);
        }
    }
    return 0;
}
