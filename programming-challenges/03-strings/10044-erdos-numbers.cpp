//
//  main.cpp
//  uhunt
//
//  10044 - Erdos Numbers
//  2017/02/10
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <set>

using std::string;
using std::vector;
using std::unordered_map;
using std::set;

unordered_map<int,set<int>> graph;
unordered_map<string, int> m;

int bfs(int a) {
    if (graph.find(a) == graph.end()) {
        return -1;
    }

    std::unordered_map<int, bool> visited;
    for (auto i = graph.begin(); i != graph.end(); i++) {
        visited[i->first] = false;
    }
    visited[a] = true;
    std::queue<int> q;
    std::queue<int> l;
    q.push(a);
    int level = 0;
    l.push(level);

    while(q.size()) {
        int cur = q.front();
        level = l.front();
        q.pop();
        l.pop();
        if (cur == 0) { // "Erdos, P." success
            return level;
        }
        // examine connections;
        set<int> connections = graph[cur];
        for (auto i = connections.begin(); i != connections.end(); i++) {
            if (visited[*i] == false) {
                visited[*i] = true;
                q.push(*i);
                l.push(level+1);
            }
        }
    }
    return -1;
}

int main() {
    //freopen("sample.in", "r", stdin);
    int test_cases, p, n;
    vector<int> authors; // authors in the current paper
    string line, author;
    scanf("%d\n", &test_cases);

    for (int t = 1; t <= test_cases; t++) {
        scanf("%d %d\n", &p, &n);

        graph.clear();
        m.clear();
        int index = 0;
        m["Erdos, P."] = index++;

        for (int i = 0; i < p; i++) { // for each paper
            std::getline(std::cin, line);
            authors.clear();
            string name = "";

            // Erdos, P., Lfliesgdqus, N.E., Wagzoqxymo, V., Wfejhygi, A.G.:

            int j = 0;
            int size = (int)line.size();

            // this section will sure give a TLE if not done right
            while (j < size) {
                while (j < size && line[j] == ' ') { j++; } // get rid of spaces
                while (j < size && line[j] != ',') { name += line[j]; j++; } // read first part
                if (j >= size) { break; } // without this line => TLE not even runtime error or wrong answer

                name += line[j++]; // take the first comma

                // continue reading until second comma or end of paper
                while (j < size && line[j] != ',' && line[j] != ':') { name += line[j]; j++; }

                if (m.find(name) == m.end()) { m[name] = index++; }
                authors.push_back(m[name]);
                name = "";

                j++; // skip the second comma comma
            }
 
            // make connections
            for (int j = 0; j < authors.size(); j++) {
                for (int k = j+1; k < authors.size(); k++) {
                    graph[authors[j]].insert(authors[k]);
                    graph[authors[k]].insert(authors[j]);
                }
            }
        }

        printf("Scenario %d\n", t);
        for (int i = 0; i < n; i++) {
            std::getline(std::cin, author);
            if (m.find(author) == m.end()) { // annoying some authors might not be in the graph at all
                std::cout << author << " " << "infinity" << std::endl; // agh
            } else {
                int level = bfs(m[author]);
                if (level != -1) {
                    std::cout << author << " " << level << std::endl;
                } else {
                    std::cout << author << " " << "infinity" << std::endl; // agh
                }
            }
        }
    }
    return 0;
}