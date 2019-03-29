#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* 417 - Word Index
 Sample Input
 z
 a
 cat
 vwxyz
 Sample Output
 26
 1
 0
 83681
*/

char dict[85000][6];

int main() {
    
    char i, j, k, l, m, word[100];
    int counter = 1, index, found;
    
    for (i = 'a'; i <= 'z'; i++) {
        sprintf(word, "%c", i);
        strcpy(dict[counter++], word);
    }
    
    for (i = 'a'; i <= 'z'; i++)
        for (j = i + 1; j <= 'z'; j++) {
            sprintf(word, "%c%c", i, j);
            strcpy(dict[counter++], word);
        }

    for (i = 'a'; i <= 'z'; i++)
        for (j = i + 1; j <= 'z'; j++)
            for (k = j + 1; k <= 'z'; k++) {
                sprintf(word, "%c%c%c", i, j, k);
                strcpy(dict[counter++], word);
            }
    
    for (i = 'a'; i <= 'z'; i++)
        for (j = i + 1; j <= 'z'; j++)
            for (k = j + 1; k <= 'z'; k++)
                for (l = k + 1; l <= 'z'; l++) {
                    sprintf(word, "%c%c%c%c", i, j, k, l);
                    strcpy(dict[counter++], word);
                }
                
    for (i = 'a'; i <= 'z'; i++)
        for (j = i + 1; j <= 'z'; j++)
            for (k = j + 1; k <= 'z'; k++)
                for (l = k + 1; l <= 'z'; l++)
                    for (m = l + 1; m <= 'z'; m++) {
                        sprintf(word, "%c%c%c%c%c", i, j, k, l, m);
                        strcpy(dict[counter++], word);
                    }
    
    while (scanf("%s", word) == 1) {
        
        found = 0;
        for (index = 0; index < counter; index++)
            if (strcmp(word, dict[index]) == 0) {
                found = 1;
                printf("%d\n", index);
                break;
            }
        if (!found)
            printf("0\n");
    }
    return 0;
}