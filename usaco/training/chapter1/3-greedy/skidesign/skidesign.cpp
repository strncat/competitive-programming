/*
 ID: fatima.1
 PROG: skidesign
 LANG: C++11
 */

/* Given an array of hill heights. If it costs x^2 units of money to change 
  the height of a hill by x units, what is the minimum amount of money FJ will need to pay? */

#include <iostream>
#include <algorithm>
#include <limits.h>

#define MAX 1002
int N, hill[MAX];

int compare(const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int solve(void) {
    int cost = 0, highest_hill = 0, min_cost = INT_MAX;

    for (int i = 0; i < N; i++) {
        scanf("%d", &hill[i]);
        if (hill[i] > highest_hill) {
            highest_hill = hill[i];
        }
    }

    // try all possible elevations since it's in the range (0,100) only
    // (0,17), (1,18), (2,19) and so on
    // so that every single hill in the array is in that range only
    for (int i = 0; i <= highest_hill; i++) {

        for (int j = 0; j < N; j++) {
            if (hill[j] < i) {
               cost += (i - hill[j])*(i - hill[j]);
            } else if (hill[j] > i+17) {
                cost += (hill[j] - (i+17))*(hill[j] - (i+17));
            }
        }

        // is this cost better?
        if (cost < min_cost) {
            min_cost = cost;
        }
        cost = 0;

    }
    return min_cost;
}

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &hill[i]);
    }
    std::cout << solve() << std::endl;
}