#include <stdio.h>
#include <limits.h>

// Hacker Rank
// August 2014
// Counter Game Weekly Challenge
// for reference, the editorial has a better solution

int is_power_of_two(unsigned long long x) {
    return x && (x & (x - 1)) == 0;
}

#define MAX 64

int main() {
    
    int test_cases, counter;
    unsigned long long int i, n, powers_of_2[100];
    
    powers_of_2[0] = 1;
    for (i = 1; i < MAX; i++) {
        powers_of_2[i] = powers_of_2[i - 1] * 2;
    }
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {

        scanf("%llu", &n);
        counter = 1; // Louise makes the first move

        while (n > 1) {
            if (is_power_of_two(n)) {
                n /= 2;
                counter++;
            } else {
                for (i = 1; i < MAX; i++) {
                    if (n < powers_of_2[i]) {
                        break;
                    }
                }
                n -= powers_of_2[i - 1];
                counter++;
            }
        }
        if (counter % 2 == 0) {
            printf("Louise\n");
        } else {
            printf("Richard\n");
        }
    }
    return 0;
}
