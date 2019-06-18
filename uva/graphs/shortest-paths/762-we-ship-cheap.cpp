//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/18/19.
//  762 - We Ship Cheap
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

#define MAX 10000

std::unordered_map<std::string, std::string> parent;
std::vector<std::string> queries;
std::unordered_map<std::string, int> indices;
std::vector<std::vector<std::string>> g;
int counter;

// count the number of nodes on the optimal path from s to f
std::vector<std::string> count(std::string f, std::string s) {
    std::vector<std::string> path;
    while (f != s) {
        std::string edge = parent[f];
        edge.append(" ").append(f);
        path.push_back(edge);
        f = parent[f];
    }
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
std::vector<std::string> bfs(std::string start, std::string end) {
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
    return std::vector<std::string>();
}

void insert_node(std::string word) {
    if (indices.find(word) == indices.end()) {
        indices[word] = counter++;
        g.push_back(std::vector<std::string>());
    }
}

// read the input, my least favorite part agh :(
void read() {
    int n;
    scanf("%d\n", &n);

    std::string line, start, end;
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);
        if (line == "") { return; } // agh hack
        std::istringstream iss(line);
        iss >> start >> end;

        // insert node in the graph, if seen for the first time
        insert_node(start);
        insert_node(end);

        // create an edge between the two cities
        add_edge(start, end);
    }

    // read queries (only one for this problem)
    std::getline(std::cin, line);
    std::istringstream iss(line);
    iss >> start >> end;
    insert_node(start);
    insert_node(end);
    queries.push_back(start);
    queries.push_back(end);
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    bool first = true;

    while (1) {
        // clear all global vectors/maps etc
        parent.clear();
        queries.clear();
        g.clear();
        indices.clear();
        counter = 0;

        // read the input
        read();

        if (g.empty()) { break; }

        if (first) {
            first = false;
        } else {
            printf("\n");
        }

        // answer each query by performing a bfs
        for (int i = 0; i < queries.size(); i+=2) {
            std::vector<std::string> path = bfs(queries[i], queries[i+1]);
            if (path.size() == 0) {
                printf("No route\n");
            } else {
                for (long j = path.size()-1; j >= 0; j--) {
                    printf("%s\n", path[j].c_str());
                }
            }
        }
    }
}
