//
//  main.cpp
//  uhunt
//
//  10205 Stack ’em Up
//  2017/03/20
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <string.h>

using std::string;
using std::vector;
using std::unordered_map;

int main() {
    //freopen("sample.in", "r", stdin);

    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--) {
        unordered_map<int, string> a;
        unordered_map<int, string> b;

        vector<string> suit = {"Clubs", "Diamonds", "Hearts", "Spades"};
        vector<string> value = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};

        int index = 1;
        for (int i = 0; i < suit.size(); i++) {
            for (int j = 0; j < value.size(); j++) {
                a[index++] = value[j] + " of " + suit[i];
            }
        }

        int n, x;
        scanf("%d", &n);
        vector<vector<int>> shuffles;
        for (int i = 0; i < n; i++) {
            shuffles.push_back(vector<int>());
            for (int j = 0; j < 52; j++) {
                scanf("%d", &x);
                shuffles[i].push_back(x);
            }
        }

        vector<int> ks;
        string line;
        std::cin.ignore();
        getline(std::cin, line);
        while (line != "") {
            std::stringstream ss;
            ss << line;
            ss >> x;
            ks.push_back(x);
            std::getline(std::cin, line);
        }

        for (int k = 0; k < ks.size(); k++) {
            int s = ks[k]-1;

            for (int i = 0; i < 52; i++) {
                string t = a[shuffles[s][i]];
                b[i+1] = t;
            }
            for (int i = 1; i <= 52; i++) {
                a[i] = b[i];
            }
        }

        for (int i = 1; i <= 52; i++) {
            printf("%s\n", a[i].c_str());
        }

        if (test_cases) {
            printf("\n");
        }
    }
    return 0;
}
