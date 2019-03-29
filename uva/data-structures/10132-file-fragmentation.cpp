//
//  main.cpp
//  uhunt
//
//  10132 - File Fragmentation
//  2017/03/21
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <math.h>
#include <queue>

using std::string;
using std::vector;
using std::unordered_map;


int main() {
    //freopen("sample.in", "r", stdin);

    int test_cases;
    scanf("%d\n", &test_cases);

    while(test_cases--) {
        unordered_map<int, vector<string>> m;
        vector<int> lengths;
        string line;

        while (getline(std::cin, line)) {
            if (line == "") { break; }

            int len = (int)line.size();

            if (m.find(len) == m.end()) {
                m[len] = vector<string>();
                lengths.push_back(len);
            }
            m[len].push_back(line);
        }

        std::sort(lengths.begin(), lengths.end());

        int size = (int)lengths.size();
        unordered_map<string, int> f;

        for (int i = 0; i <= size/2; i++) {
            int low = lengths[i];
            int high = lengths[size-1-i];

            for (int j = 0; j < m[low].size(); j++) {
                for (int k = 0; k < m[high].size(); k++) {
                    string t = m[low][j] + m[high][k];

                    if (f.find(t) == f.end()) {
                        f[t] = 1;
                    } else {
                        f[t]++;
                    }
                }
            }
        }
        int max = 0;
        string max_s = "";
        for (auto i = f.begin(); i != f.end(); i++) {
            if (i->second > max) {
                max = i->second;
                max_s = i->first;
            }
        }
        printf("%s\n", max_s.c_str());

        if (test_cases) {
            printf("\n");
        }
    }
    return 0;
}
