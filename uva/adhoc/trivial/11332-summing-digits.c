#include <stdio.h>

/* 11332 - Summing Digits
 Sample input
 2
 11
 47
 1234567892
 0
 Output for sample input
 2
 2
 2
 2
*/

int main() {

    long int x, digit, sum;

    while (scanf("%ld", &x) == 1 && x) {
        
        while (1) {
            sum = 0;
            while (x > 0) {
                digit = x % 10;
                sum += digit;
                x /= 10;
            }
            x = sum;
            if (sum < 10)
                break;
        }
        printf("%ld\n", sum);
    }
    return 0;
}