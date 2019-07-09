#include <stdio.h>

/* Hackerrank: Find Digits */

int main() {

    int cases, digit, count = 0, n, copy;

    scanf("%d", &cases);

    while (cases--) {

        scanf("%d", &n);
        copy = n;
        count = 0;

        while (n) {
            digit = n % 10;
            if (digit && (copy % digit == 0)) {
                count++;
            }
            n /= 10;
        }
        printf("%d\n", count);
    }
    return 0;
}
