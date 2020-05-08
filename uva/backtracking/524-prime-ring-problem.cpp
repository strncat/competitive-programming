//
//  main.cpp
//  uhunt
//
//  524 - Prime Ring Problem
//

#include <iostream>
#include <vector>
#include <math.h>

#define MAX 100
bool prime[MAX];

void generate_primes(bool *p) {
    for (int i = 0; i < MAX; i++) { p[i] = true; }
    p[0] = false; p[1] = false;
    int n = MAX/2;
    for (int i = 2; i <= n; i++) { // mark all multiples to be false
        if (p[i]) {
            int j = i*2;
            while (j < MAX) {
                p[j] = false;
                j += i;
            }
        }
    }
}

void backtrack(int *a, bool *visited, int index, int n) {
    if (index > n) { // potenial solution
        // last check, (last element + first element) has to be prime
        if (!prime[a[index-1]+a[1]]) { return; }
        for (int i = 1; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[n]);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (visited[i] == false && prime[a[index-1] + i]) { // sum is prime
            a[index] = i;
            visited[i] = true;
            backtrack(a, visited, index+1, n);
            visited[i] = false;
        }
    }
}

int main() {
    //freopen("sample.in", "r", stdin);
    int n, test = 1;
    bool newline = false;

    generate_primes(prime);

    while (scanf("%d", &n) == 1) {
        if (newline) { printf("\n"); }
        newline = true;

        printf("Case %d:\n", test++);
        int a[n+1];
        bool visited[n+1];
        for (int i = 1; i <= n; i++) {
            visited[i] = false;
        }
        a[1] = 1;
        visited[1] = true;
        backtrack(a, visited, 2, n);

    }
    return 0;
}
