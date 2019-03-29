//
//  main.cpp
//  uhunt
//
//  10006 - Carmichael Numbers
//  2017/03/05
//
//

#include <iostream>
#include <math.h>

int is_prime(int n) {
    if (n <= 1) { return false; }
    if (n == 2) { return true; }
    if (n % 2 == 0) { return 0; }

    int s = sqrt(n);
    for (int i = 3; i <= s + 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

long long mod_fast(long long b, long long e, long long m) { // b^e mod m, O(lg(e))
    b = b % m;
    long long result = 1;

    while (e) {
        if (e % 2 == 1) {
            result = (result * b) % m;
        }
        b = (b * b) % m;
        e >>= 1;
    }
    return result;
}

int main() {
    //freopen("sample.in", "r", stdin);
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        bool carmichael = true;
        if (n % 2 == 0 || is_prime(n)) {
            carmichael = false;
        } else { // only test odd numbers that are not prime
            for (int i = 2; i < n; i++) {
                if (mod_fast(i, n, n) != i) {
                    carmichael = false;
                    break;
                }
            }
        }
        if (carmichael) {
            printf("The number %d is a Carmichael number.\n", n);
        } else {
            printf("%d is normal.\n", n);
        }
    }
    return 0;
}
