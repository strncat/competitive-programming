#include <stdio.h>
#include <string.h>

/* 12527 - Different Digits
Sample Input
87 104
989 1022
22 25
1234 1234
Sample Output
14
0
3
1
*/

int main() {
    
    int i, j, a, b, count, temp;
    int d[4]; /* we only need 4 digits a and b are only [-1,5000] */
    
    while (scanf("%d %d", &a, &b) == 2) {
        
        count = 0;
        
        for (i = a; i <= b; i++) {
            
            d[0] = -1; d[1] = -2; d[2] = -3; d[3] = -4;
            
            temp = i;
            j = 0;
            while (temp > 0) {
                d[j++] = temp % 10;
                temp /= 10;
            }
            
            if (d[0] == d[1] || d[1] == d[2] || d[2] == d[3] || d[3] == d[0] || d[0] == d[2] || d[0] == d[3] || d[1] == d[3])
                ;
            else
                count++;
        }
        printf("%d\n", count);
    }
    return 0;
}