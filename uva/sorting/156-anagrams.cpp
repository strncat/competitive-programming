//
//  main.cpp
//  uhunt
//
//  156 - Ananagrams
//  2017/02/27
//
//

#include <iostream>
#include <algorithm>
#include <vector>

typedef struct word {
    std::string w;
    std::string sorted;
    bool anagram;
    word(char *s) {
        w = sorted = std::string(s);
        anagram = false;
        std::transform(sorted.begin(), sorted.end(), sorted.begin(), ::tolower);
        std::sort(sorted.begin(), sorted.end());
    }
} word;

int main() {
    //freopen("sample.in", "r", stdin);
    char s[25];
    std::vector<word> a;
    std::vector<std::string> sorted;
    while (scanf("%s", s)) {
        if (s[0] == '#') { break; }
        a.push_back(word(s));
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = i+1; j < a.size(); j++) {
            if (a[i].sorted == a[j].sorted) {
                a[i].anagram = true;
                a[j].anagram = true;
            }
        }
    }
    for (int i = (int)a.size()-1; i >= 0; i--) {
        if (!a[i].anagram) {
            sorted.push_back(a[i].w);
        }
    }
    std::sort(sorted.begin(), sorted.end());
    for (int i = 0; i < (int)sorted.size(); i++) {
        std::cout << sorted[i] << std::endl;
    }
    return 0;
}
