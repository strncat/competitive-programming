//
//  main.cpp
//  uHunt
//
//  Created by FB on 7/01/19.
//  1260 - Sales
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    //freopen("in.txt" , "r" , stdin);

    int tests;
    scanf("%d", &tests);

    while (tests--) {
        int n;
        scanf("%d", &n);

        int sales[5001];
        int prev[5001] = {0};

        for (int i = 0; i < n; i++) {
            scanf("%d", &sales[i]);
        }

        for (int i = 0; i < n; i++) { // each sales value
            for (int j = i+1; j < n; j++) { // compare it to each day that comes after it
                if (sales[i] <= sales[j]) {
                    prev[j]++;
                }
            }
        }

        int total = 0;
        for (int i = 1; i < n; i++) {
            total += prev[i];
        }
        printf("%d\n", total);
    }

    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f", time_spent);
    return 0;
}
