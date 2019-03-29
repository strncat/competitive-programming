//
//  main.cpp
//  uhunt
//
//  10315 - Poker Hand
//  2017/02/25
//
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using std::vector;
using std::unordered_map;
using std::string;

typedef enum {BLACK, WHITE, TIE, INVALID} winner;

typedef struct card {
    char suit;
    char number;
    int value;
    card(char s, char n) {
        const char numbers[] = "23456789TJQKA";
        suit = s;
        number = n;
        for (int i = 0; i < 14; i++) {
            if (numbers[i] == number) {
                value = i;
                break;
            }
        }
    }
    card(int v) {
        value = v;
    }
} card;

bool compare(const card &a, const card &b) {
    return a.value > b.value;
}

winner highest_card(vector<card>& black, vector<card>& white) { // assuming sorted
    for (int i = 0; i < black.size(); i++) {
        if (black[i].value > white[i].value) {
            return BLACK;
        } else if (white[i].value > black[i].value) {
            return WHITE;
        }
    }
    return TIE;
}

bool same_suit(vector<card>& c) {
    for (int i = 0; i < c.size()-1; i++) {
        if (c[i].suit != c[i+1].suit) {
            return false;
        }
    }
    return true;
}

bool consecutive_values(vector<card>& c) {
    for (int i = 0; i < c.size()-1; i++) {
        if (abs(c[i+1].value - c[i].value) != 1) { return false; }
    }
    return true;
}

int has_n_cards(unordered_map<int,int>& m, int c) {
    for (auto i = m.begin(); i != m.end(); i++) {
        if (i->second == c) {
            m[i->first] = 0; // IMPORTANT take it out
            return i->first;
        }
    }
    return -1;
}

// removes used cards and re-sort the cards
void clear_cards(vector<card>& black, vector<card>& white,
                 unordered_map<int,int>& bm,
                 unordered_map<int,int>& wm) {
    black.clear();
    white.clear();
    for (auto i = bm.begin(); i != bm.end(); i++) {
        if (i->second > 0) {
            black.push_back(card(i->first));
        }
    }
    for (auto i = wm.begin(); i != wm.end(); i++) {
        if (i->second > 0) {
            white.push_back(card(i->first));
        }
    }
    std::sort(black.begin(), black.end(), compare);
    std::sort(white.begin(), white.end(), compare);
}

winner find_winner(vector<card>& black, vector<card>& white) { // two hands a and b
    // sort --------------------------
    std::sort(black.begin(), black.end(), compare);
    std::sort(white.begin(), white.end(), compare);


    // maps --------------------------
    unordered_map<int,int> blackmap;
    unordered_map<int,int> whitemap;

    for (int i = 0; i < black.size(); i++) {
        if (blackmap.find(black[i].value) == blackmap.end()) {
            blackmap[black[i].value] = 1;
        } else {
            blackmap[black[i].value]++;
        }
    }

    for (int i = 0; i < white.size(); i++) {
        if (whitemap.find(white[i].value) == whitemap.end()) {
            whitemap[white[i].value] = 1;
        } else {
            whitemap[white[i].value]++;
        }
    }

    bool black_same_suit = same_suit(black);
    bool white_same_suit = same_suit(white);

    bool black_consecutive = consecutive_values(black);
    bool white_consecutive = consecutive_values(white);


    // straight flush --------------------------------
    if (black_same_suit && black_consecutive &&
        white_same_suit && white_consecutive) {
        return highest_card(black, white);
    }

    if (black_same_suit && black_consecutive) {
        return BLACK;
    }

    if (white_same_suit && white_consecutive) {
        return WHITE;
    }


    // four of a kind ---------------------------------
    int blackfour = has_n_cards(blackmap, 4);
    int whitefour = has_n_cards(whitemap, 4);

    // both have it, one has to win or a tie
    if (blackfour != -1 && whitefour != -1) {
        if (blackfour == whitefour) {
            clear_cards(black, white, blackmap, whitemap);
            return highest_card(black, white);
        }
        if (blackfour > whitefour) { return BLACK; }
        if (whitefour > blackfour) { return WHITE; }

    }
    // either might have it
    if (blackfour != -1) { return BLACK; }
    if (whitefour != -1) { return WHITE; }


    // full house ---------------------------------------
    int blackthree = has_n_cards(blackmap, 3); // has 3 same cards
    int whitethree = has_n_cards(whitemap, 3);

    int blackpair = has_n_cards(blackmap, 2); // has 2 same cards
    int whitepair = has_n_cards(whitemap, 2);

    // both have full houses
    if (blackthree != -1 && blackpair != -1 &&
        whitethree != -1 && whitepair != -1) {

        if (blackthree == whitethree && blackpair == whitepair) { return TIE; }

        //  "Ranked by the value of the 3 cards."
        if (blackthree > whitethree) { return BLACK; }
        if (whitethree > blackthree) { return WHITE; }

        // threes are equal, check the pair
        if (blackpair > whitepair) { return BLACK; }
        if (whitepair > blackpair) { return WHITE; }
    }

    // either might have a full house
    if (blackthree != -1 && blackpair != -1) { return BLACK; }
    if (whitethree != -1 && whitepair != -1) {  return WHITE; }


    // flush --------------------------------------------
    // both have it, return the highest card
    if (black_same_suit && white_same_suit) {
        return highest_card(black, white);
    }
    if (black_same_suit) { return BLACK; }
    if (white_same_suit) { return WHITE; }


    // straight -----------------------------------------
    if (black_consecutive && white_consecutive) {
            return highest_card(black, white);
    }

    if (black_consecutive) { return BLACK; }
    if (white_consecutive) { return WHITE; }


    // three of a kind -----------------------------------
    if (blackthree != -1 && whitethree != -1) {
        if (blackthree == whitethree) {
            clear_cards(black, white, blackmap, whitemap);
            return highest_card(black, white);
        }
        if (blackthree > whitethree) { return BLACK; }
        if (whitethree > blackthree) { return WHITE; }
    }
    if (blackthree != -1) { return BLACK; }
    if (whitethree != -1) { return WHITE; }


    // two pairs -----------------------------------
    int blackpair2 = has_n_cards(blackmap, 2);
    int whitepair2 = has_n_cards(whitemap, 2);

    // both have two pairs
    if (blackpair != -1 && blackpair2 != -1 &&
        whitepair != -1 && whitepair2 != -1) {

        // same value for both pairs
        if ((blackpair == whitepair && blackpair2 == whitepair2) ||
            (blackpair == whitepair2 && blackpair2 == whitepair)) {
            clear_cards(black, white, blackmap, whitemap);
            return highest_card(black, white); // remaining card
        }

        // one has to be better
        int bmax = blackpair > blackpair2 ? blackpair : blackpair2;
        int amax = whitepair > whitepair2 ? whitepair : whitepair2;

        int bmin = blackpair < blackpair2 ? blackpair : blackpair2;
        int amin = whitepair < whitepair2 ? whitepair : whitepair2;

        if (bmax > amax) { return BLACK; }
        if (bmax < amax) { return WHITE; }

        if (bmin > amin) { return BLACK; }
        if (amin > bmin) { return WHITE; }
    }

    // wither black or white both pairs
    if (blackpair != -1 && blackpair2 != -1) { return BLACK; }
    if (whitepair != -1 && whitepair2 != -1) { return WHITE; }


    // one pair -----------------------------------
    if (blackpair != -1 && whitepair != -1) { // both have a pair
        if (blackpair == whitepair) { // same pair
            clear_cards(black, white, blackmap, whitemap);
            return highest_card(black, white);
        }
        return blackpair > whitepair ? BLACK : WHITE;
    }
    if (blackpair != -1) { return BLACK; }
    if (whitepair != -1) { return WHITE; }


    return highest_card(black, white);
}

int main() {
    //freopen("sample.in", "r", stdin);
    char c[2];
    vector<card> black;
    vector<card> white;

    while (1) {
        white.clear();
        black.clear();
        for (int i = 0; i < 5; i++) {
            if (scanf("%s", c) != 1) { return 0; }
            black.push_back(card(c[1], c[0]));
        }
        for (int i = 0; i < 5; i++) {
            if (scanf("%s", c) != 1) { return 0; }
            white.push_back(card(c[1], c[0]));
        }

        winner p = find_winner(black, white);
        if (p == WHITE) {
            printf("White wins.\n");
        } else if (p == BLACK) {
            printf("Black wins.\n");
        } else {
            printf("Tie.\n");
        }
    }
    return 0;
}
