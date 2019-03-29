/*
 ID: fatima.1
 PROG: crypt1
 LANG: C++11
 */
//
//  Usaco Training
//  1.3 Prime Cryptarithm
//

// lessons: the way I thought about this originally was to iterate thru all possible permutations
// of the N numbers given that's N^N and then! check if it's valid .. etc
// while the easy approach or the in your face approach is to simply notice the restriction on the
// the numbers "2 digits" multipled by "3 digits" so just iterate thru all 1 to 99 and then 1 to 999

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

void print(std::vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

bool find(std::vector<int> a, int x) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == x) {
            return true;
        }
    }
    return false;
}

bool checkDigits(int product, std::vector<int> a) {
    if (product == 0 && !find(a, 0)) { return false; }
    while (product) {
        if (!find(a, product % 10)) {
            break;
        }
        product /= 10;
    }
    if (product == 0) { return true; }
    return false;
}

bool test(int i, int j, std::vector<int> valid) {
    // partial products
    int p1 = j * (i / 10);
    int p2 = j * (i % 10);

    // if any exceeds 3 digits, quit
    if (p1 > 999 || p2 > 999) {
        return false;
    }

    // check that both p1 and p2 are from the valid set of digits
    if (!checkDigits(p1, valid) || !checkDigits(p2, valid)) {
        return false;
    }
    return checkDigits(p1*10 + p2, valid);
}

int main() {
    freopen("crypt1.in", "r", stdin);
    freopen("crypt1.out", "w", stdout);

    int n, temp;
    scanf("%d", &n);

    std::vector<int> valid;
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        valid.push_back(temp);
    }

    int solutions = 0;
    for (int i = 10; i < 100; i++) {
        for (int j = 100; j < 1000; j++) {
            if (checkDigits(i, valid) && checkDigits(j, valid) && test(i, j, valid)) {
                solutions++;
            }
        }
    }

    printf("%d\n", solutions);
    return 0;
}
