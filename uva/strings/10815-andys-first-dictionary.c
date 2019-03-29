#include <stdio.h>
#include <string.h>
#include <ctype.h> /* tolower */
#include <stdlib.h> /* qsort */

/* 10815 - Andy's First Dictionary */

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

    char c;
    char s[5000][201];
    char temp[201];
    int i = 0, n = 0;
    
    while ( (c = getc(stdin)) != EOF ) {
        
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) /* a word = consecutive sequence of alphabets */
            temp[i++] = tolower(c);
        else if (i > 0) {
            temp[i] = '\0';
            i = 0;
            if (find_string(s, temp, n) == 1)
                strcpy(s[n++], temp);
        }
    }
    
    qsort(s, n, 201, compare_strings);
    
    for (i = 0; i < n; i++)
        printf("%s\n", s[i]);
    
    return 0;
}

