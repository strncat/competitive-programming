//
//  10183 - How Many Fibs?
//  100 days challenge
//
//  Created by FB on 9/22/17.
//  Copyright © 2017 FB. All rights reserved.
//

#include <iostream>
#include <math.h>
#include <algorithm>

// Fn = 1/sqrt(5) { [(1+sqrt(5))/2]^n - [(1-sqrt(5))/2]^n }
// the 490th Fibonacci number has 100 digits in it

#define MAXDIGITS 1000
#define PLUS +1
#define MINUS -1

// we're only dealing with positive integers here so much simpler
// this is based on programming challenges bignum, I just simplified it to handle positive integers only
typedef struct bignum {
    char digits[MAXDIGITS];
    int lastdigit; // index of last digit
} bignum;

void print_bignum(bignum *n) {
    for (int i = n->lastdigit; i >= 0; i--) {
        printf("%c", n->digits[i]+'0');
    }
    printf("\n");
}

void int_to_bignum(int s, bignum *n) {
    for (int i = 0; i < MAXDIGITS; i++) {
        n->digits[i] = (char) 0;
    }
    n->lastdigit = -1;
    int t = abs(s);

    while (t > 0) {
        n->lastdigit++;
        n->digits[n->lastdigit] = t % 10;
        t /= 10;
    }
    if (s == 0) { n->lastdigit = 0; }
}

void initialize_bignum(bignum *n) {
    int_to_bignum(0, n);
}

void zero_justify(bignum *n) {
    while (n->lastdigit > 0 && n->digits[n->lastdigit] == 0) {
        n->lastdigit--;
    }
}

int compare_bignum(bignum *a, bignum *b) { // is b larger?
    // compare the number of digits
    if (b->lastdigit > a->lastdigit) { return PLUS; }
    if (a->lastdigit > b->lastdigit) { return MINUS; }

    // both have the number of digits
    for (int i = a->lastdigit; i >= 0; i--) {
        if (a->digits[i] > b->digits[i]) { return MINUS; }
        if (b->digits[i] > a->digits[i]) { return PLUS; }
    }
    return 0; // equal
}

void add_bignum(bignum *a, bignum *b, bignum *c) {
    initialize_bignum(c);

    c->lastdigit = std::max(a->lastdigit, b->lastdigit)+1;
    int carry = 0;
    for (int i = 0; i <= c->lastdigit; i++) {
        c->digits[i] = (char) (carry + a->digits[i] + b->digits[i]) % 10;
        carry = (carry + a->digits[i] + b->digits[i]) / 10;
    }
    zero_justify(c);
}

bignum numbers[500];

void preload_fibonacci() {
    for (int i = 0; i < 500; i++) {
        initialize_bignum(&numbers[i]);
    }
    int_to_bignum(1, &numbers[1]); // F1 = 1
    int_to_bignum(1, &numbers[2]); // F2 = 1

    // starting at F3
    for (int i = 3; i < 490; i++) {
        add_bignum(&numbers[i-1], &numbers[i-2], &numbers[i]);
        //printf("i = %d\n", i);
        //print_bignum(&numbers[i]);
    }
}

int main() {
    //freopen("example.in" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    char temp1[10004], temp2[10004];
    preload_fibonacci();

    while (1) {
        char c;
        int i = 0, j = 0;
        while (scanf("%c", &c)) {
            if (c == ' ') { break; }
            temp1[i++] = c;
        }
        while (scanf("%c", &c)) {
            if (c == ' ' || c == '\n') { break; }
            temp2[j++] = c;
        }
        if (i == 1 && j == 1 && temp1[0] == '0' && temp2[0] == '0') {
            break;
        }

        bignum a, b;
        initialize_bignum(&a);
        initialize_bignum(&b);

        for (int k = 0; k < i; k++) {
            a.digits[k] = temp1[i-k-1]-'0';
        }
        a.lastdigit = i-1;
        for (int k = 0; k < j; k++) {
            b.digits[k] = temp2[j-k-1]-'0';
        }
        b.lastdigit = j-1;

        int index = 1;
        while(compare_bignum(&numbers[++index], &a) == PLUS) {
            // while a is larger continue
            //print_bignum(&numbers[i]);
        }
        // a is either lower or equal to numbers[i]

        int count = 0;
        while(compare_bignum(&numbers[index], &b) >= 0) {
            // while b is larger continue or equal to numbers[i]
            //print_bignum(&numbers[index]);
            count++;
            index++;
        }
        printf("%d\n", count);
    }
    return 0;
}

