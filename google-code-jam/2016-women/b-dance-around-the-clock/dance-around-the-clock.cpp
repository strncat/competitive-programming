//
//  https://code.google.com/codejam/contest/8274486/dashboard#s=p1
//  Problem B. Dance Around The Clock
//
//  Created by Fatima Broom on 3/12/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>

/* example d = 4
       1    2     3     4
 n=1   2    1     4     3
 n=2   3    4     1     2
 n=3   4    3     2     1
 n=4   1    2     3     4
 when n=d we complete a cycle
*/

int find_position(int k, int d, int n) { // find a position given a dancer
    int position = 0;
    if (k % 2) { // ODD
        position = k + n;
        if (position > d) { position %= d; }
    } else { // EVEN
        position = k - n;
        if (position <= 0) { position += d; }
    }
    return position;
}

int find_dancer(int position, int k, int d, int n) { // find a dancer given a position
    int dancer = 0;
    if (k % 2 == 0) { // if k is even then the dancer is odd
        dancer = position - n;
        if (dancer <= 0) {
            dancer += d;
        }
        if (dancer > d) {
            dancer %= d;
        }
    } else { // EVEN
        dancer = position + n;
        if (dancer > d) {
            dancer %= d;
        }
        if (dancer <= 0) {
            dancer += d;
        }
    }
    return dancer;
}

int main() {
    freopen("in-large.txt", "r", stdin);
    //freopen("out-large.txt", "w", stdout);

    int tests;
    scanf("%d\n", &tests);

    for (int t = 1; t <= tests; t++) {
        int d, k, n;
        scanf("%d %d %d", &d, &k, &n);

        n = n % d; // because after d we just repeat the same cycle

        // first figure out where k will be
        int kpos = find_position(k, d, n);

        // using k's position let's find who sits next to k
        int kminus = find_dancer(kpos-1, k, d, n);
        int kplus = find_dancer(kpos+1, k, d, n);

        printf("Case #%d: %d %d\n", t, kplus, kminus);
    }
    return 0;
}
