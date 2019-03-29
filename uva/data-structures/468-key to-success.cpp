//
//  main.cpp
//  uhunt
//
//  468 - Key to Success
//  2017/02/21
//
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

bool custom_sort(const std::pair<char,int>& a, const std::pair<char,int>& b) {
    if (a.second > b.second) {
        return true;
    }
    return false;
}

int main() {
    //freopen("sample.in", "r", stdin);
    int n;
    scanf("%d\n", &n);
    while(n--) {
        std::string ref, line;
        std::getline(std::cin, ref);
        std::getline(std::cin, line);
        scanf("\n");

        // count the frequency of each letter in both the reference and the line
        int cref[100] = {0};
        for (int i = 0; i < ref.size(); i++) {
            if (isalpha(ref[i])) {
                cref[ref[i]-65]++; // A=65, a=97
            }
        }

        int cline[100] = {0};
        for (int i = 0; i < line.size(); i++) {
            if (isalpha(line[i])) {
                cline[line[i]-65]++;
            }
        }

        // insert back these frequences in vectors to have something like [{a,4}, {c,11} ...]
        std::vector<std::pair<char,int>> ref_count, line_count;
        for (int i = 0; i < 100; i++) {
            if (cref[i]) { ref_count.push_back(std::pair<char,int>(i+'A',cref[i])); }
            if (cline[i]) { line_count.push_back(std::pair<char,int>(i+'A',cline[i])); }
        }

        // sort
        std::sort(ref_count.begin(), ref_count.end(), custom_sort);
        std::sort(line_count.begin(), line_count.end(), custom_sort);


        // assuming that every letter will map to some other letter
        std::unordered_map<char, char> m;
        for (int i = 0; i < line_count.size(); i++) {
            m[line_count[i].first] = ref_count[i].first;
        }

        // finally decode
        std::string result = "";
        for (int i = 0; i < line.size(); i++) {
            if ((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
                printf("%c",m[line[i]]);
            } else {
                printf("%c", line[i]);
            }
        }
        printf("\n");
        if (n) {
            printf("\n");
        }
    }
    return 0;
}