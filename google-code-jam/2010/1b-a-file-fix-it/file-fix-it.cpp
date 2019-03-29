//
// Google Code Jam 2010
// Round 1B: File Fix-it
//

#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>

class Vertex {
public:
    std::vector<Vertex*> children;
    std::string name;
    int depth;
    Vertex(std::string name, int depth) {
        this->name = name;
        this->depth = depth;
    }
    void insertChild(Vertex *x) {
        children.push_back(x);
    }
};

Vertex* search(Vertex *root, std::string name, int depth) {
    if (root == NULL) { return NULL; }
    if (root->name == name && root->depth == depth) { return root; }

    for (auto c = root->children.begin(); c != root->children.end(); c++) {
        Vertex *r = search(*c, name, depth);
        if (r != NULL) { return r; }
    }
    return NULL;
}

int main() {
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    int tests, exist, create;
    std::string path;
    scanf("%d", &tests);

    for (int t = 1; t <= tests; t++) {
        scanf("%d %d", &exist, &create);
        Vertex *root = new Vertex("root", 0);

        for (int i = 0; i < exist; i++) {
            std::cin >> path;
            std::istringstream stream(path);
            std::string token;
            Vertex *temp = root;
            int depth = 1;

            while(getline(stream, token, '/')) { // split around /
                if (token == "") { continue; }
                Vertex *r = search(temp, token, depth);
                if (r == NULL) { // doesn't exist yet
                    Vertex *v = new Vertex(token, depth);
                    temp->insertChild(v);
                    temp = v;
                } else {
                    temp = r;
                }
                depth++;
            }
        }
        int mkdir = 0;
        for (int i = 0; i < create; i++) {
            std::cin >> path;
            std::istringstream stream(path);
            std::string token;
            Vertex *temp = root;
            int depth = 1;

            while(getline(stream, token, '/')) { // split around /
                if (token == "") { continue; }
                Vertex *r = search(temp, token, depth);
                if (r == NULL) { // doesn't exist yet
                    Vertex *v = new Vertex(token, depth);
                    temp->insertChild(v);
                    temp = v;
                    mkdir++;
                    //std::cout << "creating new folder " << token << std::endl;
                } else {
                    temp = r;
                }
                depth++;
            }
        }
        printf("Case #%d: %d\n", t, mkdir);
    }

    return 0;
}
