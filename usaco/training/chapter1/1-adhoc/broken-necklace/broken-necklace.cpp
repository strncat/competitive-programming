/*
 ID: fatima.1
 PROG: beads
 LANG: C++11
 */
//
//  Usaco Training
//  1.1 Broken Necklace
//

#include <iostream>
#include <stdio.h>
#include <vector>

int main() {
    freopen("beads.in", "r", stdin);
    //freopen("beads.out", "w", stdout);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = s + s;

    int i = 0, len = 0, max = 0;
    char a = s[i];
    i++;

    // initially count the maximum length of repeated characters (+w)
    while (i < n+n && (s[i] == a || s[i] == 'w')) {
        i++;
    }
    len = i;
    max = len; // intially this is the max length

    while (i < n+n) {
        int j = i;
        a = s[j];
        // calculate the next length of repeated characters (+w)
        while (j < n+n && (s[j] == a || s[j] == 'w')) {
            j++;
        }

        // is the length of the two pieces > max?
        if (len + (j - i) > max) {
            max = len + j - i;
        }
        len = j - i;

        // before moving on add w's to the current length
        // this to take into account this case: rrwbbbrrr rrwbbb is of length 6
        // wbbbrrr has the maximum length = 7 so we need to count w again
        i--;
        while (i >= 0 && s[i] == 'w') {
            len++;
            i--;
        }
        i = j;
    }
    printf("%d\n", (max > n ?  n : max));
    return 0;
}
