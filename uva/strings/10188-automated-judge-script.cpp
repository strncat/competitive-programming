//
//  main.cpp
//  uhunt
//
//  10188 - Automated Judge Script
//  2017/03/20
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <string.h>

using std::string;
using std::vector;
using std::unordered_map;

int main() {
    //freopen("sample.in", "r", stdin);

    int n, m, t = 1;
    while (scanf("%d", &n) && n != 0) {
        getchar(); // scanf("%d\n") instead of getchar() gives WA? WHY?
        string judge, team, judgeNumeric, teamNumeric;
        char line[200];

        for (int i = 0; i < n; i++) {
            fgets(line, 150, stdin);
            judge += line;
            for (int j = 0; j < strlen(line); j++) {
                if (isdigit(line[j])) {
                    judgeNumeric += line[j];
                }
            }
        }

        scanf("%d", &m);
        getchar();
        for (int i = 0; i < m; i++) {
            fgets(line, 150, stdin);
            team += line;
            for (int j = 0; j < strlen(line); j++) {
                if (isdigit(line[j])) {
                    teamNumeric += line[j];
                }
            }
        }

        if (n == m && judge == team) { // exact match
            printf("Run #%d: Accepted\n", t++);
        } else if (judgeNumeric == teamNumeric) { // numeric match only
            printf("Run #%d: Presentation Error\n", t++);
        } else {
            printf("Run #%d: Wrong Answer\n", t++);
        }
    }
    return 0;
}
