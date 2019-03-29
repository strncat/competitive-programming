//
//  main.cpp
//  uhunt
//
//  574 - Sum It Up
//

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

/*
 Given this array 4 3 2 2 1 1
 to search for 4:
 (1) Once we pick an element i, we start the next search at i+1 and not 0 because we'll 
     end up with both 1,3 and 3,1 for example and we only care about 3,1 in this case.
 (2) To avoid duplicates such as the two (3,1)s, We need just manually check every time
     for duplicates and only store new pairs or use a map<vector<int>,bool> and store 
     the solutions in it.
 
 Other than these notes, the problem is just a backtracking problem, start with an element
 and search for the next elements to complete the sum.
*/

void backtrack(int *a, int *s, int index, int n, int sum,
               int current_sum, std::vector<std::string>& all, int search_index) {
    if (current_sum != sum && index == n) { return; }
    if (current_sum == sum) { // potenial solution
        std::ostringstream oss;
        oss << s[0];
        for (int i = 1; i < index; i++) {
            oss << "+" << s[i];
        }
        auto result = std::find(all.begin(), all.end(), oss.str());
        if (result == all.end()) {
            all.push_back(oss.str());
        }
        return;
    }

    for (int i = search_index; i < n; i++) {
        if (current_sum + a[i] <= sum) { // sum is prime
            s[index] = a[i];
            backtrack(a, s, index+1, n, sum, current_sum + a[i], all, i+1);
        }
    }
}

int main() {
    //freopen("sample.in", "r", stdin);
    int n, sum;
    while (1) {
        scanf("%d %d", &sum, &n);
        if (sum == 0 && n == 0) { break; }

        int a[n], s[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        std::vector<std::string> all;
        printf("Sums of %d:\n", sum);
        for (int i = 0; i < n; i++) {
            s[0] = a[i];
            backtrack(a, s, 1, n, sum, a[i], all, i+1);
        }

        if (all.size() == 0) {
            printf("NONE\n");
        } else {
            std::vector<std::string> sorted;
            for (auto i = all.begin(); i != all.end(); i++) {
                std::cout << *i << std::endl;
            }
        }

    }
    return 0;
}