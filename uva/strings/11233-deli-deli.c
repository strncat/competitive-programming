#include <stdio.h>
#include <string.h>

/* 11233 - Deli Deli 
 
 Sample Input
 
 3 7
 rice rice
 spaghetti spaghetti
 octopus octopi
 rice
 lobster
 spaghetti
 strawberry
 octopus
 peach
 turkey
 
 Sample Output
 rice
 lobsters
 spaghetti
 strawberries
 octopi
 peaches
 turkeys
 */

int main() {

    int i, j, total, n, found, length, l;
    char word[22][22], definition[22][22], w[22];
    
    scanf("%d %d", &total, &n);
    
    for (i = 0; i < total; i++)
        scanf("%s %s", word[i], definition[i]);
    
    for (i = 0; i < n; i++) {
        
        found = 0;
        scanf("%s", w);
        
        /* If the word is in the list of irregular words replace it with the given plural. */
        for (j = 0; j < total; j++)
            if (strcmp (w, word[j]) == 0) {
                printf("%s\n", definition[j]);
                found = 1;
                break;
            }
        if (!found) {
            length = (int) strlen(w);
            l = length - 1;
            
            /* Else if the word ends in a consonant followed by "y", replace "y" with "ies". */
            if (w[l - 1] != 'e' && w[l - 1] != 'a' && w[l - 1] != 'i' && w[l - 1] != 'o' && w[l - 1] != 'u' && w[l] == 'y') {
                w[l] = 'i';
                printf("%ses\n", w);
            }
            
            /* Else if the word ends in "o", "s", "ch", "sh" or "x", append "es" to the word. */
            else if (w[l] == 'o' || w[l] == 's' || w[l] == 'x' || (w[l] == 'h' && w[l - 1] == 's') || (w[l] == 'h' && w[l - 1] == 'c'))
                printf("%ses\n", w);
            
            /* Else append "s" to the word. */
            else
                printf("%ss\n", w);
        }
    }
    return 0;
}

