#include <stdio.h>

/* hackerrank: counter game */

unsigned long long int is_power_of_two(unsigned long long int x) {
    return (x & (x - 1)) == 0;
}

unsigned long long int fold_over(unsigned long long int x) {
    /* every bit sets the bit immediately to its right */
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    x |= (x >> 32);
    return x;
}

unsigned long long int next_power_of_two(unsigned long long int x) {
    x = fold_over(x);
    x = x >> 1; // one less
    return x + 1; // next power of two
}

int main() {
    
    int cases, Louise;
    unsigned long long int counter;
    
    scanf("%d", &cases);
    
    while (cases--) {
        
        scanf("%llu", &counter);
        
        Louise = 0;
        while (counter != 1) {
            
            if (!is_power_of_two(counter)) {
                //printf("next power of two %llu\n", next_power_of_two(counter));
                counter = counter - next_power_of_two(counter);
            } else {
                //printf("reduce by half %llu\n", counter);
                counter = counter / 2;
            }
            Louise = Louise ? 0 : 1;
        }
        
        if (Louise == 1) {
            printf("Louise\n");
        } else {
            printf("Richard\n");
        }
    }
    
    return 0;
}
