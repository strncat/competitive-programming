//
//  Reverse Words
//

#include <iostream>
#include <stdio.h>

void reverseWord(std::string& w, int first, int last) {
    for (int i = first, j = last; i < j; i++, j--) {
        char temp = w[i];
        w[i] = w[j];
        w[j] = temp;
    }
}

void reverseSentence(std::string& s) {
    int n = (int) s.length();
    reverseWord(s, 0, n - 1);
    int index = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') { // end of a word
            reverseWord(s, index, i - 1);
            index = i + 1; // begining of new word
        }
    }
    reverseWord(s, index, n - 1);
}

int main() {
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    std::string s;
    int tests;
    scanf("%d\n", &tests);
    for (int t = 1; t <= tests; t++) {
        getline(std::cin, s);
        reverseSentence(s);
        printf("Case #%d: %s\n", t, s.c_str());
    }
    return 0;
}
