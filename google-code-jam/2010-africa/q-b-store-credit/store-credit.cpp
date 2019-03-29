//
//  Store Credit
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>

std::pair<int,int> pickTwo(std::vector<int>& a, int k) {
    std::unordered_map<int, int> m;
    for (int i = 0; i < (int) a.size(); i++) {
        if (m.count(k - a[i])) {
            return {m[k - a[i]], i + 1};
        } else {
            m[a[i]] = i + 1;
        }
    }
    return {-1,-1};
}

int main() {
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    int tests, n, k;
    scanf("%d\n", &tests);
    for (int t = 1; t <= tests; t++) {
        scanf("%d", &k);
        scanf("%d", &n);
        std::vector<int> a;
        for (int i = 0; i < n; i++) {
            int temp;
            scanf("%d", &temp);
            a.emplace_back(temp);
        }
        std::pair<int, int> indices = pickTwo(a, k);
        printf("Case #%d: %d %d\n", t, indices.first, indices.second);
    }
    return 0;
}
