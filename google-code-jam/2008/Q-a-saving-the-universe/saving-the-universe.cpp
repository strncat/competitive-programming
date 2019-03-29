//
// Google Code Jam 2008
// Problem A. Saving the Universe
//

#include <iostream>
#include <stdio.h>
#include <unordered_set>
#include <vector>

int main() {
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    int tests, S, Q;
    scanf("%d", &tests);

    for (int t = 1; t <= tests; t++) {
        int switches = 0;

        scanf("%d\n", &S);
        std::unordered_set<std::string> engines; // asumming engines are unique!
        std::string q;
        for (int i = 0; i < S; i++) {
            getline(std::cin, q);
            engines.insert(q);

        }
        // another simpler solution would to have a simple map seen, mark
        // words seen / unseen instead of creating a set every single time
        scanf("%d\n", &Q);
        std::vector<std::string> keywords;
        std::unordered_set<std::string> enginesCopy = std::unordered_set<std::string>(engines);
        for (int i = 0; i < Q; i++) {
            getline(std::cin, q);
            auto result = enginesCopy.find(q);
            if (result != enginesCopy.end()) { enginesCopy.erase(result); }
            if (enginesCopy.size() < 1) {
                switches++; // have to use this engine for all previous queries
                enginesCopy = std::unordered_set<std::string>(engines); // reset engines
                auto result = enginesCopy.find(q); // need to remove it
                enginesCopy.erase(result); // remove it too
            }

        }
        printf("Case #%d: %d\n", t, switches);
    }
    return 0;
}
