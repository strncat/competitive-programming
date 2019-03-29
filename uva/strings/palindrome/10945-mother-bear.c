#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* 10945 - Mother bear [will only contain the letters A-Z, a-z, '.', ',', '!', '?'], ignoring case and punctuations
Sample Input
Madam, Im adam!
Roma tibi subito motibus ibit amor.
Me so hungry!
Si nummi immunis
DONE
 
Sample Output
You won't be eaten!
You won't be eaten!
Uh oh..
You won't be eaten!
*/

int main() {
    
    char line[50001];
    int n, i, length, mid, palindrome;
    
    while (fgets(line, 50000, stdin)) {
        
        length = (int) strlen(line);
        
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }
        
        if (strcmp(line, "DONE") == 0)
            break;
        
        /* only keep lower case letters */
        n = 0;
        for (i = 0; i < length; i++) {
            line[i] = tolower(line[i]);
            if (line[i] >= 'a' && line[i] <= 'z')
                line[n++] = line[i]; /* overwrite */
        }
        
        mid = n / 2;
        palindrome = 1;
        for (i = 0; i < mid; i++)
            if (line[i] != line[n - 1 - i]) {
                palindrome = 0;
                break;
            }
        
        if (palindrome)
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
    return 0;
}