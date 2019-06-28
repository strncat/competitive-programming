//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/25/19.
//  471 - Magic Numbers
//

#include <iostream>
#include <math.h>

/* 471 - Magic Numbers
 Sample Input
 1
 1234567890
 Sample Output
 1234567890 / 1 = 1234567890
 2469135780 / 2 = 1234567890
 4938271560 / 4 = 1234567890
 6172839450 / 5 = 1234567890
 8641975230 / 7 = 1234567890
 9876543120 / 8 = 1234567890
 */


bool no_repeated_digits(unsigned long long int n) {
    int digits[10] = {0};
    while (n > 0) {
        digits[n % 10]++;
        if (digits[n % 10] > 1) {
            return false;
        }
        n = n / 10;
    }
    return true;
}

int main() {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    //freopen("in.txt" , "r" , stdin);
    int tests;
    long long int n;
    long long int max = 9876543210; // without this max I got 20 WAs :) http://online-judge.uva.es/board/viewtopic.php?f=5&t=6911

    scanf("%d", &tests);
    while (tests--) {
        scanf("%lld", &n);
        for (long long int i = 1; i * n <= max; i++) {
            if (no_repeated_digits(i) && no_repeated_digits(i * n)) {
                printf("%lld / %lld = %lld\n", n * i, i, n);
            }
        }

        if (tests) {
            printf("\n");
        }
    }
    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f", time_spent);
    return 0;
}
