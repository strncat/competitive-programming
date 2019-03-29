//
//  main.cpp
//  uhunt
//
//  11636 - Hello World!
//  2017/02/27
//
//

#include <iostream>

int main() {
    //freopen("sample.in", "r", stdin);
    int n, a[16] = {0,0,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384};
    int t = 1;
    while (scanf("%d", &n)) { // n <= 10,001 < 2^14 = 16,384
        if (n < 0) { break; }
        int i = 0;
        if (n == 1) { i = 1; }
        else {
            for (; i < 16; i++) {
                if (a[i] >= n) { break; }
            }
        }
        printf("Case %d: %d\n", t++, i - 1);
    }
    return 0;
}