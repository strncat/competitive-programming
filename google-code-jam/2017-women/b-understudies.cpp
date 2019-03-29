//
//  main.cpp
//  uhunt
//
//  1
//

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>

using std::vector;

int main() {
    freopen("sample.in", "r", stdin);
    freopen("sample.out", "w", stdout);

    int test_cases;
    double s[200][2];

    scanf("%d", &test_cases);

    for (int t = 1; t <= test_cases; t++) {
        int n;
        scanf("%d", &n);

        vector<double> p;
        double x;
        for (int i = 0; i < 2*n; i++) {
            scanf("%lf", &x);
            p.push_back(x);
        }

        for (int i = 0; i < n; i++) {
            s[i][0] = 0.0;
            s[i][1] = 0.0;
        }

        std::sort(p.begin(), p.end());
        std::reverse(p.begin(), p.end());

/*
 for (int i = 0; i < 2*n; i++) {
 printf("%lf ", p[i]);
 }
 printf("\n");
*/

        double s[200][2];
        for (int i = 0; i < n; i++) {
            s[i][0] = p[i];
        }

        int index = 1;
        for (int i = n; i < 2*n; i++) {
            s[n-index][1] = p[i];
            index++;
        }

        double product = 1;
        for (int i = 0; i < n; i++) {
            //printf("%lf %lf\n", s[i][0], s[i][1]);
            double x = 1.0 - (s[i][0] * s[i][1]);
            product *= x;
        }

        printf("Case #%d: %lf\n", t, product);

    }
    return 0;
}
