//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/18/19.
//  388 Galactic Import
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>
#include <algorithm>
#include <limits.h>

std::vector<std::vector<char>> g;
std::vector<char> planets;
double values[100];


// count the number of nodes on the optimal path from s to f
int calculate_cost(int *parent, char f, double initial_cost) {
    double cost = initial_cost;
    f = parent[f];
    while (f != -1) {
        cost -= (cost*0.05);
        f = parent[f];
    }
    return cost;
}

// assuming start is a valid point
int bfs(char start, char end) {
    std::queue<char> q;
    bool visited[100] = {false};
    int parent[100];

    // first node
    q.push(start);
    visited[start] = true;
    parent[start] = -1;

    // classic bfs, nothing special, exit when we pop the final node
    // could obviously optimize by checking early for the final node
    while(!q.empty()) {
        char cur = q.front();
        q.pop();

        if (cur == end) {
            return calculate_cost(parent, cur, values[start]);
        }

        // go through all neighbors
        for (int i = 0; i < g[cur].size(); i++) {
            char next = g[cur][i];
            if (!visited[next]) {
                visited[next] = true;
                q.push(next);
                parent[next] = cur;
            }
        }
    }
    return -1;
}

// add an edge between the two cities
void add_edge(char start, char end) {
    g[start].push_back(end);
}

// read the input, my least favorite part agh :(
void read_graph() {
    int n;
    scanf("%d\n", &n);

    for (int i = 0; i < 100; i++) {
        g.push_back(std::vector<char>());
    }

    // nodes
    std::string line, value, neighbors;
    char planet;
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, line);
        if (line.size() == 0) { return; } //hack af
        std::istringstream iss(line);
        iss >> planet >> value >> neighbors;
        // multiply by a 100
        int cost = (value[0]-'0')*10000 + (value[2]-'0')*1000 + (value[3]-'0')*100;
        values[planet] = cost;
        planets.push_back(planet);

        for (int j = 0; j < neighbors.size(); j++) {
            add_edge(planet, neighbors[j]);
            add_edge(neighbors[j], planet);
        }
    }
}

void reset_state() {
    // clear all global vectors/maps etc
    planets.clear();
    g.clear();
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    while (1) {
        reset_state();
        read_graph();

        if (planets.size() == 0) { break; } // hack af

        double max_value = -1.0;
        std::string max_planet = "";
        std::sort(planets.begin(), planets.end());
        for (int i = 0; i < planets.size(); i++) {
            // perform a bfs from every planet in the galaxy to Eart
            double cur_value = bfs(planets[i], '*'); // from every node to earth
            if (cur_value > max_value) {
                max_value = cur_value;
                max_planet = planets[i];
            }
        }
        printf("Import from %s\n", max_planet.c_str());
    }

    return 0;
}
