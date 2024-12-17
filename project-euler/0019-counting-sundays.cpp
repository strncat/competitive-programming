//
//
//  Project Euler
//
//  Created by FB on 8/04/24.
//  19 Counting Sundays https://projecteuler.net/problem=19
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#define N 100

int main(int argc, const char * argv[]) {
    // How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
    clock_t begin, end;
    double time_spent;
    begin = clock();

    //freopen("triangle.txt" , "r" , stdin);
                       // J  F   M   A   M   J   J    A   S  O   N   D
    int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    // Sunday corresponds to 1/6/1901
    int d = 6;
    int m = 1;
    int y = 1901;
    int count = 0;
    
    // starting at Sunday 1/6/1900
    while (y <= 2000) {
        d += 7;
        if (d % months[m] == 1) {
            count++;
            printf("It's Sunday! %d/1/%d\n", m+1,y);
        }
        if (d > months[m]) {
            d = d % months[m];
            m++;
            if (m == 13) { // new year
                m = 1;
                y++;
                // check if y is a leap year
                if (y % 4 == 0 || (y % 100 == 0 && y % 400 == 0)) {
                    months[2] = 29;
                } else {
                    months[2] = 28;
                }
            }
        }
    }
    printf("count = %d\n", count);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
