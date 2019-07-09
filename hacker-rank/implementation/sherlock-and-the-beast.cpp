//
//  Sherlock and The Beast
//  Created by Fatima B on 9/27/15
//
//  need a better way to test

#include <iostream>
#include <assert.h>

void print(int d, int n, std::string &s) {
    for (int i = 0; i < n; i++) {
        printf("%d", d);
        //s = s + std::to_string(d); // really bad / will TLE but i need it for testing
    }
}

std::string produce(int n) {
    std::string s = "";
    int i;
    for (i = n; i > 0; i--) {
        if (i % 3 == 0 && (n-i) % 5 == 0) {
            break;
        }
    }

    if (i == 0) {
        if (n % 5 == 0) {
            print(3, n, s);
        } else {
            s = std::to_string(-1);
        }
    } else {
        print(5, i, s);
        print(3, n - i, s);
    }
    return s;
}

void tests() {
    int a[4] = {1, 3, 5, 11};
    std::string c[4] = {"-1", "555", "33333", "55555533333"};
    for (int i = 0; i < 4; i++) {
        std::string s = produce(a[i]);
        assert(s == c[i]);
    }
}

int main() {
    //tests();
    int n, cases;
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d", &n);
        printf("%s\n", produce(n).c_str());
    }
    return 0;
}
