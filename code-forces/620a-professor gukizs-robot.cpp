//
//  Code Foreces
//  620A - Professor GukiZ's Robot
//
//  Created by Fatima B on 1/21/16.
//  Copyright © 2016 Fatima B. All rights reserved.
//

#include <iostream>
#include <stack>
#include <limits.h>

int main() {
    long x1, x2, y1, y2;
    scanf("%ld %ld", &x1, &y1);
    scanf("%ld %ld", &x2, &y2);
    printf("%ld\n", std::max(abs(x2 - x1),abs(y2 - y1)));
    return 0;
}
