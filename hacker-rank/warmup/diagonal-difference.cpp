//
//  Diagonal Difference
//  Calculate the absolute difference of the sums across the two main diagonals
//

#include <iostream>
#include <cstring>

int main() {
    int n, d, sum1 = 0, sum2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &d);
            if (i == j) {
                sum1 += d;
            }
            if (i + j == n-1) {
                sum2 += d;
            }
        }
    }
    printf("%d", abs(sum1 - sum2));
    return 0;
}
