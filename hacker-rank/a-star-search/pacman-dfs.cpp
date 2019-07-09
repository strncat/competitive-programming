//
//  PacMan - DFS
//
//  Created by Fatima B on 10/6/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>

struct Point {
    int x;
    int y;
    Point() {x=-10; y=-10;}
    Point(int a, int b) {
        x = a;
        y = b;
    }
    bool operator==(const Point &a) const {
        return x == a.x && y == a.y;
    }
};

struct point_hash {
public:
    std::size_t operator()(const Point &a) const {
        return std::hash<int>()(a.x) ^ std::hash<int>()(a.y);
    }
};

void dfs(std::vector<std::string> grid, int r, int c, int px, int py, int fx, int fy) {
    std::stack<Point> s; // ONLY DIFFERENCE BETWEEN QUEUE AND STACK

    bool visited[50][50] = {false};
    std::unordered_map<Point, Point, point_hash> parent; // PARENT ARRAY
    std::stack<Point> path;
    std::vector<Point> explored;
    Point goal;

    // first node
    Point p(px, py);
    s.push(p);
    visited[px][py] = true;
    parent[p] = Point(-1,-1); // root node

    while (!s.empty()) {
        Point e = s.top();
        s.pop();

        // add the node to the explored nodes so far
        explored.push_back(e);

        // if this is the goal node, stop
        if (grid[e.x][e.y] == '.') { // found food
            goal.x = e.x;
            goal.y = e.y;
            break;
        }

        // left => down => right => up
        int offset[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for (int i = 0; i < 4; ++i) {

            Point next(e.x + offset[i][0], e.y + offset[i][1]);

            if (next.x >= 0 && next.x < r && next.y >= 0 && next.y < c // WITHIN BOUNDARIES
                && !visited[next.x][next.y] // NOT VISITED YET
                && grid[next.x][next.y] != '%') { // NOT WALL

                visited[next.x][next.y] = true; // mark it
                parent[next] = e; // set the parent
                s.push(next); // push it on the stack
            }
        }
    }

    // PRINT ALL THE EXPLORED NODES
    printf("%d\n", (int) explored.size());
    for (auto i = explored.begin(); i != explored.end(); i++) {
        printf("%d %d\n", i->x, i->y);
    }


    // CONSTRUCT THE ROUTE USING THE PARENT ARRAY
    path.push(goal);
    while (goal.x != -1) {
        goal = parent[goal];
        path.push(goal);
    }

    // PRINT THE ACTUAL ROUTE
    path.pop();
    printf("%d\n", (int) path.size()-1);
    while (!path.empty()) {
        Point e = path.top();
        path.pop();
        printf("%d %d\n", e.x, e.y);
    }
}

void tests() {
    std::vector<std::string> grid = {
        "%%%%%%%%%%%%%%%%%%%%",
        "%--------------%---%",
        "%-%%-%%-%%-%%-%%-%-%",
        "%--------P-------%-%",
        "%%%%%%%%%%%%%%%%%%-%",
        "%.-----------------%",
        "%%%%%%%%%%%%%%%%%%%%"};
    dfs(grid, 7, 20, 3, 9, 5, 1);
}

int main() {
    //tests();
    int x, y, fx, fy, r, c;
    std::vector<std::string> grid;
    scanf("%d %d", &x, &y);
    scanf("%d %d", &fx, &fy);
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++) {
        std::string s; std::cin >> s;
        grid.push_back(s);
    }
    dfs(grid, r, c, x, y, fx, fy);
    return 0;
}
