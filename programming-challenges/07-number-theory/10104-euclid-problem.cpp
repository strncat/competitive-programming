//
//  main.cpp
//  uhunt
//
//  10104 Euclid Problem
//  2017/03/05
//
//

#include <iostream>
#include <vector>
#include <math.h>

// find x, y and d in p*x + q*y = d = gcd(p,q)
long gcd(long p, long q, long *x, long *y) {
    if (q > p) { return gcd(q, p, y, x); }

    if (q == 0) {
        *x = 1;
        *y = 0;
        return(p);
    }
    long x1, y1;
    long g = gcd(q, p%q, &x1, &y1);
    *x = y1;
    *y = (x1 - floor(p/q)*y1);
    return g;
}

int main() {
    //freopen("sample.in", "r", stdin);
    long p, q;
    while (scanf("%ld %ld", &p, &q) != EOF) {
        long g, x, y;
        g = gcd(p, q, &x, &y);
        printf("%ld %ld %ld\n", x, y, g);
    }
    return 0;
}