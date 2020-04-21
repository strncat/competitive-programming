//
//  Closest Pair of Points in 2D O(NLog(N))
//  10245 - The Closest Pair Problem
//
//  Created by FB on 9/22/17.
//  Copyright © 2017 FB. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <algorithm>

#define MAX 10002

typedef struct Point {
    double x, y;
    Point() { this->x = 0; this->y = 0; }
    Point(double x, double y) { this->x = x; this->y = y; }
} Point;

bool compareByX(const Point &left, const Point &right) {
    return (left.x < right.x);
}

bool compareByY(const Point &left, const Point &right) {
    return (left.y < right.y);
}

// important not to sqrt here seriously, I got so many WAs because of this!
double distanceSquared(Point a, Point b) {
    return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y);
}

float bruteForce(Point *sortedX, int n) {
    float min = 10000000000;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (distanceSquared(sortedX[i], sortedX[j]) < min) {
                min = distanceSquared(sortedX[i], sortedX[j]);
            }
        }
    }
    return min;
}

double closestSplitPair(Point *sortedX, int n, double delta) {
    int mid = n/2;
    Point midPoint = sortedX[mid];

    Point strip[MAX];
    int m = 0;
    for (int i = 0; i < n; i++) {
        if (fabs(sortedX[i].x - midPoint.x) < delta) {
            strip[m++] = sortedX[i];
        }
    }
    std::sort(strip, strip + m, compareByY);

    double min = delta;
    for (int i = 0; i < m; i++) {
        int limit = i + 7 <= m ? i + 7 : m; // only check the 7 points after the current point
        for (int j = i + 1; j < limit; j++) {
            double dist = distanceSquared(strip[i], strip[j]);
            if (dist < min) {
                min = dist;
            }
        }
    }
    return min;
}

double closestPairs(Point *sortedX, int n) {
    if (n < 4) { return bruteForce(sortedX, n); }
    int mid = n/2;
    double dl = closestPairs(sortedX, mid);
    double dr = closestPairs(sortedX + mid, n-mid);

    double delta = std::min(dl, dr);
    return closestSplitPair(sortedX, n, delta);
}

double closestPairMain(Point *points, int n) {
    std::sort(points, points + n, compareByX);
    return closestPairs(points, n);
}

int main() {
    //freopen("example.in" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    Point points[MAX];
    int n;

    while (scanf("%d", &n) && n) {
        for (int i = 0; i < n; i++) {
            scanf("%lf %lf", &points[i].x, &points[i].y);
        }
        double distance = sqrt(closestPairMain(points, n));

        if (distance >= 10000.0) {
            printf("INFINITY\n");
        } else {
            printf("%.4lf\n", distance);
        }
    }
    return 0;
}