//
//
//  Project Euler
//
//  Created by FB on 01/18/25.
//  42 Coded Triangle Numbers https://projecteuler.net/problem=42
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#include <cassert>

#define N 10000
int triangle[N];
std::unordered_map<int,int> is_valid_term;

void triangle_sequence(int max) {
    for (int n = 1; n <= max; n++) {
        int term = (n * (n+1)) / 2;
        triangle[n] = term; // so triangle[10] = 55
        is_valid_term[triangle[n]] = 1; // is_triangle[55] is a term in the sequence
    }
}

int main(int argc, const char * argv[]) {
    freopen("0042_words.txt" , "r" , stdin);
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    std::string str;
    std::cin >> str; // read the entire string

    std::vector<std::string> words;
    std::stringstream ss(str);
    std::string token;
    char delimiter = ',';
    
    int max_length = 0;
    while (std::getline(ss, token, delimiter)) {
        std::string word = token.substr(1, token.size() - 2);
        words.push_back(word);
        if (word.length() > max_length) {
            max_length = word.length();
        }
    }
    int max_score = 26 * max_length;
    triangle_sequence(max_score);
    
    int count = 0;
    for (int i = 0; i < words.size(); i++) {
        int score = 0;
        for (int j = 0; j < words[i].size(); j++) {
            score += words[i][j]-'A'+1;
        }
        if (is_valid_term[score]) {
            count++;
        }
    }
    printf("triangle terms count = %d\n", count);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}

