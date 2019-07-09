//
//  Sansa and XOR
//  find the value obtained by XOR-ing the contiguous subarrays,
//  [1 2 3] = 1⊕2⊕3⊕(1⊕2)⊕(2⊕3)⊕(1⊕2⊕3)=2
//
/* my solution
 for n = 3, the count for i, i+1, i+2 is
 1 1 1
 1 2 1
 1 1 1
 
 for n = 4 .... for n = 5
 1 1 1 1        1 1 1 1 1
 1 2 2 1        1 2 2 2 1
 1 2 2 1        1 2 3 2 1
 1 1 1 1        1 2 2 2 1
                1 1 1 1 1
 
 and so on, you see the pattern, in each iteration we add 1 to each decreasing 
 range starting with adding 1 to anything between (0, n) and then (1, n-1) and so on
 
 The editorial shows a closed formula I didn't know about and not using here
 the number of times an element will appear is actually (i + 1) * (n - i) much simpler
*/

#include <iostream>

void print(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int find_xor(int *a, int n) {
    int m = n/2;
    int xor_result = 0;
    int sum = 0;
    int offset = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = offset; j < n - offset; j++) {
            sum += 1;
        }
        if (sum & 1) {
            xor_result ^= a[offset];
            if (offset != n-offset-1) {
                xor_result ^= a[n-offset-1];
            }
        }
        offset++;
    }
    return xor_result;
}

void tests() {
    int a[3] = {1, 2, 3};
    int r = find_xor(a, 3);
    if (r != 2) {
        printf("failed test returned %d\n", r);
    }
    int b[4] = {4, 5, 7, 5};
    r = find_xor(b, 4);
    if (r != 0) {
        printf("failed test returned %d\n", r);
    }
    int c[5] = {1, 2, 3, 4, 5};
    r = find_xor(c, 5);
    if (r != 7) {
        printf("failed test returned %d\n", r);
    }
}

int main() {
    tests();
    int cases, n, a[100001];
    scanf("%d", &cases);

    while (cases--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
                scanf("%d", &a[i]);
        }
        std::cout << find_xor(a, n) << std::endl;
    }
    return 0;
}
