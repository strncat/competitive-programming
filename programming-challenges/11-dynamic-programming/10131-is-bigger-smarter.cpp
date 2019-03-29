//
//  main.cpp
//  10131 - Is Bigger Smarter?
//
//  Created by FB on 3/22/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>
#include <stack>

#define MAX 1004

int longest_increasing_subsequence(int n, int d[MAX][3]) {
    int c[MAX];
    int p[MAX];
    for (int i = 0; i < n; i++) {
        c[i] = 1;
        p[i] = -1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < i; j++) {
            if (d[i][0] > d[j][0] && d[i][1] < d[j][1] && c[j] >= c[i]) {
                c[i] = c[j] + 1;
                p[i] = j;
            }
        }
    }

    int max = 1;
    int index = 0;
    for (int i = 1; i < n; i++) {
        if (max < c[i]) {
            max = c[i];
            index = i;
        }
    }

    std::stack<int> t;
    t.push(index);
    while (p[index] != -1) {
        t.push(p[index]);
        index = p[index];
    }

    printf("%d\n", max);
    while (!t.empty()) {
        printf("%d\n", d[t.top()][2]);
        t.pop();
    }
    return 0;
}

int compare(const void *a, const void *b) {
    int x1 = *(const int*)a;
    int x2 = *(const int*)b;
    if (x1 > x2) return  1;
    if (x1 < x2) return -1;
    // x1 and x2 are equal; compare y's
    int y1 = *(((const int*)a)+1);
    int y2 = *(((const int*)b)+1);
    if (y1 > y2) return  1;
    if (y1 < y2) return -1;
    return 0;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n = 0, d[MAX][3], size, iq;
    while (scanf("%d %d", &size, &iq) == 2) {
        d[n][0] = size;
        d[n][1] = iq;
        d[n][2] = n+1;
        n++;
    }
    // sort by size
    qsort(d, n, sizeof(d[0]), compare);
    longest_increasing_subsequence(n, d);
    return 0;
}
