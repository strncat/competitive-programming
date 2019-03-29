//
//  main.cpp
//  uhunt
//
//  11917 - Do Your Own Homework
//  2017/02/07
//

#include <iostream>
#include <unordered_map>

int main() {
    //freopen("sample.in", "r", stdin);
    int n, test_cases, d, D;
    std::unordered_map<std::string, int> m;
    std::string s;

    scanf("%d", &test_cases);

    for (int t = 1; t <= test_cases; t++) {
        m.clear();
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            std::cin >> s >> d;
            m[s] = d;
        }

        std::cin >> D >> s;
        std::unordered_map<std::string, int>::iterator i = m.find(s);
        if (i == m.end() || i->second > D + 5) {
            printf("Case %d: Do your own homework!\n", t);
        } else if (D >= i->second) {
            printf("Case %d: Yesss\n", t);
        } else {
            printf("Case %d: Late\n", t);
        }
    }
    return 0;
}
