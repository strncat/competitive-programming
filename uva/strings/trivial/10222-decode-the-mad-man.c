#include <stdio.h>
#include <string.h>

/* 10222 - Decode the Mad man
 Sample Input
 k[r dyt I[o
 
 Sample Output
 how are you
 */

int main() {
    
    int i, decode[256];
    char c, keyboard[81] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
    
    for (i = 0; i < 81; i++)
       decode[keyboard[i]] = keyboard[i - 2];
    
    while ((c = getchar()) != EOF) {
        
        if (c == ' ' || c == '\n')
            putchar(c);
        
        else if (c >= 'A' && c <= 'Z') {
            c = c - 'A' + 'a';
            putchar(decode[c]);
        }
        else
            putchar(decode[c]);
    }
    return 0;
}