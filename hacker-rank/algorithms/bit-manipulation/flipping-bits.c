#include <stdio.h>

/* Hacker Rank Flipping bits */

#define N 4

int main() {

    int cases;
    unsigned int n;

    scanf("%d", &cases);

    while (cases--) {
        scanf("%u", &n);
        printf("%u\n", ~n);
    }

    return 0;
}
