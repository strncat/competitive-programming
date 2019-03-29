#include <stdio.h>
#include <string.h>
/* 11530 - SMS Typing
Input
3
welcome to ulab
good luck and have fun
  a
 
Output:
Case #1: 29
Case #2: 41
Case #3: 3
*/

int main() {
    
    int i, test_cases, count;
    char ascii[256] = {0}, c, dummy[10];
    ascii['a'] = ascii['d'] = ascii['g'] = ascii['j'] = ascii['m'] = ascii['p'] = ascii['t'] = ascii['w'] = ascii[' '] = 1;
    ascii['b'] = ascii['e'] = ascii['h'] = ascii['k'] = ascii['n'] = ascii['q'] = ascii['u'] = ascii['x'] = 2;
    ascii['c'] = ascii['f'] = ascii['i'] = ascii['l'] = ascii['o'] = ascii['r'] = ascii['v'] = ascii['y'] = 3;
    ascii['s'] = ascii['z'] = 4;
    
    scanf("%d", &test_cases);
    fgets(dummy, 10, stdin); /* PAY ATTENTION TO THIS, DOING SCANF("%d\n") DOESN'T WORK */
    
    for (i = 1; i <= test_cases; i++) {
        
        count = 0;
        
        while ((c = getchar()) != '\n')
            if (c >= ' ' && c <= 'z')
                count += ascii[c];

        printf("Case #%d: %d\n", i, count);
    }
    return 0;
}