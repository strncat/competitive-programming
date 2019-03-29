#include <stdio.h>

/* Halloween party
maximum pieces 1x1 of cake, 2<=K<=10^7
Sample Input #00
4
5
6
7
8
Sample Output #00
6
9
12
16
*/


int main() {
    
    int test_cases, k;
    long long int w, h;
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%d", &k);
        
        w = k / 2;
        h = w;
        if (k % 2)
            w++;
        
        printf("%lld\n", w * h);
    }
    return 0;
}
