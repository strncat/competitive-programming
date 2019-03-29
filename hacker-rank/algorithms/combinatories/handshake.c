#include <stdio.h>

/* hackerrank Handshake
   At the annual meeting of Board of Directors of Acme Inc, every one starts shaking hands with everyone else in
   the room. Given the fact that any two persons shake hand exactly once, Can you tell the total count of
    handshakes?
*/

int main() {

    int cases, n;

    scanf("%d", &cases);

    while (cases--) {

        scanf("%d", &n);
        printf("%d\n", n * (n - 1) / 2);
    }
    return 0;
}
