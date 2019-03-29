#include <stdio.h>
#include <string.h>
#include <ctype.h> /* tolower */
#include <stdlib.h> /* qsort */

/* 11062 Andy's Second Dictionary */

int compare_strings(void const *a, void const *b) {
    
    char const *aa = (char const *)a;
    char const *bb = (char const *)b;
    
    return strcmp(aa, bb);
}

int find_string(char s[5000][201], char temp[201], int n) {
    
    int i;
    
    for (i = 0; i < n; i++) {
        if (strcmp(s[i], temp) == 0)
            return -1;
    }
    return 1;
}

int main() {

    char c, prev = 0;
    char s[5000][201];
    char temp[201];
    int i = 0, n = 0, incomplete = 0;
    
    while ( (c = getc(stdin)) != EOF ) {
        
        /* two cases */
        if (c != '\n' && prev == '-')  /* it is part of the word */
            temp[i++] = '-';
        
        else if (c == '\n' && prev == '-') { /* it is not part of the word */
            incomplete = 1; /* word is not yet complete */
        }
        
        if (c == '-')  /* will treat this case in the next iteration */
            prev = '-';
        
        else /* reset */
            prev = 0;
 
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            temp[i++] = tolower(c);
        
        else if (i > 0 && !incomplete && c != '-') {
            temp[i] = '\0';
            i = 0;
            if (find_string(s, temp, n) == 1)
                strcpy(s[n++], temp);
        }
        incomplete = 0;
    }
    
    qsort(s, n, 201, compare_strings);
    
    for (i = 0; i < n; i++)
        printf("%s\n", s[i]);
    
    return 0;
}

