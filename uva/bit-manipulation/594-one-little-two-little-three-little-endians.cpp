//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/24/19.
//  594 - One Little, Two Little, Three Little Endians
//

#include <iostream>

// 123456789
// 00000111 01011011 11001101 00010101
// ->
// 00010101 11001101 01011011 00000111
// 365779719

int reverse_bytes(int n) {
    int x = 0;
    for (int i = 0; i < 4; i++) {
        x = x << 8; // shift x 8 bits to make space for the upcoming byte
        unsigned char byte = n; // save the lowest 8 bits, could use a mask instead
        x = x | byte; // now x holds the byte in its lowest byte
        n = n >> 8; // get rid of the lowest 8 bits we just copied, now the msb will have the next byte we need to copy
    }
    return x;
}

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    freopen("in.txt" , "r" , stdin);

    int n, r;
    while (scanf("%d", &n) == 1) {
        r = reverse_bytes(n);
        printf("%d converts to %d\n", n, r);
    }

    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f", time_spent);
    return 0;
}
