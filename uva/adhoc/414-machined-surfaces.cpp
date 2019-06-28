//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/25/19.
//  414 - Machined Surfaces
//

#include <iostream>
#include <math.h>

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    //freopen("in.txt" , "r" , stdin);

    char line[30];
    int n, size = 25;

    while (scanf("%d\n", &n) == 1) {
        if (n == 0) { break; }

        int count[15] = {0}, max = 0;
        for (int i = 0; i < n; i++) {
            fgets(line, 30, stdin);

            // count X's in each line
            for (int j = 0; j < size; j++) {
                if (line[j] == 'X') {
                    count[i]++;
                }
            }

            if (count[i] > max) {
                max = count[i];
            }
        }

        int missing = 0;
        for (int i = 0; i < n; i++) {
            missing += abs(max-count[i]);
        }

        printf("%d\n", missing);

    }


    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f", time_spent);
    return 0;
}
