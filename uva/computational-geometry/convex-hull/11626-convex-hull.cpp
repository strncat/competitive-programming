//
//  main.cpp
//  uva
//
//  Created by FB on 9/6/23.
//  Based on https://cp-algorithms.com/geometry/convex-hull.html
//  11626 - Convex Hull
//  https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2673
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<long long>> jarvis(std::vector<std::vector<long long>>& points);

struct Point {
    long long x, y;
};

int orientation(Point a, Point b, Point c) {
    long long area = (b.x - a.x)*(c.y - a.y) - (c.x - a.x)*(b.y - a.y);
    if (area < 0) {
        return -1; // cw
    } else if (area > 0) {
        return 1; // ccw
    }
    return 0;
}

bool strict_left(Point a, Point b, Point c) {
    long long area = orientation(a, b, c);
    return area > 0;
}

bool left(Point a, Point b, Point c) {
    long long area = orientation(a, b, c);
    return area >= 0;
}

bool strict_right(Point a, Point b, Point c) {
    long long area = orientation(a, b, c);
    return area < 0;
}

bool right(Point a, Point b, Point c) {
    long long area = orientation(a, b, c);
    return area <= 0;
}

long long distance(Point a, Point b) {
    return (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
}

bool collinear(Point a, Point b, Point c) { 
    return orientation(a, b, c) == 0;
}

void graham_scan(std::vector<Point>& points) {
    // step 1: pick the left most element as the starting point
    Point left_most = points[0];
    for (int i = 1; i < points.size(); i++) {
        if (points[i].x < left_most.x || (points[i].x == left_most.x && points[i].y < left_most.y)) {
            left_most = points[i];
        }
    }

    // step 2: sort the remaining points around left_most by angle while breaking ties by distance
    //
    sort(points.begin(), points.end(), [&left_most](const Point& a, const Point& b) {
        int d = orientation(left_most, a, b);
        if (d > 0) { // ccw
            return true;
        } else if (d == 0) { // collinear
            return distance(a, left_most) < distance(left_most, b);
        }
        return false;
    });

    int i = (int)points.size()-1;
    while (i >= 0 && collinear(left_most, points[i], points.back())) {
        i--;
    }
    reverse(points.begin()+i+1, points.end());

    std::vector<Point> stack;
    // The first two vertices are guaranteed to be on the hull
    stack.push_back(left_most);
    stack.push_back(points[1]);

    // starting from the 3rd point,
    for (int i = 2; i < (int)points.size(); i++) {
        // let p = stack[stack.size()-2], q = stack[stack.size()-1], r = points[i]
        // if r is on the right, of the line pq, then pop q and repeat the same test
        // though now with a different p and q points
        while (stack.size() > 1 && strict_right(stack[stack.size()-2], stack[stack.size()-1], points[i])) {
            stack.pop_back();
        }

        // otherwise, r is on the left so just push it on the stack
        stack.push_back(points[i]);
    }

    printf("%ld\n", stack.size());
    for (int i = 0; i < stack.size(); i++) {
        printf("%lld %lld\n", stack[i].x, stack[i].y);
    }
}

int main(int argc, const char * argv[]) {
    freopen("in.txt" , "r" , stdin);
    std::vector<Point> points;
    int test_cases;
    scanf("%d", &test_cases);

    while (test_cases--) {
        points.clear();
        long long n;
        scanf("%lld", &n);

        long long x, y;
        char c;
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld %c", &x, &y, &c);
            if (c == 'Y') {
                Point t; t.x = x; t.y = y;
                points.push_back(t);
            }
        }

       graham_scan(points);
    }
}
