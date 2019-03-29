//
//  Problem A. Magic Trick
//  https://code.google.com/codejam/contest/2974486/dashboard
//
//  Created by Fatima Broom on 2/27/16.
//  Copyright © 2016 Fatima Broom. All rights reserved.
//

#include <iostream>
#include <time.h>
#include <assert.h>
#include <vector>
#include <unordered_map>

int main() {
    // measure time
    clock_t begin, end;
    double time_spent;
    begin = clock();

    freopen("in-small.txt" , "r" , stdin);
    freopen("out-small.txt" , "w" , stdout);

    int n;
    scanf("%d", &n);

    for (int t = 1; t <= n; t++) {

        // the array cards will hold the two rows we care about
        int c, r1, r2, cards[17] = {0};

        // read the cards but we only store the cards in the row we care about
        scanf("%d", &r1); r1--;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &c);
                if (i == r1) { // row selected
                    cards[c]++;
                }
            }
        }

        scanf("%d", &r2); r2--;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &c);
                if (i == r2) { // row selected
                    cards[c]++;
                }
            }
        }

        // after reading the two rows we will have each card and the number
        // of times we saw this card
        int selected = 0, num2s = 0;
        for (int i = 1; i <= 16; i++) {
            if (cards[i] == 2) { // we count the number of cards tht we repeated
                num2s++;
                selected = i;
            }
        }

        // if we only have one card that was repeated then this the card chosen by the player
        if (num2s == 1) { // only one card matched
            printf("Case #%d: %d\n", t, selected);
        } else if (num2s > 1) { // more than one card matched, the magician can't determine the card
            printf("Case #%d: Bad magician!\n", t);
            continue;
        } else { // we don't have any card repeated
             printf("Case #%d: Volunteer cheated!\n", t);
        }

    }

    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    assert(time_spent < 3.1); // because in practice problems you only submit the output
    return 0;
}
