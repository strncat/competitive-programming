//
//  main.cpp
//  uhunt
//
//  402 - M*A*S*H
//  2017/02/22
//
//

#include <iostream>
#include <string.h>

int main() {
    freopen("sample.in", "r", stdin);
    int n, x, t = 1;
    while(scanf("%d %d", &n, &x) != EOF) {
        int cards[20]; // 20 cards;
        memset(cards, 0, sizeof(cards));
        for (int i = 0; i < 20; i++) {
            scanf("%d", &cards[i]);
        }

        int a[51]={0}, temp[51]={0};
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }

        int c = 0;
        while (n > x) {
            if (c > 19) { break; }
            int i = 1, j = 1, newn = n;
            for (;i <= n; i++) {
                if (i % cards[c] != 0) {
                    temp[j++] = a[i];
                } else {
                    newn--;
                    if (newn == x) { i++; break; }
                }
            }
            // continue copying
            for (;i <= n; i++) {
                temp[j++] = a[i];
            }

            // copy temp back to a
            n = newn;
            for (int i = 1; i < j; i++) {
                a[i] = temp[i];
            }
            c++;
        }

        printf("Selection #%d\n", t++);
        for (int i = 1; i < n; i++) {
            printf("%d ",a[i]);
        }
        printf("%d\n\n", a[n]);
    }
    return 0;
}
