//
//  main.cpp
//  uhunt
//
//  10150 - Doublets
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

vector<string> dictionary;
vector<vector<int>> g;
unordered_map<string,int> m;
int parent[30000];

bool bfs(int start, int end) {
    bool visited[30000] = {false};
    for (int i = 0; i < 30000; i++) {
        parent[i] = -1;
    }

    std::queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if (v == end) {
            return true;
        }

        for (int i = 0; i < g[v].size(); i++) {
            if (!visited[g[v][i]]) {
                visited[g[v][i]] = true;
                parent[g[v][i]] = v;
                q.push(g[v][i]);
            }
        }
    }
    return false;
}

vector<string> construct_path(int start, int end) {
    vector<string> path;
    while (end != start) {
        path.push_back(dictionary[end].c_str());
        end = parent[end];
    }
    path.push_back(dictionary[end].c_str());
    return path;
}

bool is_doublet(string a, string b, int len) {
    int diff = 0;
    for (int i = 0; i < len; i++) {
        if (a[i] != b[i]) { diff++; }
        if (diff > 1) {
            return false;
        }
    }
    return true;
}

int main() {
    //freopen("sample.in", "r", stdin);

    // read dictionary
    int index = 0;
    string line;
    while (getline(std::cin, line)) {
        if (line == "") { break; }
        dictionary.push_back(line);
        g.push_back(vector<int>());
        m[line] = index++;

    }

    // create links
    for (int i = 0; i < dictionary.size(); i++) {
        for (int j = i + 1; j < dictionary.size(); j++) {

            // there is no point of checking if two words are doublets if they are not of the same length
            int a = (int)dictionary[i].size(), b = (int)dictionary[j].size();
            if (a != b) { continue; }

            // only check when they are of the same length
            if (is_doublet(dictionary[i], dictionary[j], a)) {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    // read pairs
    string start, end;
    int newline = 0;
    while (std::cin >> start >> end) {
        if (newline) {
            printf("\n");
        }
        newline++;

        if ((start.size() != end.size()) || m.find(start) == m.end() || m.find(end) == m.end()) {
            printf("No solution.\n");
            continue;
        }

        if (bfs(m[start], m[end])) {
            vector<string> path = construct_path(m[start], m[end]);
            for (int i = (int)path.size()-1; i >= 0; i--) {
                std::cout << path[i] << std::endl;
            }
        } else {
            printf("No solution.\n");
        }
    }
    return 0;
}
