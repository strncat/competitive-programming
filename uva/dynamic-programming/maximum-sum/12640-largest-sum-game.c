#include <stdio.h>
#include <limits.h>

/* 12640 - Largest Sum Game
 Sample Input 1 2 3 4 5 6 7 8 9 -1 -1 -1 23 -1 -24 2 23 1 -14 -4 14 -11 -7 6 Sample Output 45 0 25 14
*/

/* solved using Kadane Algorithm */

int main() {

    int a, sum, max_sum, exit;
    char c;
    
    while (1) {
        
        sum = 0;
        max_sum = INT_MIN;
        
        while (1) {
            
            exit = scanf("%d%c", &a, &c);
            
            if (exit == -1)
                return 0;
            
            sum += a;
            
            if (sum < 0)
                sum = 0;
            
            if (sum > max_sum)
                max_sum = sum;
            
            if (c == '\n')
                break;
        }
        printf("%d\n", max_sum);
    }
    
    return 0;
}

