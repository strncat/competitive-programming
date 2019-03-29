/*
 ID: fatima.1
 PROG: namenum
 LANG: C++11
 */
//
//  Usaco Training
//  1.2 Name That Number
//
// this is a bad solution .. I generated all possible words 3^12 = 531441 words while
// we only have 5000 words in the dictionary
// what I should've done is go thru the dictionary and see if it matches the digits in the question
// I added a method officialSolution

#include <iostream>
#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <fstream>

void officialSolution(std::vector<std::string> words, std::string s) {
    char map[256];
    map['A'] = map['B'] = map['C'] = '2';
    map['D'] = map['E'] = map['F'] = '3';
    map['G'] = map['H'] = map['I'] = '4';
    map['J'] = map['K'] = map['L'] = '5';
    map['M'] = map['N'] = map['O'] = '6';
    map['P'] = map['R'] = map['S'] = '7';
    map['T'] = map['U'] = map['V'] = '8';
    map['W'] = map['X'] = map['Y'] = '9';

    int solutions = 0;
    // now for each word in the dictionary, does it match s?
    for (auto w = words.begin(); w != words.end(); w++) {
        int j = 0;
        if (s.length() == w->length()) {
            for (j = 0; j < w->length(); j++) {
                if (map[(*w)[j]] != s[j]) {
                    break;
                }
            }
        }
        if (j == w->length()) {
            solutions++;
            printf("%s\n", w->c_str());
        }
    }
    if (!solutions) {
        printf("NONE\n");
    }
}

void generate(std::string s, int index, std::vector<std::string> &list, std::string result,
              std::unordered_map<int, std::vector<char>> letters,
              std::unordered_map<int, std::set<char>> dict) {
    if (index == s.length()) {
        list.push_back(result);
        return;
    }
    // all the options (letters) available for the current number
    for (auto t = letters[s[index]-'0'].begin(); t != letters[s[index]-'0'].end(); t++) {
        // prune early
        if (dict[index].count(*t)) {
            generate(s, index + 1, list, result + *t, letters, dict);
        }
    }
}

int main() {
    // letters we are allowed to use
    std::unordered_map<int, std::vector<char>> letters;
    letters[2] = {'A', 'B', 'C'};
    letters[3] = {'D', 'E', 'F'};
    letters[4] = {'G', 'H', 'I'};
    letters[5] = {'J', 'K', 'L'};
    letters[6] = {'M', 'N', 'O'};
    letters[7] = {'P', 'R', 'S'};
    letters[8] = {'T', 'U', 'V'};
    letters[9] = {'W', 'X', 'Y'};

    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);

    std::string s;
    std::cin >> s;

    // build dictionary of valid names only include eligible names

    std::vector<std::string> all;
    std::unordered_map<int, std::set<char>> dict;
    std::set<std::string> words;
    std::string d;
    std::ifstream file("dict.txt");
    while (file >> d) {
        if (d.length() == s.length()) {
            all.push_back(d);
            words.insert(d);
            for (int i = 0; i < d.length(); i++) {
                dict[i].insert(d[i]);
            }
        }
    }
    /*
    std::vector<std::string> list;
    generate(s, 0, list, "", letters, dict);
    bool none = true;

    for (auto t = list.begin(); t != list.end(); t++) {
        if (words.count(*t)) {
            std::cout << *t << std::endl;
            none = false;
        }
    }
    if (none) {
        std::cout << "NONE" << std::endl;
    }
    */
    officialSolution(all, s);
    return 0;
}
