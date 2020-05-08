//
//  main.cpp
//  uhunt
//
//  628 - Passwords
//  2017/03/03
//
//

#include <iostream>
#include <vector>

using std::vector;
using std::string;

void generate_passwords(vector<string>& dictionary, vector<char> digits,
                        vector<string>& passwords, string& pattern,
                        string &s, int k) {
    if (pattern.size() == k) {
        passwords.push_back(s);
        return;
    }
    if (pattern[k] == '0') { // digit
        for (int i = 0; i < digits.size(); i++) {
            s.push_back(digits[i]);
            generate_passwords(dictionary, digits, passwords, pattern, s, k+1);
            s.pop_back();
        }
    }

    if (pattern[k] == '#') { // word
        for (int i = 0; i < dictionary.size(); i++) {
            s.append(dictionary[i]);
            generate_passwords(dictionary, digits, passwords, pattern, s, k+1);
            int t = (int) dictionary[i].size();
            while (t--) { s.pop_back(); }
        }
    }
}

int main() {
    //freopen("sample.in", "r", stdin);
    vector<char> digits = {'0','1','2','3','4','5','6','7','8','9'};
    int m, n;
    while (scanf("%d", &n) == 1) {
        vector<string> dictionary;
        string s, pattern;

        printf("--\n");

        for (int i = 0; i < n; i++) {
            std::cin >> s;
            dictionary.push_back(s);
        }

        scanf("%d", &m);
        for (int i = 0; i < m; i++) {
            vector<string> passwords;
            string s = "";
            std::cin >> pattern;

            generate_passwords(dictionary, digits, passwords, pattern, s, 0);
            for (int i = 0; i < passwords.size(); i++) {
                std::cout << passwords[i] << std::endl;
            }
        }
    }
    return 0;
}