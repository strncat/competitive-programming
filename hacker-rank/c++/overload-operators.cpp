//
//  Hacker Rank
//  Overload Operators
//
//  Created by Fatima B on 1/23/16.
//  Copyright © 2016 Fatima B. All rights reserved.
//

#include<iostream>

using namespace std;

class Complex {
public:
    int a, b;
    void input(string s) {
        int v1= 0;
        int i= 0;
        while (s[i]!='+') {
            v1 = v1*10 + s[i] - '0';
            i++;
        }
        while (s[i] == ' ' || s[i] == '+' || s[i] == 'i') {
            i++;
        }
        int v2 = 0;
        while (i<s.length()) {
            v2 = v2*10 + s[i] - '0';
            i++;
        }
        a = v1;
        b = v2;
    }
};

Complex operator+(const Complex &c1, const Complex &c2) {
    Complex c;
    c.a = c1.a + c2.a;
    c.b = c1.b + c2.b;
    return c;
}

ostream& operator<<(ostream &out, Complex &c) {
    if (c.b > 0) {
        out << c.a << "+i" << c.b;
    } else if (c.b < 0) {
        out << c.a << "-i" << c.b;
    } else {
        out << c.a;
    }
    return out;
}



int main() {
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
