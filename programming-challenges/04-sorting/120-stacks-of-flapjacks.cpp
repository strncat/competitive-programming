//
//  120 - Stacks of Flapjacks
//  100 days challenge
//
//  Created by FB on 9/22/17.
//  Copyright © 2017 FB. All rights reserved.
//

// Did I think of the algorithm myself? NOPE
// Is it pretty? Very pretty I won't forget it

#include <iostream>
#include <sstream>
#include <stack>

void print_cakes(int *cakes, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", cakes[i]);
    }
    printf("\n");
}

void flip(int *a, int index) {
    std::stack<int> s;
    for (int i = index; i >= 0; i--) {
        s.push(a[i]);
    }
    for (int i = index; i >= 0; i--) {
        a[i] = s.top();
        s.pop();
    }
}

void sort(int *cakes, int n) {
    int i = n - 1;
    for (; i >= 0; i--) { // n elements
        int max = -1;
        int current_index = -1;
        int optimal_index = i;
        for (int j = 0; j <= i; j++) {
            if (cakes[j] > max) {
                max = cakes[j];
                current_index = j;
            }
        }
        // move max to its correct location
        if (current_index != optimal_index) {
            printf("%d ", n - current_index);
            // flip the region between index 0 and current_index so that
            // current_index moves to the front, example 3 5 6 1 7
            // we flip it around index 3 so now we have 6 5 3 1 7
            flip(cakes, current_index);

            // flip around the optimal or correct location so
            // 6 5 3 1 7 -> 1 3 5 6 7 and repeat for each element
            printf("%d ", n - optimal_index);
            flip(cakes, optimal_index);
        }
    }
    printf("0\n");
}

int main() {
    //freopen("example.in", "r", stdin);
    int c, cakes[100];
    std::string s;
    while(std::getline(std::cin, s)){
        int n = 0;
        std::istringstream is(s);
        while(is >> c) {
            cakes[n++] = c;
        }
        print_cakes(cakes, n);
        sort(cakes, n);
        //print_cakes(cakes, n);
        //printf("\n\n");
    }
    return 0;
}
