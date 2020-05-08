//
//  main.cpp
//  uhunt
//
//  10276 - Hanoi Tower Troubles Again!
//  2017/03/01
//
//

#include <iostream>
#include <vector>
#include <math.h>

using std::vector;

void construct_candidate(int *a, int ball, int n, int *c, int *ncandidates) {
    for (int i = 1; i <= n; i++) { // possible peg numbers
        int t = sqrt(a[i]+ball);
        if (a[i] == 0 || t*t == a[i]+ball) { // no balls
            c[(*ncandidates)++] = i;
        }
    }
}

int backtrack(int *a, int ball, int n) {
    int c[n];
    int ncandidates = 0;

    ball = ball + 1;
    construct_candidate(a, ball, n, c, &ncandidates);

    if (ncandidates == 0) { // reached the final number
        return 0; // base case
    }

    int max = 0;
    for (int i = 0; i < ncandidates; i++) {
        a[c[i]] = ball;
        int b = backtrack(a, ball, n);
        if (b > max) { max = b; }
    }
    return max + 1;
}

void balls(int n) {
    int a[n+1];
    for (int i = 0; i <= n; i++) { a[i] = 0; }
    int t = backtrack(a, 0, n);
    printf("%d\n", t);
}

int main() {
    //freopen("sample.in", "r", stdin);
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        balls(n);
    }
    return 0;
}