#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>

int long_division(int number) {
    std::unordered_map<int,int> seen;

    int numerator = 1 * 10;
    int cycle_len = 0;

    for (int i = 0; i < 1000; i++) { // let the maximum cycle length be 1000
        int remainder = numerator % number;

        if (seen[remainder] == 1) { // cycle ends
            break;
        }

        seen[remainder] = 1;
        numerator = remainder * 10;
        cycle_len++;
    }
    return cycle_len;
}



int main(int argc, const char * argv[]) {
    int max_cycle = 0;
    for (int i = 1; i < 1000; i++) {
        int length = long_division(i);
        printf("1/%d has cycle %d\n", i, length);
        if (length > max_cycle) {
            max_cycle = length;
        }
    }
    printf("max cycle is %d\n", max_cycle);

    long_division(999);

    return 0;
}

