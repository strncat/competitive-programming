//
//  main.cpp
//  uhunt
//
//  10067 - Playing with Wheels
//  2017/03/16
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using std::string;
using std::vector;
using std::pair;
using std::unordered_map;

string read_num() {
    int d1, d2, d3, d4;
    scanf("%d %d %d %d", &d1, &d2, &d3, &d4);
    string s = std::to_string(d1) + std::to_string(d2) + std::to_string(d3) + std::to_string(d4);
    return s;
}

int bfs(vector<string>& forbidden, string& initial, string& dest) {
    std::queue<string> q;
    unordered_map<string, bool> visited;
    unordered_map<string, int> distance;

    q.push(initial);
    bool forb = false;

    while (!q.empty()) {
        string num = q.front();
        q.pop();

        if (num == dest) {
            return distance[num];
        }

        for (int i = 0; i < forbidden.size(); i++) {
            if (forbidden[i] == num) {
                forb = true;
                break;
            }
        }

        if (forb) {
            forb = false;
            continue;
        }

        for (int i = 0; i < 4; i++) {
            // change ith digit

            // (1) add
            string new_num = num;
            if (new_num[i] == '9') {
                new_num[i] = '0';
            } else {
                new_num[i] = new_num[i]+1;
            }

            if (visited.find(new_num) == visited.end()) {
                visited[new_num] = true;
                q.push(new_num);
                distance[new_num] = distance[num] + 1;
            }

            // (2) subtract
            new_num = num;
            if (new_num[i] == '0') {
                new_num[i] = '9';
            } else {
                new_num[i] = new_num[i]-1;
            }
            if (visited.find(new_num) == visited.end()) {
                visited[new_num] = true;
                q.push(new_num);
                distance[new_num] = distance[num] + 1;
            }
        }
    }
    return -1;
}

int main() {
    freopen("sample.in", "r", stdin);

    int f, t;
    scanf("%d\n", &t);

    while (t--) {
        string initial = read_num();
        string dest = read_num();

        vector<string> forbidden;
        scanf("%d", &f);
        for (int i = 0; i < f; i++) {
            string d = read_num();
            forbidden.push_back(d);
        }

        int c = bfs(forbidden, initial, dest);
        if (c >= 0) { printf("%d\n", c); }
        else { printf("-1\n"); }
    }
    return 0;
}
