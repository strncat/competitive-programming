#include <stdio.h>
#include <string.h>

/* UVa - [483 - Word Scramble]
 Sample Input
 I love you.
 You love me.
 We're a happy family.
 
 Sample Output
 I evol .uoy
 uoY evol .em
 er'eW a yppah .ylimaf
*/

void reverse(char *str, int begin, int end) {
    
    char *p = &str[begin], *q = &str[end], temp;
    
    while (p < q) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
}

int main() {
    
    char line[2000];
    int i, prev, length;
    
    while (fgets(line, 2000, stdin)) { /* == NULL */
        
        length = (int) strlen(line);
        
        i = 0;
        prev = 0;
        
        for (i=0; i<length; i++)
            if (line[i] == ' ') {
                reverse(line, prev, i-1);
                prev = i+1;
            }
        reverse(line, prev, i-2);
        
        printf("%s", line);
    }
    return 0;
}
