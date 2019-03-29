//
//  main.cpp
//  uhunt
//
//  409 - Excuses, Excuses!
//  2017/02/04
//

#include <iostream>
#include <vector>

// find a word in a line
int find(std::string line, std::string keyword) {
    int line_size = (int)line.size();
    int keyword_size = (int)keyword.length();
    int matches = 0;
    int j = 0;
    for (int i = 0; i < line_size; i++) {
        // we matched the whole keyword already, now we need to make sure this char is not alphanumberic
        if (j == keyword_size) {
            if (!isalpha(line[i])) {
                matches++; // found a match
            }
            // otherwise we restart the search for the keyword for the next iteration
            // because we just matched the keyword and keywords are always alphanumeric
            j = 0;
        } else if (tolower(line[i]) != tolower(keyword[j])) { // check for match and restart if didn't match
            j = 0;
        } else if (j == 0 && i > 0 && isalpha(line[i-1])) { // this is a new search but the previous character is alphanumeric
            j = 0; // if not a valid begining keep it, don't advance
        } else { // this is a match, check for the next character of the keyword
            j++;
        }
    }
    if (j == keyword_size) { // final match at the end of the line
        matches++;
    }
    return matches;
}

int find_keywords(std::string line, std::vector<std::string> keywords) {
    int matches = 0;
    for (int i = 0; i < keywords.size(); i++) {
        matches += find(line, keywords[i]);
    }
    return matches;
}

int main() {
    //freopen("sample.in", "r", stdin);

    int K = 0, E = 0, n = 0;
    while(scanf("%d%d\n", &K, &E) == 2) { // or != EOF both work
        n++;
        std::string line, keyword; // max of 70 chars each
        std::vector<std::string> keywords;
        std::vector<std::string> lines;
        int count[33] = {0};

        // read each keyword
        for (int i = 0; i < K; i++) {
            getline(std::cin, keyword);
            keywords.push_back(keyword);
        }

        // read each line and then find all the keywords in that line
        int max = 0;
        std::string max_line = "";
        for (int i = 0; i < E; i++) {
            getline(std::cin, line);
            lines.push_back(line);
            count[i] = find_keywords(line, keywords);
            if (count[i] > max) {
                max = count[i];
                max_line = line;
            }
        }

        printf("Excuse Set #%d\n", n);
        for (int i = 0; i < lines.size(); i++) {
            if (count[i] == max) {
                printf("%s\n", lines[i].c_str());
            }
        }
        printf("\n");
    }
    return 0;
}
