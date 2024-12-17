//
//
//  Project Euler
//
//  Created by FB on 12/15/24.
//  24 Lexicographic Permutations https://projecteuler.net/problem=24
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <sstream>

bool next_permutation(std::vector<int>& a) {
    // (1) Find the right most pair such that a_i < a_i+1
    int i = -1;
    for (i = (int)a.size() - 2; i >= 0; i--) {
        if (a[i] < a[i+1]) {
            break;
        }
    }

    if (i == -1) { // no more permutations are possible
        return false;
    }

    // (2) Starting at i, we want to find the smallest number larger than a[i]
    int k = -1;
    for (int j = (int)a.size() - 1; j > i; j--) {
        if (a[j] > a[i]) {
            k = j;
            break;
        }
    }
    
    // (3) Swap and reverse from i+1 to the end
    std::swap(a[i], a[k]);
    std::reverse(a.begin() + (i+1), a.end());

    return true;
}


int main(int argc, const char * argv[]) {
    //freopen("triangle.txt" , "r" , stdin);
    clock_t begin, end;
    double time_spent;
    begin = clock();
    std::vector<int> a = {0,1,2,3,4,5,6,7,8,9};

    for (int i = 1; i < 1000000; i++) {
        if (!next_permutation(a)) {
            break;
        }
    };
    
    /*
    for (int i = 1; i < 1000000; i++) {
        if (!std::next_permutation(a.begin(), a.end())) {
            break;
        }
    };
    */
    
    // 2783915460
    for (int i : a) {
        std::cout << i;
    }
    printf("\n");
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}


