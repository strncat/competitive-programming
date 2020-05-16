//
//  11343 - Isolated Segments
//  Classic application of CLRS's Algorithm for Line Intersection
//  CLRS: Chapter 33 - Computational Geometry
//
//  Created by FB on 5/15/20.
//
//

#include <iostream>
#include <vector>

typedef struct point {
    long long x;
    long long y;
} point;

typedef struct segment {
    point p1;
    point p2;
} segment;

// check whether p-p1 is on the left or right of segment p2-p1
int direction(point p, point q, point t) {
    // find t-p x q-p
    // t-p = (t.x-p.x, t.y-p.y)
    // q-p = (q.x-p.x, q.y-p.y)
    long long cross_product = (t.x - p.x) * (q.y - p.y) -
                              (t.y - p.y) * (q.x - p.x);

    if (cross_product > 0) {
        return 1; // t-p is clockwise from q-p
    } else if (cross_product < 0) {
        return -1; // anticlockwise
    }
    return 0; // colinear
}

bool on_segment(point p, point q, point t) {
    if (t.x >= std::min(p.x, q.x) &&
        t.x <= std::max(p.x, q.x) &&
        t.y >= std::min(p.y, q.y) &&
        t.y <= std::max(p.y, q.y)) {
        return true;
    }
    return false;
}

bool segment_intersection(point p1, point p2, point p3, point p4) {
    int d1 = direction(p3, p4, p1); // which side is p1 on?
    int d2 = direction(p3, p4, p2); // same for p2
    int d3 = direction(p1, p2, p3);
    int d4 = direction(p1, p2, p4);

    // this means each line segment straddles the line containing the
    // other segment so they intersect
    if  (d1 != d2 && d3 != d4) {
        return true;
    }

    // d1 = 0 means that p1,p3,p4 are colinear, we check if p1
    // is between the segment p3, p4
    if (d1 == 0 and on_segment(p3, p4, p1)) {
        return true;
    }
    if (d2 == 0 and on_segment(p3, p4, p2)) {
        return true;
    }
    if (d3 == 0 and on_segment(p1, p2, p3)) {
        return true;
    }
    if (d4 == 0 and on_segment(p1, p2, p4)) {
        return true;
    }
    return false;
}

int main() {
    //freopen("in.txt" , "r" , stdin);
    int n, tests;
    scanf("%d", &tests);
    while (tests--) {
        scanf("%d", &n);
        std::vector<segment> segments;
        for (int i = 0; i < n; i++) {
            segment s;
            scanf("%lld %lld %lld %lld", &s.p1.x, &s.p1.y, &s.p2.x, &s.p2.y);
            segments.push_back(s);
        }
        int num_isolated = 0;
        for (int i = 0; i < n; i++) {
            bool isolated = true;
            for (int j = 0; j < n; j++) {
                if (i == j) { continue; }
                // check if segment[i] & segment[j] intersect
                if (segment_intersection(segments[i].p1, segments[i].p2,
                                         segments[j].p1, segments[j].p2)) {
                    isolated = false;
                    break;
                }
            }
            if (isolated) {
                num_isolated++;
            }
        }
        printf("%d\n", num_isolated);
    }
    return 0;
}
