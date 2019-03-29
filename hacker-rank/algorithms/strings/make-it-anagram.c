#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Make it Anagram
Sample Input #00:
cde
abc
Sample Output #00:
4
*/

#define N 10003

int main() {
    
    char s[N];
    int i, n, delete = 0, letter[26] = {0};
    
    scanf("%s", s);
        
    n = (int) strlen(s);
    
    memset(letter, 0, sizeof(letter));
    
    for (i = 0; i < n; i++)
        letter[s[i] - 'a']++;
    
    scanf("%s", s);

    n = (int) strlen(s);
    
    for (i = 0; i < n; i++)
        letter[s[i] - 'a']--;
   
    for (i = 0; i < 26; i++)
        delete += abs(letter[i]);
    
    printf("%d", delete);
    
    return 0;
}