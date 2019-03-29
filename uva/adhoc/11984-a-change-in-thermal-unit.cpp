//
//  main.cpp
//  uhunt
//
//  11984 - A Change in Thermal Unit
//  2017/02/06
//

#include <iostream>

int main() {
    //freopen("sample.in", "r", stdin);
    int test_cases, c, d;
    scanf("%d", &test_cases);
    for (int t = 1; t <= test_cases; t++) {
        scanf("%d %d", &c, &d);

        // F = (9/5)*c + 32
        // F+d = (9/5)*C + 32
        // ((9/5)*c + 32) + d = (9/5)*C + 32
        // (9/5)*c + d = (9/5)*C
        // 9*c + 5*d = 9*C
        // 9C = 9c + 5d
        // C = c + (5/9)*d
        printf("Case %d: %.2f\n", t, c + (5.0/9.0)*d);
    }
    return 0;
}