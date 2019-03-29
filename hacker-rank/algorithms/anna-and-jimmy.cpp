//
//  main.cpp
//  1
//
//  Created by Fatima Broom on 2/1/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>

int main() {
    int n;
    scanf("%d", &n);

    int volume = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            for (int k = 1; k < n; k++) {
                if (i + j + k == n) {
                    if (i*j*k > volume) {
                        volume = i*j*k;
                    }
                }
            }
        }
    }
    printf("%d\n", volume);

    return 0;
}
