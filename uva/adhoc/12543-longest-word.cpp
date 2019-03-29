//
//  UVa
//  12543 - Longest Word
//

#include <iostream>
#include <string.h>

int main() {
    //freopen("sample.in", "r", stdin);

    int max = 0;
    char s[200], m[200];

    while(scanf("%s",s)) {
        if (strcmp(s, "E-N-D") == 0) {
            break; // end of text
        }
        
        // otherwise, is it the longest string?
        int n = (int)strlen(s);
        int i = 0;
        int total = 0;
        for (i = 0; i < n; i++) {
            if ((s[i] <= 'z' && s[i] >= 'a') ||
                (s[i] >= 'A' && s[i] <= 'Z') ||
                 s[i] == '-') {
                total++;
            }
        }
        if (total > max) {
            max = total;
            strcpy(m, s);
        }
    }
    // Print out the longest word in small letters.
    int n = (int)strlen(m);
    for (int i = 0; i < n; i++) {
        if ((m[i] <= 'z' && m[i] >= 'a') ||
            (m[i] >= 'A' && m[i] <= 'Z') ||
            m[i] == '-') {
            printf("%c", tolower(m[i]));
        }
    }
    printf("\n");
    return 0;
}
