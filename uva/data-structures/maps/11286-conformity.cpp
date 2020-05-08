//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/30/19.
//  11286 - Conformity
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    //freopen("in.txt" , "r" , stdin);

    int n, c;
    while (scanf("%d", &n) == 1) {
        if (n == 0) { break; }

        std::unordered_map<std::string, int> combos;
        std::vector<int> combos_freq;

        for (int i = 0; i < n; i++) {
            std::vector<int> classes;
            std::string s;
            s = "";
            // read student classes
            for (int j = 0; j < 5; j++) {
                scanf("%d", &c);
                classes.push_back(c);
            }
            std::sort(classes.begin(), classes.end());


            // check if this combo exists
            for (int j = 0; j < 5; j++) {
                s.append(std::to_string(classes[j]));
            }
            combos[s]++;
        }

        int max = -1;
        for (auto i = combos.begin(); i != combos.end(); i++) {
            if (i->second > max) {
                max = i->second;
            }
        }

        int total_students = 0;
        for (auto i = combos.begin(); i != combos.end(); i++) {
            if (i->second == max) {
                total_students += max;
            }
        }

        printf("%d\n", total_students);
    }

    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f", time_spent);
    return 0;
}
