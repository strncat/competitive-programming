//
//  main.cpp
//  uhunt
//
//  489 - Hangman Judge
//  2017/02/20
//
//

#include <iostream>
#include <string.h>

int main() {
    //freopen("sample.in", "r", stdin);
    int n;
    char s[1000], answer[1000];
    bool c[26], b[26];

    while(scanf("%d", &n) == 1 && n != -1) {
        scanf("%s\n%s", answer, s); // both lower case

        memset(c, false, sizeof(c));
        memset(b, false, sizeof(b));

        int alen = (int)strlen(answer);
        for (int i = 0; i < alen; i++) {
            c[answer[i]-97] = b[answer[i]-97] = true; // a=97
        }

        int strike = 0;
        int slen = (int)strlen(s);
        for (int i = 0; i < slen; i++) {
            if (b[s[i]-'a'] == false) { // guessed a wrong character
                strike++;
                b[s[i]-'a'] = true; // if we guessed wrong again, we should not strike again so we set it to true
            } else {
                c[s[i]-'a'] = false; // This is a correct guess, we use this array later to check if have a solution
            }
            if (strike >= 7) { break; } // important because it is possible that guess correctly after we run out of strikes so we need to exit
        }

        printf("Round %d\n", n);

        int i = 0;
        for (; i < 26; i++) {
            // some letters are still left .... possible chickening
            if (c[i]) { break; }
        }

        if (i == 26) { // everything was guessed correctly
            printf("You win.\n");
        } else if (strike >= 7) {
            printf("You lose.\n");
        } else {
            printf("You chickened out.\n");
        }
    }
    return 0;
}