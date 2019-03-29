//
// Problem A. I/O Error
//

#include <iostream>

int main() {
    freopen("example.txt", "r", stdin);
    freopen("example-out.txt", "w", stdout);

    int tests, size;
    scanf("%d\n", &tests);

    for (int t = 1; t <= tests; t++) {
        scanf("%d\n", &size);
        printf("Case #%d: ", t);

        for (int i = 0; i < size; i++) {
            int result = 0;
            int factor = 128;
            for (int j = 0; j < 8; j++) {
                char c;
                scanf("%c", &c);
                if (c == 'I') {
                    result += factor;
                }
                factor /= 2;
            }
            printf("%c", result);
        }
        printf("\n");

    }
    return 0;
}
