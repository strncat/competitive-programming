//
//  main.cpp
//  uhunt
//
//  10370 - Above Average
//  2017/02/06
//

#include <iostream>

int main() {
    //freopen("sample.in", "r", stdin);
    int n, c, a[1000];
    scanf("%d", &c);
    for (int t = 0; t < c; t++) {
        scanf("%d", &n);

        int sum = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            sum += a[i];
        }

        double average = sum/n;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] > average) {
                count++;
            }
        }
        printf("%.3f%%\n", ((count*1.0)/n)*100);
    }
    return 0;
}