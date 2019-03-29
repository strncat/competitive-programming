//
//  main.cpp
//  uhunt
//
//  10010 - Where's Waldorf?
//  2017/02/10
//

#include <iostream>
#include <string.h>

char a[52][52];

void find_word(int m, int n, char *word, int wlen) {
    // for each cell try the 8 different directions
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            // right
            int k = 0;
            while (k < wlen && j+k < n && word[k] == a[i][j+k]) {
                k++;
            }
            if (k == wlen) { // found the word at position i,j
                printf("%d %d\n", i+1, j+1);
                return;
            }

            // left
            k = 0;
            while (k < wlen && j-k >= 0 && word[k] == a[i][j-k]) {
                k++;
            }
            if (k == wlen) { // found the word at position i,j
                printf("%d %d\n", i+1, j+1);
                return;
            }

            // up
            k = 0;
            while (k < wlen && i-k >= 0 && word[k] == a[i-k][j]) {
                k++;
            }
            if (k == wlen) { // found the word at position i,j
                printf("%d %d\n", i+1, j+1);
                return;
            }

            // down
            k = 0;
            while (k < wlen && i+k < m && word[k] == a[i+k][j]) {
                k++;
            }
            if (k == wlen) { // found the word at position i,j
                printf("%d %d\n", i+1, j+1);
                return;
            }

            // left/up diagnoal
            k = 0;
            while (k < wlen && i-k >= 0 && j-k >= 0 && word[k] == a[i-k][j-k]) {
                k++;
            }
            if (k == wlen) { // found the word at position i,j
                printf("%d %d\n", i+1, j+1);
                return;
            }

            // left/down diagonal
            k = 0;
            while (k < wlen && i+k < m && j-k >= 0 && word[k] == a[i+k][j-k]) {
                k++;
            }
            if (k == wlen) { // found the word at position i,j
                printf("%d %d\n", i+1, j+1);
                return;
            }

            // right/up diagonal
            k = 0;
            while (k < wlen && i-k >= 0 && j+k < n && word[k] == a[i-k][j+k]) {
                k++;
            }
            if (k == wlen) { // found the word at position i,j
                printf("%d %d\n", i+1, j+1);
                return;
            }

            // right/down diagonal
            k = 0;
            while (k < wlen && i+k < m && j+k < n && word[k] == a[i+k][j+k]) {
                k++;
            }
            if (k == wlen) { // found the word at position i,j
                printf("%d %d\n", i+1, j+1);
                return;
            }
        }
    }
}

int main() {
    //freopen("sample.in", "r", stdin);
    int test_cases;
    scanf("%d", &test_cases);

    for (int t = 0; t < test_cases; t++) {
        int n, m;
        scanf("%d %d", &m, &n);
        for (int i = 0; i < m; i++) {
            scanf("%s", a[i]);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = tolower(a[i][j]);
            }

        }
        //for (int i = 0; i < m; i++) { printf("%s\n", a[i]); }

        int k;
        scanf("%d", &k);

        for (int i = 0; i < k; i++) {
            char word[52];
            scanf("%s", word);
            //printf("%s\n", word);
            for (int j = 0; j < strlen(word); j++) {
                word[j] = tolower(word[j]);
            }
            find_word(m, n, word, (int)strlen(word));
        }
        if (t < test_cases-1) {
            printf("\n");
        }
    }
    return 0;
}
