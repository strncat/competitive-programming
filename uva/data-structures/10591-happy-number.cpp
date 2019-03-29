//
//  main.cpp
//  uhunt
//
//  10591 - Happy Number
//  2017/02/07
//

#include <iostream>
#include <set>

int square_digits(long long int n) {
    int t = 0;
    while (n > 0) {
        t += (n%10)*(n%10);
        n /= 10;
    }
    return t;
}

int main() {
    //freopen("sample.in", "r", stdin);
    int test_cases;
    long long int n, original;
    scanf("%d", &test_cases);

    for (int t = 1; t <= test_cases; t++) {
        scanf("%lld", &n);

        std::set<long long int> s;
        original = n;
        while (n != 1) {
            s.insert(n);
            n = square_digits(n);
            if (s.find(n) != s.end()) {
                break;
            }
        }

        if (n == 1) {
            printf("Case #%d: %lld is a Happy number.\n", t, original);
        } else {
            printf("Case #%d: %lld is an Unhappy number.\n", t, original);
        }
    }
    return 0;
}