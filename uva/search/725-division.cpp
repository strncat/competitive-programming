//
//  main.cpp
//  uHunt
//
//  Created by FB on 7/01/19.
//  725 - Division
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

std::vector<std::string> solutions;
std::vector<std::pair<int,int>> permutations;

bool generate_solutions(int n) {
    bool sol = false;
    for (int i = 0; i < permutations.size(); i++) {
        if (permutations[i].first / permutations[i].second == n) {
            sol = true;
            if (permutations[i].first < 10000) {
                printf("0%d / ", permutations[i].first);
            } else {
                printf("%d / ", permutations[i].first);
            }
            if (permutations[i].second < 10000) {
                printf("0%d = %d\n", permutations[i].second, n);
            } else {
                printf("%d = %d\n", permutations[i].second, n);
            }
        }
    }
    return sol;
}

void generate_numbers(int pos, int *a, int n, int *sel, int m) {
    if (pos == n) {
        int num1, num2;
        num1 = a[0]+a[1]*10+a[2]*100+a[3]*1000+a[4]*10000;
        num2 = a[5]+a[6]*10+a[7]*100+a[8]*1000+a[9]*10000;
        if (num1 % num2 == 0) {
            permutations.push_back({num1, num2});
        }
    }
    // 10 digit number
    for (int j = 0; j < m; j++) {
        if (!sel[j]) { // not selected yet
            a[pos] = j;
            sel[j] = 1;
            generate_numbers(pos+1, a, n, sel, m);
            sel[j] = 0;
        }
    }
}

bool cmp(std::pair<int,int> &a, std::pair<int,int> &b) {
    if (a.first < b.first) { return true; }
    if (a.first > b.first) { return false; }
    // otherwise
    return a.second < b.second;
}

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    //freopen("in.txt" , "r" , stdin);

    // generate all valid permuations
    int a[10] = {0};
    int sel[10] = {0};
    generate_numbers(0, a, 10, sel, 10);
    std::sort(permutations.begin(), permutations.end());

    int n = 0;
    bool first = true;
    while(scanf("%d", &n) == 1) {
        solutions.clear();
        if (n == 0) { break; }
        if (first) {
            first = false;
        } else {
            printf("\n");
        }
        if (!generate_solutions(n)) {
            printf("There are no solutions for %d.\n", n);
        }
    }

    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f\n", time_spent); // 0.246944
    return 0;
}
