//
//  main.cpp
//  uHunt
//
//  Created by FB on 6/30/19.
//  11572 - Unique Snowflakes
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>

int main(int argc, const char * argv[]) {
    //clock_t begin, end;
    //double time_spent;
    //begin = clock();
    //freopen("in.txt" , "r" , stdin);

    int tests;
    scanf("%d", &tests);

    while (tests--) {
        int n;
        scanf("%d", &n);

        // map is used to keep track of the snowflakes indices
        std::unordered_map<int,int> map;
        std::vector<int> snowflakes;
        int c;

        for (int i = 0; i < n; i++) {
            scanf("%d", &c);
            snowflakes.push_back(c);
        }

        int cur = 0, max = 0;
        for (int i = 0; i < n; i++) {
            if (map.find(snowflakes[i]) != map.end()) {
                // repeated snowflake, let's restart the search
                i = map[snowflakes[i]] + 1; // restart right after the repeated element
                map.clear(); // clear map of indices
                if (cur > max) { // update max
                    max = cur;
                }
                cur = 0; // reset current length
            }
            map[snowflakes[i]] = i; // save the index in map
            cur++;
        }
        // last update
        if (cur > max) { max = cur; }

        printf("%d\n", max);
    }

    //end = clock();
    //time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    //printf("%f", time_spent);
    return 0;
}
