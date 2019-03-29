//
//  main.cpp
//  uhunt
//
//  412 - Pi
//  2017/02/04
//

#include <iostream>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    //freopen("sample.in", "r", stdin);
    int n;
    int a[50];
    while (1) {
        scanf("%d", &n);
        if (n == 0) { break; }

        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        // number of pairs = n choose 2 = n * (n-1) / 2
        int total = n * (n-1) / 2;
        double pi = 0;
        int r = 0; // pairs without common factors

        // find pairs without common factor
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                // are a[i] and a[j] relatively prime?
                if (gcd(a[i], a[j]) == 1) {
                    r++;
                }
            }
        }
        if (r > 0) {
            pi = sqrt (6.0 * total / (double)r);
            printf("%.6f\n", pi);
        } else {
            printf("No estimate for this data set.\n");
        }
    }
    return 0;
}
