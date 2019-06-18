//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/18/19.
//  383 Shipping Routes
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>

std::unordered_map<std::string, std::string> parent;
std::vector<std::string> queries;
std::unordered_map<std::string, int> indices;
std::vector<std::vector<std::string>> g;
int counter;

// count the number of nodes on the optimal path from s to f
int calculate_cost(std::string f, std::string s, int num) {
    int cost = num * 100;
    int total = 0;
    while (f != s) {
        total++;
        f = parent[f];
    }
    return cost * total;
}

// assuming start is a valid point
int bfs(std::string start, std::string end, int num) {
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
            return calculate_cost(cur, start, num);
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
    return -1;
}

void insert_node(std::string word) {
    if (indices.find(word) == indices.end()) {
        indices[word] = counter++;
        g.push_back(std::vector<std::string>());
    }
}

// add an edge between the two cities
void add_edge(std::string start, std::string end) {
    int i = indices[start];
    int j = indices[end];
    g[i].push_back(end);
    g[j].push_back(start);
}

// read the input, my least favorite part agh :(
void read_graph(int m, int n) {
    // nodes
    std::string line, node;
    std::getline(std::cin, line); // all nodes
    std::istringstream iss(line);
    for (int i = 0; i < m; i++) {
        iss >> node;
        insert_node(node);
    }

    // edges
    std::string start, end;
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);
        std::istringstream iss(line);
        iss >> start >> end;
        insert_node(start);
        insert_node(end);
        add_edge(start, end);
    }
}

void reset_state() {
    // clear all global vectors/maps etc
    parent.clear();
    queries.clear();
    g.clear();
    indices.clear();
    counter = 0;
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    int tests;
    int test = 1;
    scanf("%d", &tests);

    printf("SHIPPING ROUTES OUTPUT\n\n");

    while (tests--) {
        reset_state();

        printf("DATA SET  %d\n\n", test++);

        // read graph input
        int n, m, p;
        scanf("%d %d %d\n", &m, &n, &p);
        read_graph(m, n);

        // answer each query by performing a bfs
        std::string line, start, end;
        int num;
        for (int i = 0; i < p; i++) {
            std::getline(std::cin, line);
            std::istringstream iss(line);
            iss >> num >> start >> end;
            // maybe I don't need this, if all requests are guaranteed to be valid
            insert_node(start);
            insert_node(end);

            int t = bfs(start, end, num);
            if (t == -1) {
                printf("NO SHIPMENT POSSIBLE\n");
            } else {
                printf("$%d\n",t);
            }
        }

        printf("\n");
    }

    printf("END OF OUTPUT\n");
    return 0;
}
