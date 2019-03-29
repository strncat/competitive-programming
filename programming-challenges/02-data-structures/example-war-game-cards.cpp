//
//  chapter 2 data structures war game
//
//  Created by Fatima B on 10/23/15.
//  Copyright © 2015 nemo. All rights reserved.
//


#include <iostream>
#include <assert.h>

#define MAXQUEUESIZE 1000
#define MAXSTEPS 1000

typedef struct queue {
    int buffer[MAXQUEUESIZE];
    int index;
} queue;

void init_queue(queue *q) {
    q->index = 0;
}

void enqueue(queue *q, int value) {
    if (q->index >= MAXQUEUESIZE) { return; }
    q->buffer[q->index++] = value;
}

int dequeue(queue *q) {
    if (q->index == 0) { return -1; }
    int value = q->buffer[q->index-1];
    q->index--;
    return value;
}

bool empty(queue *q) {
    return (q->index == 0);
}

void clear_queue(queue *c, queue *q) {
    while (!empty(c)) {
        enqueue(q, dequeue(c));
    }
}

#define NSUITS 4
#define NCARDS 52

char suits[] = "cdhs";
char values[] = "23456789TJQKA";

char suit(int rank) {
    return suits[card%NSUITS];
}

char value(int rank) {
    return values[card/NSUITS];
}

int rank_card(char suit, char value) {
    for (int i = 0; i < NCARDS/NSUITS; i++) {
        if (values[i] == value) {
            for (int j = 0; j < NSUITS; j++) {
                if (suit == suits[j]) {
                    return i*NSUITS + j;
                }
            }
        }
    }
    return -1;
}

void tests() {
    assert(rank_card('h', '2') == 26);
}

void war(queue *a, queue *b) {
    int steps = 0;
    int x, y; // top cards
    queue c; // playing queue
    bool inwar = false;
    init_queue(&c);

    while (!empty(a) && !empty(b) && steps <= MAXSTEPS) {
        steps++;
        x = dequeue(a);
        y = dequeue(b);
        enqueue(&c, x);
        enqueue(&c, y);
        if (inwar) { // read carefully, if a tie, player play the next card
            // face down and then another card face up
            inwar = false;
        } else {
            if (value(x) > value (y)) { // player a gets the cards
                clear_queue(&c, a);
            } else if (value(x) < value(y)) { // player b gets the cards
                clear_queue(&c, b);
            } else {
                inwar = true;
            }
        }
    }

    if (empty(a) && !empty(b)) {
        printf("a wins in %d steps\n", steps);
    } else if (empty(b) && !empty(b) ) {
        printf("b wins in %d steps\n", steps);
    } else {
        printf("it's a tie %d steps", steps);
    }
}

int main() {
    //tests();
    char c, value, suit;
    queue deck[2];
    while (true) {
        for (int i = 0; i <= 1; i++) {
            init_queue(&deck[i]);

            while ((c = getchar()) != '\n') {
                if (c == EOF) { return 0; }
                if (c != ' ') {
                    value = c;
                    suit = getchar();
                    enqueue(&deck[i], rank_card(suit, value));
                }
            }
        }

        war(&deck[0], &deck[1]);
    }
    return 0;
}
