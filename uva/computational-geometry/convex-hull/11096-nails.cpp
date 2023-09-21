//
//  main.cpp
//  uva
//
//  Created by FB on 9/6/23.
//  Based on https://cp-algorithms.com/geometry/convex-hull.html
//  11096 - Nails
//  https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2037
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

long long distance_squared(Point a, Point b) {
    return (b.x - a.x)*(b.x - a.x) + (b.y - a.y)*(b.y - a.y);
}

bool collinear(Point a, Point b, Point c) { 
    return orientation(a, b, c) == 0;
}

double graham_scan(std::vector<Point>& points) {
    if (points.size() <= 3) {
        double length = 0.0;
        for (int i = 0; i < points.size()-1; i++) {
            length += sqrt(distance_squared(points[i], points[i+1]));
        }
        length += sqrt(distance_squared(points[points.size()-1], points[0]));
        return length;
    }

    // step 1: pick the left most element as the starting point
    Point left_most = points[0];
    for (int i = 1; i < points.size(); i++) {
        if (points[i].y < left_most.y || (points[i].y == left_most.y && points[i].x < left_most.x)) {
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
            return distance_squared(a, left_most) < distance_squared(left_most, b);
        }
        return false;
    });

    //int i = (int)points.size()-1;
    //while (i >= 0 && collinear(left_most, points[i], points.back())) {
    //    i--;
    //}
    //reverse(points.begin()+i+1, points.end());

    std::vector<Point> stack;
    // The first two vertices are guaranteed to be on the hull
    stack.push_back(left_most);
    stack.push_back(points[1]);

    // starting from the 3rd point,
    for (int i = 2; i < (int)points.size(); i++) {
        // let p = stack[stack.size()-2], q = stack[stack.size()-1], r = points[i]
        // if r is on the right, of the line pq, then pop q and repeat the same test
        // though now with a different p and q points
        while (stack.size() > 1 && right(stack[stack.size()-2], stack[stack.size()-1], points[i])) {
            stack.pop_back();
        }

        // otherwise, r is on the left so just push it on the stack
        stack.push_back(points[i]);
    }

    double length = 0.0;
    for (int i = 0; i < stack.size()-1; i++) {
        length += sqrt(distance_squared(stack[i], stack[i+1]));
    }
    length += sqrt(distance_squared(stack[stack.size()-1], stack[0]));

    return length;
}

int main(int argc, const char * argv[]) {
    //freopen("in.txt" , "r" , stdin);
    std::vector<Point> points;
    int test_cases;
    double length;
    scanf("%d", &test_cases);
    while (test_cases--) {
        points.clear();
        long long n, x, y;
        scanf("%lf %lld", &length, &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &x, &y);
            Point t; t.x = x; t.y = y;
            points.push_back(t);
        }
        double new_length = graham_scan(points);
        printf("%.5lf\n", std::max(length, new_length));
    }
}
