//
// 793 - Network Connections
// 20150401
//

#include <iostream>
#include <sstream>
#include <cstdio>

class UnionFind {
public:
    int *leader;
    int n;
    int count;

    UnionFind(int n) {
        this->n = n;
        count = n; // initially the number of components is n
        leader = new int[n];
        for (int i = 0; i < n; i++) {
            leader[i] = i; // each item is in its own component
        }
    }

    int findOP(int x) { // constant time to find the leader of x
        return leader[x];
    }

    bool connected(int x, int y) {
        return leader[x] == leader[y];
    }

    void unionOP(int x, int y) { // union takes linear time
        if (connected(x, y)) return;
        int l = leader[x];
        for (int i = 0; i < n; i++) { // convert anyone under l to be under leader[y]
            if (leader[i] == l) {
                leader[i] = leader[y];
            }
        }
        count--;
    }
};

int main() {

    bool newline = false;
    int tests;
    std::cin >> tests;

    while (tests--) {
        // new line crap
        if (newline) {
            std::cout << std::endl;
        }
        newline = true;

        // init based on the size of the network
        int n;
        std::cin >> n;
        std::cin.ignore(); // aghhhhh
        UnionFind uf(n + 1);

        // connections and questions
        int answered = 0, unanswered = 0;
        for (std::string s; getline(std::cin, s) && !s.empty();) {
            std::stringstream sin(s);
            char c; sin >> c;
            int a, b; sin >> a >> b;
            if (c == 'c') {
                uf.unionOP(a, b); // merge if possible

            } else {
                if (uf.connected(a, b) == true) {
                    answered++;
                } else {
                    unanswered++;
                }
            }
        }
        printf("%d,%d\n", answered, unanswered);
    }
    return 0;
}
