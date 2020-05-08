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
#include <unordered_map>

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
    freopen("in.txt" , "r" , stdin);

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

        std::vector<bool> sel(a.size(), false);
        // a = [1,3,4,6,7,8,...] actual elements
        // index = 0
        // sel = [false, false, ... ] for all elements
        // number of selections made so far
        backtrack(a, 0, sel, 0);

        scanf("%d", &k);
        if (k == 0) {
            break;
        } else {
            printf("\n");
        }
    }
    return 0;
}
