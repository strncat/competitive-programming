//
//  11505 - Logo
//
//  Created by FB on 04/20/20.
//  Copyright © 2020 nemo. All rights reserved.
//

#include <iostream>
#include <math.h>

int main() {
    freopen("in.txt" , "r" , stdin);

    int tests;
    scanf("%d", &tests);

    while (tests--) {
        int n;
        scanf("%d\n", &n);

        std::string dir;
        int d; // degrees or distance
        double x = 0, y = 0;
        double angle = 0.0;

        for (int i = 0; i < n; i++) {
            std::cin >> dir >> d;

            printf("%c\n", dir[0]);

            if (dir[0] == 'f') {
                x += d * cos(angle);
                y += d * sin(angle);
                printf("d * cos(angle) = %0.2f\n", d * cos(angle));
                printf("d * sin(angle) = %0.2f\n", d * sin(angle));
            } else if (dir[0] == 'b') {
                x -= d * cos(angle);
                y -= d * sin(angle);
                printf("d * cos(angle) = %0.2f\n", d * cos(angle));
                printf("d * sin(angle) = %0.2f\n", d * sin(angle));
            } else if (dir[0] == 'l') {
                angle += (d * M_PI / 180.0);
                printf("angle = %0.2f\n", angle * 180 / M_PI);
            } else { // dir[0] == 'r'
                angle -= (d * M_PI / 180.0);
                printf("angle = %0.2f\n", angle * 180 / M_PI);
            }

            printf("x=%0.2f y=%0.2f\n\n", x, y);
        }
        printf("%.0f\n", round(sqrt(x*x+y*y)));
    }

    return 0;
}
