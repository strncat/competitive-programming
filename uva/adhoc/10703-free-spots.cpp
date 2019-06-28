//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/25/19.
//  10703 - Free spots
//

#include <iostream>
#include <math.h>

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    //freopen("in.txt" , "r" , stdin);

    int w, h, n, x1, x2, y1, y2;
    while (scanf("%d %d %d", &w, &h, &n) == 3) {
        if (w == 0) { break; }

        int m[w+2][h+2];

        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                m[i][j] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            int min_x = std::min(x1,x2);
            int max_x = std::max(x1,x2);
            int min_y = std::min(y1,y2);
            int max_y = std::max(y1,y2);

            for (int i = min_x; i <= max_x; i++) {
                for (int j = min_y; j <= max_y; j++) {
                    m[i][j] = 0; // spot taken
                }
            }
        }

        int total = 0;
        for (int i = 1; i <= w; i++) {
            for (int j = 1; j <= h; j++) {
                total += m[i][j];
            }
        }

        if (total == 0) {
            printf("There is no empty spots.\n");
        } else if(total == 1) {
            printf("There is one empty spot.\n");
        } else {
            printf("There are %d empty spots.\n", total);
        }
    }
    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f", time_spent);
    return 0;
}
