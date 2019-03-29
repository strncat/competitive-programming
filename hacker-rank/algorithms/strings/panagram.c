#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {

    char line[2000];
    int alpha[26];
    memset(alpha, 0, sizeof(alpha));

    fgets(line, sizeof(line), stdin);
    int length = (int) strlen(line);

    for (int i = 0; i < length; i++) {
        line[i] = tolower(line[i]);
        if (line[i] >= 'a' && line[i] <= 'z') {
            alpha[line[i]-'a']++;
        }
    }

    int panagram = 1;
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == 0) {
            panagram = 0;
        }
    }

    if (panagram) {
        printf("pangram\n");
    } else {
        printf("not pangram\n");
    }
    return 0;
}
