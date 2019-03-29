//
//  main.cpp
//  uhunt
//
//  10344 - 23 out of 5
//  2017/03/02
//
//

#include <iostream>
#include <vector>

using std::vector;

bool dfs(int *a, int *visited, int value, int counter) {
    if (value == 23 && counter == 5) {
        return true;
    }
    counter++;
    bool b = false;
    for (int i = 0; i < 5; i++) {
        if (!visited[i]) {
            visited[i] = true;
            b = dfs(a, visited, value - a[i], counter);
            if (b) { return true; }

            b = dfs(a, visited, value + a[i], counter);
            if (b) { return true; }

            b = dfs(a, visited, value * a[i], counter);
            if (b) { return true; }
            visited[i] = false;
        }
    }
    return b;
}

int main() {
    //freopen("sample.in", "r", stdin);
    int a[5];
    while (1) {
        scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0) { break; }

        bool b = false;
        for (int i = 0; i < 5; i++) {
            int visited[5] = {false};
            visited[i] = true;
            b = dfs(a, visited, a[i], 1);
            visited[i] = false;
            if (b) { break; }
        }
        if (b) { printf("Possible\n"); } else { printf("Impossible\n"); }
    }
    return 0;
}