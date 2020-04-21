//
//  main.cpp
//  11854 Egypt
//
//  Created by Fatima B on 10/11/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>

int main() {
    int a, b, c;
    while (scanf("%d %d %d", &a, &b, &c)) {
        if (a == 0 && b == 0 && c == 0) { break; }

        if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) {
            printf("right\n");
        } else {
            printf("wrong\n");
        }
    }
    return 0;
}
