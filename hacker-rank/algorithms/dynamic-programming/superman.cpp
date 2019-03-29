/*
 4 15 2
 5 1 1 1 4 10
 8 9 5 7 7 3 9 8 8
 5 9 5 6 4 3
 0
 output = 12
 3 5 2
 2 1 3
 4 1 2 3 4
 1 1
 output = 4
 */
#include <iostream>

#define MAX 2000
int b[MAX][MAX]; // has to be global because of the size
long DP[MAX][MAX];
long maxFloor[MAX];
int I, H, N;

long recursive(int building, int floor) {
    if (building <= 0 || floor <= 0) { return 0; }
    
    // either stay in the same building
    long max = recursive(building, floor - 1);
    
    // OR jump to another building with a loss in floors = I
    for (int i = 1; i <= N; i++) {
        long candidate = 0;
        if (i != building) { // not the same building
            candidate = recursive(i, floor - I); // take a loss of I floors in building i
        }
        if (candidate > max) {
            max = candidate;
        }
    }
    return b[building][floor] + max;
}

long dynamicProgramming() {
    long max = 0;
    int floor, building;

    // The DP value in a specific floor/building will depend on those floors below that floor only
    // We need to finish it floor by floor
    // For each Floor we'll compute the maximum at that floor

    for (floor = 1; floor <= H; floor++) { // for each floor

        for (building = 1; building <= N; building++) { // for each building in that floor

            DP[building][floor] = DP[building][floor - 1] + b[building][floor]; // initially DP is just the floor below

            if (floor >= I && maxFloor[floor - I] + b[building][floor] > DP[building][floor]) { // but floor - I might have a higher value
                DP[building][floor] = maxFloor[floor - I] + b[building][floor];
            }

            if (DP[building][floor] > maxFloor[floor]) { // update the max for this floor
                maxFloor[floor] = DP[building][floor];
            }
        }
        if (maxFloor[floor] > max) { // max of all floors
            max = maxFloor[floor];
        }
    }
    return max;
}

int main() {
    scanf("%d %d %d", &N, &H, &I);

    // reset
    for (int i = 0; i <= N; i++) {
        maxFloor[i] = 0;
        for (int j = 0; j <= H; j++) {
            b[i][j] = 0;
            DP[i][j] = 0;
        }
    }

    // input
    for (int i = 1; i <= N; i++) { // for every building
        int people, floor;
        scanf("%d", &people); // number of people in that building
        for (int j = 1; j <= people; j++) { // read where people are located
            scanf("%d", &floor);
            b[i][floor]++; // there exists a person on that floor
        }
    }

    long max = dynamicProgramming();

    printf("%ld\n", max);
    return 0;
}
