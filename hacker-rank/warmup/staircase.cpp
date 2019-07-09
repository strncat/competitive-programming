//
//  Staircase
//

#include <iostream>
#include <cstring>

int main() {
    int h;
    scanf("%d", &h);
    // for each row
    for (int i = 1; i <= h; i++) {
        // print enough spaces
        for (int j = h - i; j > 0; j--) {
            printf(" ");
        }
        // followed by enough #
        for (int j = 1; j <= i; j++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
