#include <stdio.h>

/* hackerrank: AND product */

void print_binary(unsigned long x) {
    for (unsigned long i = 1 << 63; i > 0; i = i >> 1) {
        if (i & x) {
            printf("1");
        } else {
            printf("0");
        }
    }
    printf("\n");
}

unsigned long fold_over(unsigned long x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    x |= (x >> 32);
    return x;
}

unsigned long next_power_two(unsigned long x) {
    x = fold_over(x);
    return x + 1;
}

int main() {
    
    int cases;
    unsigned long a, b;

    scanf("%d", &cases);
    
    while (cases--) {
        scanf("%lu %lu", &a, &b);
        
        unsigned long nextPower = next_power_two(a);

        if (b >= nextPower) {
            printf("0\n");
        } else {
            printf("%lu\n", a);
        }
    }

    /* observe with a for loop that once we reach a power of 2 we zero out
     if we don't see a power of two next, then the result is always a

    int result = 12;
    for (int i = 13; i < 17; i++) {

        print_binary(result);
        printf(" %d (result)\n", result);

        print_binary(i);
        printf(" %d (i)\n", i);

        result &= i;
        print_binary(result);
        printf(" %d (result)\n\n", result);
    }
    */
    return 0;
}
