#include <stdio.h>
#include <stdlib.h>

/* 12602 - Nice Licence Plates
 Sample Input
 2
 ABC-0123
 AAA-9999
 Sample Output
 nice
 not nice
*/

int main() {

    int test_cases, letter_sum, sum;
    char letter[5];
    
    scanf("%d", &test_cases);
    
    while (test_cases--) {
        
        scanf("%3s-%d", letter, &sum);
        
        letter_sum = (letter[0] - 'A') * 26 * 26;
        letter_sum += (letter[1] - 'A') * 26;
        letter_sum += (letter[2] - 'A');
        
        if (abs(sum - letter_sum) <= 100)
            printf("nice\n");
        else
            printf("not nice\n");
    }
    return 0;
}