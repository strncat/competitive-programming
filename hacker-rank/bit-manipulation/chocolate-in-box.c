#include <stdio.h>

/* Chocolate in Box
solution: http://en.wikipedia.org/wiki/Nim
Constraints
1 ≤ N ≤ 10^6
1 ≤ A[i] ≤ 10^9
Sample Input
2
2 3
Sample Output
1
*/


int main() {

    int i, n, a[1000000], s[1000000];
    int sum, moves = 0;
    
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    
    sum = a[0] ^ a[1];
    for (i = 2; i < n; i++) {
        sum ^= a[i];
    }
    
    for (i = 0; i < n; i++) {
        s[i] = a[i] ^ sum;
        if (s[i] < a[i])
            moves++;
    }
    
    printf("%d\n", moves);
    
    return 0;
}
