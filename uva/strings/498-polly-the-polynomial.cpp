//
//  main.cpp
//  uhunt
//
//  498 - Polly the Polynomial
//  2017/02/06
//

#include <iostream>
#include <math.h>
#include <string.h>

int main() {
    //freopen("sample.in", "r", stdin);

    char line[1000];
    int c[1000] = {0};
    int x[1000] = {0};
    while(fgets(line, 1000, stdin)) {
        // parse c values
        char *p = strtok(line, " ");
        int n = 0;
        while (p) {
            sscanf(p, "%d", &c[n++]);
            p = strtok(NULL, " ");
        }

        // parse x values
        fgets(line, 1000, stdin);
        p = strtok(line, " ");
        int m = 0;
        while (p) {
            sscanf(p, "%d", &x[m++]);
            p = strtok(NULL, " ");
        }

        for (int i = 0; i < m; i++) {
            long long int sum = 0;
            long long int xpower = x[i];
            if (n > 0) { sum = (c[n-1] * 1); }// initial value c_{n-1} * x^{0}=1
            for (int j = n-2; j >= 0; j--) {
                sum += (c[j] * xpower); // c_{j} * x^{?}
                xpower *= x[i];
            }
            printf("%lld", sum);
            if (i < m-1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
