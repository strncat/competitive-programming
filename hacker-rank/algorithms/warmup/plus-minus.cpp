//
//  Plus Minus
//

#include <iostream>
#include <cstring>

int main() {
    int n, d, positive = 0, negative = 0, zero = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &d);
        if (d > 0) {
            positive++;
        } else if (d < 0) {
            negative++;
        } else {
            zero++;
        }
    }
    double sum = positive + negative + zero;
    printf("%.3f\n%.5f\n%.5f", positive/sum, negative/sum, zero/sum);
    return 0;
}
