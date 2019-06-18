//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/17/19.
//  429 - Word Transformation
//

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <sstream>

#define MAX 10000

std::unordered_map<std::string, std::string> parent;
std::vector<std::string> dict;
std::vector<std::string> words;

std::unordered_map<std::string, int> indices;
std::vector<std::vector<std::string>> g;

// count the number of nodes on the optimal path from s to f
int count(std::string f, std::string s) {
    int total = 0;
    while (f != s) {
        total++;
        f = parent[f];
    }
    return total;
}

// return true if the two words diff by only 1 character, could be optimized
bool diff_by_one(std::string w1, std::string w2) {
    int total = 0;
    size_t w1s = w1.size(), w2s = w2.size();
    if (w1s > w2s) {
        std::string tmp = w1;
        w1 = w2;
        w2 = tmp;
    }
    for (int i = 0; i < w1s; i++) {
        if (w1[i] != w2[i]) {
            total++;
        }
        if (total > 1) { return false; }
    }
    total += w2s - w1s;
    return total > 1 ? false : true;
}

// build the graph by inserting edges if any two words differ by 1 in the dictionary
void preprocess() {
    size_t size = dict.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            // consider every pair of words in the dictionary
            if (diff_by_one(dict[i], dict[j])) {
                // if two words differ by at most 1, then we insert an edge
                // undirected so i-j and j-i
                g[i].push_back(dict[j]);
                g[j].push_back(dict[i]);
            }
        }
    }
}

// assuming start is a valid point
int bfs(std::string start, std::string end) {
    if (start == end) { return 1; }

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
    return -1;
}

// read the input, my least favorite part agh :(
void read() {
    std::string w;
    int i = 0;
    while (1) {
        std::cin >> w;
        dict.push_back(w);
        if (w[0] == '*') { break; }
        indices[w] = i++;
        g.push_back(std::vector<std::string>());
    }

    std::string line, start, end;
    std::getline(std::cin, line); // newline
    while (1) {
        std::getline(std::cin, line);
        if (line == "") { break; }
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
        dict.clear();
        g.clear();
        indices.clear();

        // read the input
        read();

        // build the graph
        preprocess();

        // answer each query by performing a bfs
        for (int i = 0; i < words.size(); i+=2) {
            int t = bfs(words[i], words[i+1]);
            printf("%s %s %d\n", words[i].c_str(), words[i+1].c_str(), t);
        }
        if (tests) {
            printf("\n");
        }
    }
}
