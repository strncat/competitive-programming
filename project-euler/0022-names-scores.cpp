//
//
//  Project Euler
//
//  Created by FB on 12/11/24.
//  22 Names Scores https://projecteuler.net/problem=22
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>
#define N 10001

int main(int argc, const char * argv[]) {
    freopen("0022_names.txt" , "r" , stdin);
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    std::unordered_map<char,int> map;

    std::string str;
    std::cin >> str;

    std::vector<std::string> names;
    std::stringstream ss(str);
    std::string token;
    char delimiter = ',';
    
    while (std::getline(ss, token, delimiter)) {
        names.push_back(token.substr(1, token.size() - 2));
    }

    std::sort(names.begin(), names.end());
    
    long long int sum = 0;
    for (int i = 0; i < names.size(); i++) {
        int score = 0;
        for (int j = 0; j < names[i].size(); j++) {
            score += names[i][j]-'A'+1;
        }
        score *= (i+1);
        std::cout << i+1 << " " << names[i] << " " << score << std::endl;
        sum += score;
    }
    
    printf("score sum = %lld\n", sum);

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}
