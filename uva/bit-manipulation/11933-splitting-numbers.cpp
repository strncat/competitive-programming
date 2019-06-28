//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/24/19.
//  11933 Splitting Numbers
//

#include <iostream>

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    //freopen("in.txt" , "r" , stdin);

    int n;
    while (scanf("%d", &n) == 1) {
        if (n == 0) { break; }

        int a = 0, b = 0, i = 0, bit = 1;
        while (n) {
            if (n & 1) { // there is a 1 at the ith bit
                if (bit & 1) { // bit = number of 1's seen so far, odd goes to a, even to b
                    a |= (1 << i);
                } else {
                    b |= (1 << i);
                }
                bit++;
            }
            i++;
            n = n >> 1;
        }
        printf("%d %d\n", a, b);
    }

    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f", time_spent);
    return 0;
}
