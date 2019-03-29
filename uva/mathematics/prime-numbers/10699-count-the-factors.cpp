//
//  main.cpp
//  uhunt
//
//  10699 - Count the factors
//  2017 02 01
//

#include <iostream>
#include <math.h>

int prime_factors(int n) {
    int count = 0;
    int s = sqrt(n);
    for (int i = 2; i <= s; i++) {
        if (n%i == 0) {
            count++;
        }
        while (n % i == 0) {
            n = n/i;
        }
    }
    if (n >= 2) {
        count++;
    }
    return count;
}

int main() {
    //freopen("sample.in", "r", stdin);
    int n;
    while (1) {
        scanf("%d", &n);
        if (n == 0) { break; }
        printf("%d : %d\n", n, prime_factors(n));
    }
    return 0;
}
