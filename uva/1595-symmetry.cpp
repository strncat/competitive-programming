//
//  uva 1595 - Symmetry
//
//  Created by Fatima B on 10/18/15.
//  Copyright © 2015 nemo. All rights reserved.
//
//  not the shortest solution out there, after submitting this,
//  I saw some solutions that were really short and simple
//  here I just find first the middle point where line should be
//  After that I try to match each point, if I match it, I remove both
//  If I can't match it, that's an error I break
//

#include <iostream>
#include <algorithm>
#include <map>

typedef std::multimap<int,int> mymap;

int main() {
    int test_cases, n, x, y;

    scanf("%d", &test_cases);
    while(test_cases--) {
        scanf("%d", &n);
        mymap d;
        int min=100000, max=-100000;
        for (int i = 0; i < n; i++) {
            scanf("%d %d", &x, &y);
            d.insert(mymap::value_type(x, y));
            if (x < min) {
                min = x;
            }
            if (x > max) {
                max = x;
            }
        }

        if (n == 1) {
            printf("YES\n");
            continue;
        }

        double xbar = (min + max)/2.0;

        std::pair<mymap::iterator, mymap::iterator> range;
        for (mymap::iterator it = d.begin(); it != d.end(); ) {

            if (it->first == xbar) { // on the line
                it = d.erase(it);
                continue;
            }

            double distance = xbar - it->first;
            range = d.equal_range(xbar+distance);

            if (range.first == range.second) { // no element matched! error
                break;
            }

            mymap::iterator temp;
            for (temp = range.first; temp != range.second; ++temp) {
                if (temp->second == it->second) { // found a matching element
                    break;
                }
            }

            if (temp != d.end()) {
                d.erase(temp);
                it = d.erase(it);
            } else {
                ++it;
                break; /// no element matched! error
            }

        }

        if (d.empty()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
