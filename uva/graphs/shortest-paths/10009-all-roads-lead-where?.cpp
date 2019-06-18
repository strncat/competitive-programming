//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/18/19.
//  10009 - All Roads Lead Where?
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

#define MAX 10000

std::unordered_map<std::string, std::string> parent;
std::vector<std::string> words;
std::unordered_map<std::string, int> indices;
std::vector<std::vector<std::string>> g;

// count the number of nodes on the optimal path from s to f
std::string count(std::string f, std::string s) {
    std::string path;
    while (f != s) {
        path.push_back(toupper(f[0]));
        f = parent[f];
    }
    path.push_back(toupper(f[0])); // add the start too
    return path;
}

// add an edge between the two cities
void add_edge(std::string start, std::string end) {
    int i = indices[start];
    int j = indices[end];
    g[i].push_back(end);
    g[j].push_back(start);
}

// assuming start is a valid point
std::string bfs(std::string start, std::string end) {
    std::queue<std::string> q;
    std::unordered_map<std::string, bool> visited;

    // first node
    q.push(start);
    visited[start] = true;

    // classic bfs, nothing special, exit when we pop the final node
    // could obviously optimize by checking early for the final node
    while(!q.empty()) {
        std::string cur = q.front();
        q.pop();

        if (cur == end) {
            return count(cur, start);
        }

        // go through all neighbors
        int index = indices[cur];
        for (int i = 0; i < g[index].size(); i++) {
            std::string next = g[index][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                parent[next] = cur;
            }
        }
    }
    return "";
}

// read the input, my least favorite part agh :(
void read() {
    int n, q;
    scanf("%d %d\n", &n, &q);

    std::string line, start, end;
    int index = 0;
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> start >> end;

        // create a new list of neighbors if it's seen for the first time
        if (indices.find(start) == indices.end()) {
            indices[start] = index++;
            g.push_back(std::vector<std::string>());
        }

        if (indices.find(end) == indices.end()) {
            indices[end] = index++;
            g.push_back(std::vector<std::string>());
        }

        // create an edge between the two cities
        add_edge(start, end);
    }

    // read queries
    for (int i = 0; i < q; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> start >> end;
        words.push_back(start);
        words.push_back(end);
    }
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    int tests;
    scanf("%d\n", &tests);

    while (tests--) {
        // clear all global vectors/maps etc
        parent.clear();
        words.clear();
        g.clear();
        indices.clear();

        // read the input
        read();

        // answer each query by performing a bfs
        for (int i = 0; i < words.size(); i+=2) {
            std::string path = bfs(words[i], words[i+1]);
            std::reverse(path.begin(),path.end());
            printf("%s\n", path.c_str());
        }
        if (tests) {
            printf("\n");
        }
    }
}
