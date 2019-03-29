//
//  Hacker Rank
//  Taum and B'day
//
//  Created by Fatima B on 12/31/15.
//  Copyright © 2015 Fatima B. All rights reserved.
//

#include <iostream>
#include <vector>

int main() {
    int t;
    long a, b, x, y, z;
    scanf("%d", &t);
    while (t--) {
        scanf("%ld %ld", &a, &b);
        scanf("%ld %ld %ld", &x, &y, &z);

        long cost1 = a*x + b*y;
        long cost2 = a*(z+y) + b*y;
        long cost3 = a*x + b*(z+x);

        if (cost1 <= cost2 && cost1 <= cost3) {
            printf("%ld\n", cost1);
        } else if (cost2 <= cost1 && cost2 <= cost3) {
            printf("%ld\n", cost2);
        } else {
            printf("%ld\n", cost3);
        }
    }
    return 0;
}
