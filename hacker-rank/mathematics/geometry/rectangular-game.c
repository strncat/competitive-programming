//
//  hackerrank: Algorithms: Geometry: Rectangular Game

#include <stdio.h>

#define min(a, b) (a < b ? a : b)

int main() {

    long long int x, y, a, b;
    int steps;

    scanf("%d", &steps);

    scanf("%lld %lld", &x, &y);
    steps--;

    while (steps--) {
        scanf("%lld %lld", &a, &b);
        x = min(a, x);
        y = min(b, y);
    }

    printf("%lld\n", x * y);
    return 0;
}
