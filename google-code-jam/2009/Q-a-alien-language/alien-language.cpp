//
//  Scalar Product
//

#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>

void filterDictionary(std::vector<std::string>& dictionary, std::string c, int index) {
    for (auto t = dictionary.begin(); t != dictionary.end();) {
        bool deleteFlag = true;
        for (int i = 0; i < c.length(); i++) {
            if ((*t)[index] == c[i]) {
                deleteFlag = false;
                break;
            }
        }
        if (deleteFlag) {
            dictionary.erase(t);
        } else {
            t++;
        }
    }
}

long possibleWords(std::vector<std::string> dictionary, std::string& pattern, int L) {
    int index = 0;
    for (int i = 0; i < pattern.length(); i++) {
        if (pattern[i] == '(') {
            std::string characters;
            i++; // first character after '('
            while (pattern[i] != ')') { // get all valid characters
                characters += std::string(1, pattern[i]);
                i++;
            }
            filterDictionary(dictionary, characters, index++); // remove anything that doesn't match

        } else { // a one character match
            filterDictionary(dictionary, std::string(1,pattern[i]), index++);
        }
    }
    return dictionary.size();
}

int main() {
    freopen("in.txt" , "r" , stdin);
    freopen("out.txt" , "w" , stdout);

    int tests, L, D;
    scanf("%d %d %d", &L, &D, &tests);

    std::vector<std::string> dictionary;
    std::string word, pattern;

    for (int i = 0; i < D; i++) { // load dictionary
        std::cin >> word;
        dictionary.emplace_back(word);
    }

    for (int t = 1; t <= tests; t++) {
        std::cin >> pattern;
        printf("Case #%d: %ld\n", t, possibleWords(dictionary, pattern, L));
    }
    return 0;
}
