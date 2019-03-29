//
//  main.cpp
//  uhunt
//
//  216 - Getting in Line TSP
//  2017/03/14
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>

using std::vector;
using std::pair;
using std::unordered_map;

vector<double> distances;

double dist(vector<int>& a, unordered_map<int,pair<int,int>>& m) {
    double sum = 0.0;
    distances.clear();
    for (int i = 1; i < a.size(); i++) {
        double x1 = m[a[i-1]].first, x2 = m[a[i]].first;
        double y1 = m[a[i-1]].second, y2 = m[a[i]].second;
        double d = sqrt ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1));
        d += 16.0;
        sum += d;
        distances.push_back(d);
    }
    return sum;
}

int main() {
    //freopen("sample.in", "r", stdin);

    int n, x, y, t = 1;
    vector<int> a;
    unordered_map<int,pair<int,int>> m;

    while (scanf("%d", &n) && n != 0) {

        a.clear();

        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            m[i] = pair<int,int>(x,y);
            a.push_back(i);
        }

        double d, min = 10000.0;
        vector<int> min_perm;
        vector<double> min_distances;
        do {
            // calculate current distance
            d = dist(a, m);
            if (d < min) {
                min = d;
                // save this permutation
                min_perm.clear();
                min_distances.clear();
                for (int i = 0; i < a.size(); i++) {
                    min_perm.push_back(a[i]);
                    min_distances.push_back(distances[i]);
                }
            }
        } while (std::next_permutation(a.begin(), a.end()));

        printf("**********************************************************\n");
        printf("Network #%d\n", t++);
        for (int i = 1; i < a.size(); i++) {
            int x1 = m[min_perm[i-1]].first, x2 = m[min_perm[i]].first;
            int y1 = m[min_perm[i-1]].second, y2 = m[min_perm[i]].second;
            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",x1,y1,x2,y2,min_distances[i-1]);
        }
        printf("Number of feet of cable required is %.2lf.\n", min);

    }
    return 0;
}
