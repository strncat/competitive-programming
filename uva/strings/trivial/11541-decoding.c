#include <stdio.h>

/* 11541 - Decoding
 Sample Input
 3
 A2B4D1A2
 A12
 A1B1C1D1
 Output for Sample Input
 Case 1: AABBBBDAA
 Case 2: AAAAAAAAAAAA
 Case 3: ABCD
*/

int main() {

    int test_cases, i, j, n;
    char c;
    
    scanf("%d\n", &test_cases);
    
    for (i = 1; i <= test_cases; i++) {
    
        printf("Case %d: ", i);
        
        while (1) {
            
            c = getchar();
            
            if (c == EOF)
                break;
            
            else if (c == '\n') {
                putchar(c);
                break;
            }
            
            else {
                scanf("%d", &n);
                for (j = 0; j < n; j++)
                    printf("%c", c);
            }
        }
    }
    return 0;
}
