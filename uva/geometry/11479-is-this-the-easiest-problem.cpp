//
//  11479 - Is this the easiest problem?
//
//  Created by Fatima B on 10/11/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <assert.h>

int main() {
    long int test_cases, a, b, c;
    scanf("%ld", &test_cases);

    for (int i = 1; i <= test_cases; i++) {
        scanf("%ld %ld %ld", &a, &b, &c);

        if (a < 0 || b < 0 || c < 0 || a >= b + c || b >= a + c || c >= a + b) {
            printf("Case %d: Invalid\n", i);
        }

        else if (a == b && b == c) {
            printf("Case %d: Equilateral\n", i);
        }

        else if (a == b || b == c || c == a) {
            printf("Case %d: Isosceles\n", i);
        }

        else {
            printf("Case %d: Scalene\n", i);
        }
    }
}
