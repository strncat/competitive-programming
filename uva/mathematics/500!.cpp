//
//  UVa Online Judge
//  623 - 500!
//  The maximum input is 1000 for this problem. There are 2568 digits in 1000!
//
//

#include <iostream>

#define MAX 2700
int factorial[1003][MAX];
int last_digit[1003];

void calculate_factorial(int n) { // factorial[n] = n * factorial[n-1]
    int *prev = factorial[n-1];
    int *cur = factorial[n];
    int index = 0;
    int last_digit_index = 0;
    int d = n;
    while (d) {
        int j = index++; // shifting as we move
        int carry = 0;

        for (int i = 0; i <= last_digit[n-1]; i++) { // for each digit of previous
            int r = (d%10) * prev[i] + carry;
            carry =  (cur[j] + r) / 10;
            cur[j] = (cur[j] + r) % 10;
            j++;
        }
        cur[j] += carry; // last carry
        cur[j] > 0 ? last_digit_index = j : last_digit_index = j-1;
        d = d / 10;
    }
    last_digit[n] = last_digit_index;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);

    // precalculate factorials
    factorial[0][0] = 1;
    for (int i = 1; i < 1001; i++) { calculate_factorial(i); }

    int n;
    while (scanf("%d", &n) == 1) {
        printf("%d!\n", n);
        for (int i = last_digit[n]; i >= 0; i--) {
            printf("%d", factorial[n][i]);
        }
        printf("\n");
    }
    return 0;
}
