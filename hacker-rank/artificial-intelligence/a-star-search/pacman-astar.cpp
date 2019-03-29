//
//  PacMan - BFS
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

struct compare_pair {
public:
    bool operator()(std::pair<Point,int> a, std::pair<Point,int> b) {
        return a.second>b.second;
    }
};

struct point_hash {
public:
    std::size_t operator()(const Point &a) const {
        return std::hash<int>()(a.x) ^ std::hash<int>()(a.y);
    }
};

int manhattan_distance(Point a, Point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

void a_star(std::vector<std::string> grid, int r, int c, int px, int py, int fx, int fy) {

    std::priority_queue<std::pair<Point,int>, std::vector<std::pair<Point,int>>, compare_pair> s;
    bool visited[50][50] = {false};
    std::unordered_map<Point, Point, point_hash> parent;
    std::stack<Point> path;
    Point goal;

    // first node
    Point p(px, py);
    s.push(std::make_pair(p, 0));
    visited[px][py] = true;
    parent[p] = Point(-1,-1);

    while (!s.empty()) {
        std::pair<Point,int> e = s.top();
        s.pop();

        // if this is the goal node, stop
        if (grid[e.first.x][e.first.y] == '.') { // found food
            goal.x = e.first.x;
            goal.y = e.first.y;
            break;
        }

        // left => down => right => up
        int offset[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
        for (int i = 0; i < 4; ++i) {
            Point next(e.first.x + offset[i][0], e.first.y + offset[i][1]);
            if (next.x >= 0 && next.x < r &&
                next.y >= 0 &&
                next.y < c &&
                !visited[next.x][next.y] &&
                grid[next.x][next.y] != '%') {

                visited[next.x][next.y] = true;
                parent[next] = e.first;
                int cost = manhattan_distance(next, e.first);
                s.push(std::make_pair(next, cost + 1));
            }
        }
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
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%",
        "%-------%-%-%-----------%---%-----%-%",
        "%-%%%%%%%-%-%%%-%-%%%-%%%-%%%%%%%-%-%",
        "%-------%-------%-%-----%-----%-%---%",
        "%%%%%-%%%%%-%%%-%-%-%-%%%-%%%%%-%-%%%",
        "%---%-%-%-%---%-%-%-%---%-%---%-%---%",
        "%-%%%-%-%-%-%%%-%%%%%-%%%-%-%%%-%%%-%",
        "%-------%-----%---%---%-----%-%-%---%",
        "%%%-%%%%%%%%%-%%%%%%%-%%%-%%%-%-%-%-%",
        "%-------------%-------%-%---%-----%-%",
        "%-%-%%%%%-%-%%%-%-%-%%%-%-%%%-%%%-%-%",
        "%-%-%-----%-%-%-%-%-----%---%-%-%-%-%",
        "%-%-%-%%%%%%%-%-%%%%%%%%%-%%%-%-%%%-%",
        "%-%-%-%-----%---%-----%-----%---%---%",
        "%%%-%%%-%-%%%%%-%%%%%-%%%-%%%-%%%%%-%",
        "%-----%-%-%-----%-%-----%-%---%-%-%-%",
        "%-%-%-%-%-%%%-%%%-%%%-%%%-%-%-%-%-%-%",
        "%-%-%-%-%-----------------%-%-%-----%",
        "%%%-%%%%%%%-%-%-%%%%%-%%%-%-%%%-%%%%%",
        "%-------%-%-%-%-----%---%-----%-%---%",
        "%%%%%-%-%-%%%%%%%%%-%%%%%%%%%%%-%-%%%",
        "%---%-%-----------%-%-----%---%-%---%",
        "%-%%%-%%%%%-%%%%%%%%%-%%%%%-%-%-%%%-%",
        "%-%---%------%--------%-----%-------%",
        "%-%-%-%%%%%-%%%-%-%-%-%-%%%%%%%%%%%%%",
        "%-%-%---%-----%-%-%-%-------%---%-%-%",
        "%-%-%%%-%%%-%-%-%-%%%%%%%%%-%%%-%-%-%",
        "%-%---%-%---%-%-%---%-%---%-%-%-----%",
        "%-%%%-%%%-%%%%%-%%%-%-%-%%%%%-%-%%%%%",
        "%-------%---%-----%-%-----%---%-%---%",
        "%%%-%-%%%%%-%%%%%-%%%-%%%-%-%%%-%-%%%",
        "%-%-%-%-%-%-%-%-----%-%---%-%---%-%-%",
        "%-%-%%%-%-%-%-%-%%%%%%%%%-%-%-%-%-%-%",
        "%---%---%---%-----------------%-----%",
        "%-%-%-%-%%%-%%%-%%%%%%%-%%%-%%%-%%%-%",
        "%.%-%-%-------%---%-------%---%-%--P%",
        "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"};
    a_star(grid, 37, 37, 35, 35, 35, 1);
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
    a_star(grid, r, c, x, y, fx, fy);
    return 0;
}
