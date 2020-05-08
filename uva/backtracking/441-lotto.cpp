//
//  441 - Lotto
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <vector>
#include <limits.h>
#include <queue>
#include <map>
#include <algorithm>
#include <sstream>
#include <set>
#include <stack>

void combinations(std::vector<int>& combination,
                  std::vector<int>& a,
                  int start,
                  int position_to_be_filled) {
    if (position_to_be_filled > 5) { // we are done, print combination
        printf("%d", combination[0]);
        for (int i = 1; i < 6; i++) {
            printf (" %d", combination[i]);
        }
        printf ("\n");
        return;
    }
    int n = (int)a.size();
    for (int i = start; i < n; i++) {
        combination[position_to_be_filled] = a[i];
        // now recursively generate combinations for the next position / next possible start
        combinations(combination, a, i+1, position_to_be_filled+1);
    }
}

void print_combination(std::vector<int>& a, std::vector<bool>& sel) {
    int n = (int)a.size();
    int j = 0;
    for (; j < n; j++) {
        if (sel[j]) {
            printf("%d", a[j]);
            break;
        }
    }
    for (int i = j+1; i < n; i++) {
        if (sel[i]) {
            printf(" %d", a[i]);
        }
    }
    printf("\n");
}

void backtrack(std::vector<int>& a,
               int index,
               std::vector<bool>& sel,
               int selections) {
    if (selections == 6) { // done
        print_combination(a, sel);
        return;
    }
    int n = (int)a.size();
    if (index >= n) { return; } // no more elements
    // two choices
    // (1) select a[i]
    sel[index] = true;
    backtrack(a, index+1, sel, selections+1);

    // (2) don't select a[i]
    sel[index] = false;
    backtrack(a, index+1, sel, selections);

}

int main() {
    //freopen("in.txt" , "r" , stdin);

    int k;
    scanf("%d", &k);
    while (1) {
        std::vector<int> a;
        int u;
        for (int i = 0; i < k; i++) {
            scanf("%d", &u);
            a.push_back(u);
        }

        std::sort(a.begin(), a.end());

        // this way
        //std::vector<bool> sel(a.size(), false);
        //backtrack(a, 0, sel, 0);

        // or this way both work!
        std::vector<int> combination(6, 0);
        combinations(combination, a, 0, 0);

        scanf("%d", &k);
        if (k == 0) {
            break;
        } else {
            printf("\n");
        }
    }
    return 0;
}
