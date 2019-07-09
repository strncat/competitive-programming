#include <stdio.h>

/* Maximizing XOR
1 ≤ L ≤ R ≤ 10^3
Sample Input
1
10
Sample Output
15
*/

int main() {
    
    int L, R;
    long int max;
    
    scanf("%d %d", &L, &R);
    max = L ^ R;
    
    for (int i = L; i < R; i++)
        for (int j = i; j < R; j++)
            if ((i ^ j) > max)
                max = i ^ j;
    printf("%ld\n", max);
    
    return 0;
}
