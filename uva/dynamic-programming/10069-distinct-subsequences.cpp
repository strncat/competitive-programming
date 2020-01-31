//
//  main.cpp
//  10069 - Distinct Subsequences
//
//  Created by FB on 3/22/19.
//  Copyright © 2019 FB. All rights reserved.
//

#include <iostream>
#include <string.h>

#define MAXDIGITS 200
#define PLUS +1
#define MINUS -1

typedef struct bignum {
    int length;
    int d[MAXDIGITS];
    bignum() {
        memset(d, 0, sizeof(d));
        length = 1;
    }

    bignum(int n) {
        *this = n;
    }

    bignum(const char* n) {
        *this = n;
    }

    void resetBignum() {
        memset(d, 0, sizeof(d));
        length = 1;
    }

    bignum operator = (int n) {
        char s[MAXDIGITS];
        sprintf(s, "%d", n);
        *this = s;
        return *this;
    }

    bignum operator = (const char* num) {
        length = (int)strlen(num);
        for(int i = 0; i < length; i++) {
            d[i] = num[length-i-1] - '0';
        }
        return *this;
    }

    std::string str() const {
        std::string res = "";
        for (int i = 0; i < length; i++) {
            res = (char)(d[i] + '0') + res;
        }
        if (res == "") {
            res = "0";
        }
        return res;
    }

    bignum operator + (const bignum& b) const{
        bignum c;
        c.length = 0;
        for(int i = 0, g = 0; g || i < std::max(length, b.length); i++) {
            int x = g;
            if(i < length) {
                x += d[i];
            }
            if(i < b.length) {
                x += b.d[i];
            }
            c.d[c.length++] = x % 10;
            g = x / 10;
        }
        return c;
    }

    void clean() {
        while (length > 1 && !d[length-1]) {
            length--;
        }
    }

    bignum operator * (const bignum& b) {
        bignum c; c.length = length + b.length;
        for (int i = 0; i < length; i++) {
            for (int j = 0; j < b.length; j++) {
                c.d[i+j] += d[i] * b.d[j];
            }
        }
        for(int i = 0; i < c.length-1; i++) {
            c.d[i+1] += c.d[i] / 10;
            c.d[i] %= 10;
        }
        c.clean();
        return c;
    }

    bignum operator - (const bignum& b) {
        bignum c; c.length = 0;
        for (int i = 0, g = 0; i < length; i++) {
            int x = d[i] - g;
            if(i < b.length) x -= b.d[i];
            if(x >= 0) g = 0;
            else {
                g = 1;
                x += 10;
            }
            c.d[c.length++] = x;
        }
        c.clean();
        return c;
    }

    bool operator < (const bignum& b) const{
        if (length != b.length) {
            return length < b.length;
        }
        for (int i = length-1; i >= 0; i--) {
            if(d[i] != b.d[i]) {
                return d[i] < b.d[i];
            }
        }
        return false;
    }

    bool operator > (const bignum& b) const{
        return b < *this;
    }

    bool operator <= (const bignum& b) {
        return !(b > *this);
    }

    bool operator == (const bignum& b) {
        return !(b < *this) && !(*this < b);
    }

    bignum operator += (const bignum& b) {
        *this = *this + b;
        return *this;
    }
} bignum;

std::istream& operator >> (std::istream &in, bignum& x) {
    std::string s;
    in >> s;
    x = s.c_str();
    return in;
}

std::ostream& operator << (std::ostream &out, const bignum& x) {
    out << x.str();
    return out;
}


//---------------------------------------------------------------

bignum c[10001];

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    std::string s, p;
    int n, m, tests;

    scanf("%d\n", &tests);

    while(tests--) {
        std::cin >> s >> p;
        n = (int) s.length();
        m = (int) p.length();

        for (int i = 0; i < n; i++) {
            c[i].resetBignum();
        }

        // initial iteration for the first letter
        for (int i = 0; i < n; i++) {
            if (s[i] == p[0]) {
                c[i] = 1;
            }
        }

        // inductive step
        bignum sum;
        for (int i = 1; i < m; i++) {
            sum = 0;
            for (int j = 0; j < i; j++) {
                sum += c[j];
                c[j] = 0;
            }

            // starting matching p[i] at i
            for (int j = i; j < n; j++) {
                if (s[j] == p[i]) {
                    bignum temp = c[j];
                    c[j] = sum;
                    sum += temp;
                } else {
                    sum += c[j];
                    c[j] = 0;
                }
            }
        }

        sum = 0;
        for (int i = 0; i < n; i++) {
            sum += c[i];
        }
        std::cout << sum << std::endl;
    }
    return 0;
}
