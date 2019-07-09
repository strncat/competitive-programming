//
//  Determine if a Poker Hand is a Straight Flush
//
//  Created by Fatima B on 12/24/15.
//  Copyright © 2015 Fatima B. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

// function to determine if the hand is a straight hand
bool is_straight(std::vector<int>& rank) {
    std::sort(rank.begin(), rank.end());
    for (int i = 1; i < 5; i++) {
        if (rank[i] - rank[i-1] != 1) {
            return false;
        }
    }
    return true;
}

// function to determine if the hand is a flush
bool is_flush(std::vector<char>& suit) {
    for (int i = 1; i < 5; i++) {
        if (suit[i] != suit[i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::vector<int> rank1, rank2;
    std::vector<char> suit;
    char f, s;

    for (int i = 0; i < 5; i++) {
        std::cin >> f >> s;
        suit.push_back(s);
        if (f == 'T') {
            rank1.push_back(10);
            rank2.push_back(10);
        } else if (f == 'J') {
            rank1.push_back(11);
            rank2.push_back(11);
        } else if (f == 'Q') {
            rank1.push_back(12);
            rank2.push_back(12);
        } else if (f == 'K') {
            rank1.push_back(13);
            rank2.push_back(13);
        } else if (f == 'A') {
            rank1.push_back(1);
            rank2.push_back(14);
        } else {
            rank1.push_back(f-'0');
            rank2.push_back(f-'0');
        }
    }

    // if flush and straight (using A=1 or A=14)
    if (is_flush(suit) && (is_straight(rank1) || is_straight(rank2))) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    return 0;
}
