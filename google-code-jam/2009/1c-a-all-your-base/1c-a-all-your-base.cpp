//
//  jam template
//
//  Created by Fatima Broom on 2/27/16.
//  Copyright  2016 Fatima Broom. All rights reserved.
//
/*
 Given a string cats
 How can we represent this number in any base we want such that it gives us
 the minimum number possible?
 
 The minimum possible number will definitely come from using a greedy approach
 give the most significant digit 0, the one after 1 and so on
 so cats will be represented by 0123
 but the problem says that a number can't start with 0 so we flip 0 and 1 in the number
 and we get the representation 1023 in base 4
 
 Now we just convert from base 4 to base 10 to know value of the number
 in this case 1023 = 1*4^3 + 0*4^2 + 2*4^1 + 3*4^0 = 75
*/


#include <iostream>
#include <unordered_map>
#include <time.h>
#include <assert.h>

int main() {
    // measure time
    clock_t begin, end;
    double time_spent;
    begin = clock();

    freopen("in-large.txt" , "r" , stdin);
    freopen("out-large.txt" , "w" , stdout);

    int n;
    scanf("%d", &n);

    for (int t = 1; t <= n; t++) {
        // take the input string
        std::string s;
        std::cin >> s;
        int length = (int) s.length();

        // this map will hold each character with its digit value
        std::unordered_map<char, int> map;
        map[s[0]] = 1; // give the first character in the string a digit value of 1
        int count = 1; // the number of unique characters in the string
        int d = 0;

        for (int i = 1; i < length; i++) {
            if (map.find(s[i]) == map.end()) { // this is new character, it needs a new digit
                map[s[i]] = d++; // give it a new digit
                count++;
                if (d == 1) {
                    d++; // skip the digit value "1" because we already used it
                }
            }
        }

        // determine the base, since we can't have unary
        // it's at least 2 or the the number of unique characters
        int base = std::max(2, count);

        // this array will hold the representation of each character in the new base
        int digits[100]; // it said to have a maximum of 18 in the problem
        for (int i = 0; i < length; i++) {
            digits[i] = map[s[i]];
        }

        // now we need to convert from that base to base 10
        unsigned long long value = 0;
        unsigned long long mult = 1;
        for (int i = length-1; i >= 0; i--) {
            value += (digits[i]*mult);
            mult *= base;
        }
        printf("Case #%d: %llu\n", t, value);
    }
    end = clock();


    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    assert(time_spent < 3.1);
    return 0;
}
