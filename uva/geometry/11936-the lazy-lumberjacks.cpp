//
//  main.cpp
//  11936 The Lazy Lumberjacks
//
//  Created by Fatima B on 10/11/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>

int main() {
    int test_cases, a, b, c;
    scanf("%d", &test_cases);
    while (test_cases--) {
        scanf("%d %d %d", &a, &b, &c);
        if (a >= c + b || b >= a + c || c >= a + b) {
            printf("Wrong!!\n");
        } else {
            printf("OK\n");
        }
    }
    return 0;
}
