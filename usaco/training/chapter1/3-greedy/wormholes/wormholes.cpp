/*
 ID: fatima.1
 PROG: wormhole
 LANG: C++11
 */
#include <iostream>

/* source: http://usaco.org/current/data/sol_wormhole.html
   We have worms acorss a grid. Each pair of worms creates a wormhole
   A o B
   o o o
   If the above is the grid, then bessie will get stuck if it starts at
   position 0,1 .. it will enter B and exists from A and so on infinitely */


#define MAX 13
int N, x[MAX], y[MAX];
int partner[MAX], next_on_right[MAX]; // to keep track of which worm is paired with which other worm


bool cycle_exists() {
    for (int start=1; start<=N; start++) {
        // does a cycle exist starting at start?
        int pos = start;
        for (int count=0; count<N; count++) {
            // transport to partner and then move right
            pos = next_on_right[partner[pos]];
        }
        if (pos != 0) {
            return true;
        }
    }
    return false;
}

// count all solutions
int solve(void)
{
    // find first unpaired worm
    int i, total = 0;
    for (i = 1; i <= N; i++) {
        if (partner[i] == 0) { break; }
    }

    // matching complete, check for cycles
    if (i > N) {
        if (cycle_exists()) { return 1; }
        else return 0;
    }

    // try pairing i with all possible other worms j
    for (int j=i+1; j<=N; j++) {
        if (partner[j] == 0) {
            // try pairing i & j, let recursion continue to
            // generate the rest of the solution
            partner[i] = j;
            partner[j] = i;
            total += solve();
            partner[i] = partner[j] = 0;
        }
    }
    return total;
}

int main() {
    freopen("wormhole.in", "r", stdin);
    freopen("wormhole.out", "w", stdout);

    scanf("%d", &N);
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    // set next_on_right
    for (int i=1; i<=N; i++) { // set next_on_right[i]...
        for (int j=1; j<=N; j++) {
            if (x[j] > x[i] && y[i] == y[j]) { // j right of i...
                if (next_on_right[i] == 0 || x[j]-x[i] < x[next_on_right[i]]-x[i]) {
                    next_on_right[i] = j;
                }
            }
        }
    }
    std::cout << solve() << std::endl;
}