//
// 1A - A Minimum Scalar Product
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>

long minimumProduct(std::vector<long>&a, std::vector<long>& b) {
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    long long product = 0;
    for (int i = 0; i < a.size(); i++) {
        product += (a[i] * b[b.size() - 1 - i]);
    }
    return product;
}

int main() {
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    int tests, n, temp;
    scanf("%d", &tests);
    for (int t = 1; t <= tests; t++) {
        scanf("%d", &n);
        std::vector<long> a, b;
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            a.emplace_back(temp);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            b.emplace_back(temp);
        }
        long long product = minimumProduct(a, b);
        printf("Case #%d: %lld\n", t, product);
    }
    return 0;
}
