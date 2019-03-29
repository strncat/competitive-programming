//
//  Code Foreces
//  620B - Grandfather Dovlet’s calculator
//
//  Created by Fatima B on 1/21/16.
//  Copyright © 2016 Fatima B. All rights reserved.
//

#include <iostream>
#include <stack>
#include <limits.h>
#include <unordered_map>

int main() {
    int a, b;
    std::unordered_map<int, int> map;

    int d[10];
    d[0] = 6; d[1] = 2; d[2] = 5; d[3] = 5;
    d[4] = 4; d[5] = 5; d[6] = 6; d[7] = 3;
    d[8] = 7; d[9] = 6;

    scanf("%d %d", &a, &b);

    int total = 0;
    for (int i = a; i <= b; i++) {
        int t = i;
        while (t > 0) {
            total += d[t%10];
            t = t/10;
        }
    }
    printf("%d\n", total);
    return 0;
}
