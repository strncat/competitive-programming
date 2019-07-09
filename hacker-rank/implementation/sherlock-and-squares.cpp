
#include <iostream>
#include <math.h>

int main() {
    int tests;
    scanf("%d", &tests);
    long a, b;
    while (tests--) {
        scanf("%ld %ld", &a, &b);
        int count = 0;

        long sa = sqrt(a);
        long sb = sqrt(b);

        for (long i = sa; i <= sb; i++) {
            if (i*i >= a && i*i <= b) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
