//
//  10970 - Big Chocolate
//
//  Created by Fatima B on 10/14/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <assert.h>

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        printf("%d\n", (m * n) - 1);
    }
    return 0;
}
