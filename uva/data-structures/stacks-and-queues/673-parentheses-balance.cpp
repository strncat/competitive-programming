//
//  673 - Parentheses Balance
// BEAWAREEEEE test cases can have SPACES!!!!!
//
//  Created by Fatima B on 10/14/15.
//  Copyright © 2015 nemo. All rights reserved.
//

#include <iostream>
#include <assert.h>
#include <string.h>
#include <stack>

bool is_balanced(std::string s) {
    std::stack<char> t;

    for (int i = 0; i < s.length(); i++) {

        if (s[i] == '(' || s[i] == '[') {
            t.push(s[i]);
        }

        else if (s[i] == ')') {
            if (t.empty() || t.top() != '(') { return false; }
            t.pop();
        }

        else if (s[i] == ']') {
            if (t.empty() || t.top() != '[') { return false; }
            t.pop();
        }
    }
    return t.empty();
}

void tests() {
    std::string s[6] = {"", "([])", "(([()])))", "([()[]()])()", "([ ()[  ]  ( )])()", "([)]"};
    bool correct[6] {true, true, false, true, true, false};
    for (int i = 0; i < 5; i++) {
        assert(is_balanced(s[i]) == correct[i]);
    }
}

int main() {
    //tests();
    int test_cases;
    scanf("%d\n", &test_cases); // IMPORTANT TO GET THAT FREAKING NEW LINE
    std::string s;
    while (test_cases--) {
        getline(std::cin, s); // test cases can have SPACES!!!!!
        if (is_balanced(s)) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
    return 0;
}
