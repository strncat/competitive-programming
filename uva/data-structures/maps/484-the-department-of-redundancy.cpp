//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/24/19.
//  484 - The Department of Redundancy 
//

#include <iostream>
#include <unordered_map>
#include <vector>

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    freopen("in.txt" , "r" , stdin);
    std::vector<int> a;

    int x;
    std::unordered_map<int,int> m;
    while (scanf("%d", &x) == 1) {
        if (m[x] == 0) {
            a.push_back(x);
        }
        m[x]++;

    }

    for (auto i = 0; i < a.size(); i++) {
        printf("%d %d\n", a[i], m[a[i]]);
    }


    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f", time_spent);
    return 0;
}
