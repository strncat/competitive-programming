#include <stdio.h>

/* Hackerrank: Connecting Towns
 input:
 1
 84
 404 254 243 220 953 922 116 612 157 415 894 229 142 622 744 813 830 158 569 122 429 261 564 923 367 653 648 810 996 760 304 961
 458 465 993 808 612 418 853 522 981 685 652 505 103 16 981 179 516 217 606 489 352 299 254 468 367 562 168 116 926 430 674 221
 402 44 801 901 467 280 144 914 817 434 652 142 587 508 601 489 785 836 758
 output: 568325
*/

int main() {

    int cases, n, routes;
    long long int product = 1;

    scanf("%d", &cases);

    while (cases--) {

        scanf("%d", &n);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d", &routes);
            product *= routes;
            product %= 1234567;
        }
        printf("%lld\n", product);
        product = 1;
    }
    return 0;
}
