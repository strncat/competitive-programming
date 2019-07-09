//
//  Hacker Rank
//  Cutting boards
//
//  Created by Fatima B on 01/01/16.
//  Copyright © 2015 Fatima B. All rights reserved.
/*
    (1) we initialize vertical_count = 1 and horizontal_count = 1
    (2) we sort both lists
    (3) loop until we use every cost:
          we choose the highest value of h and v
          assume it was h[i] (a horizontal cut), we then:
           (1) increment horizontal_count
           (2) we add h[i] a number of times = vertical_counts

           so for example if we have two vertical cuts already: (vertical_count = 3)
           ----------
           |  |  |  |
           ----------
           then we need to cut horizontally three pieces = vertical_counts
*/

#include <iostream>
#include <algorithm>
#include <vector>

#define LARGE 1000000007

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int m, n;
        std::vector<long> h, v;
        long horizontal_count = 1, vertical_count = 1, temp, sum = 0;

        scanf("%d %d", &m, &n);
        for (int i = 0; i < m-1; i++) {
            scanf("%ld", &temp);
            h.push_back(temp);
        }
        for (int i = 0; i < n-1; i++) {
            scanf("%ld", &temp);
            v.push_back(temp);
        }

        // sort both lists!
        std::sort(h.rbegin(), h.rend());
        std::sort(v.rbegin(), v.rend());


        int i = 0, j = 0;
        while (i < h.size() && j < v.size()) {
            if (h[i] > v[j]) {
                sum = (sum + (vertical_count*h[i]))%LARGE;
                i++; horizontal_count++;
            } else {
                sum = (sum + (horizontal_count*v[j]))%LARGE;
                j++; vertical_count++;
            }
        }

        while (i < h.size()) {
            sum = (sum + (vertical_count*h[i]))%LARGE;
            i++; horizontal_count++;
        }

        while (j < v.size()) {
            sum = (sum + (horizontal_count*v[j]))%LARGE;
            j++; vertical_count++;
        }

        printf("%ld\n", sum);
    }
    return 0;
}
