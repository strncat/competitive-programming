//
//  Hacker Rank
//  Box it
//
//  Created by Fatima B on 1/23/16.
//  Copyright © 2016 Fatima B. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated, BoxesDestroyed;

class Box {
public:
    long long l, h, b;
    Box() {
        l = h = b = 0;
        BoxesCreated++;
    }
    Box(long long length, long long breadth, long long height) {
        l = length;
        b = breadth;
        h = height;
        BoxesCreated++;
    }
    Box(Box const &B) {
        l = B.l;
        b = B.b;
        h = B.h;
        BoxesCreated++;
    }
    ~Box() {
        BoxesDestroyed++;
    }

    long long getLength() {
        return l;
    }
    long long getBreadth() {
        return b;
    }
    long long getHeight() {
        return h;
    }
    long long CalculateVolume() {
        return l * h * b;
    }
    bool operator<(Box &B) {
        return (l < B.l) ||
        (l == B.l && b < B.b) ||
        (l == B.l && b == B.b && h < B.h);
    }
};

ostream& operator<<(ostream &out, const Box B) {
    out << B.l << " " << B.b << " " << B.h;
    return out;
}

void check2() {
    int n;
    cin >> n;
    Box temp;
    for(int i=0; i<n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            cout << temp << endl;
        }
        if (type == 2) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l,b,h);
            temp = NewBox;
            cout << temp << endl;
        }
        if (type == 3) {
            int l, b, h;
            cin >> l >> b >> h;
            Box NewBox(l,b,h);
            if(NewBox < temp) {
                cout << "Lesser" << endl;
            } else {
                cout << "Greater" << endl;
            }
        } if (type == 4) {
            cout << temp.CalculateVolume() << endl;
        }
        if (type == 5) {
            Box NewBox(temp);
            cout << NewBox << endl;
        }
    }
}

int main() {
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout << "Boxes Created : " << BoxesCreated << endl
    << "Boxes Destroyed : " << BoxesDestroyed << endl;
}

