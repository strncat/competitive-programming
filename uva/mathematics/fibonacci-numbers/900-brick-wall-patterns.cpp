//
//  main.cpp
//  uhunt
//
//  900 - Brick Wall Patterns
//  2017/02/08
//

#include <iostream>

long int fib[55];
void fibonacci() {
    fib[1]=1;
    fib[2]=1;
    for (int i=3; i <= 55; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
}

int main() {
    //freopen("sample.in", "r", stdin);
    int n;
    fibonacci();
    while (1) {
        scanf("%d", &n);
        if (n == 0) { break; }
        printf("%ld\n", fib[n+1]);
    }
    return 0;
}