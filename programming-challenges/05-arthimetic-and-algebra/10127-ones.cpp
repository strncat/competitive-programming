//
//  10127 - Ones
//
//  Created by Fatima B on 10/23/15.
//  Copyright © 2015 nemo. All rights reserved.
//
/* so I got stuck with this problem at having m too large (line 21)
 I was doing m = m*10 + 1 with taking the extra %n and for a number 
 like 5241 the number of digits is 291 and nothing will fit
 
 solution:
 (a + b) % m = ((a % m) + (b % m)) % m
 (a x b) % m = ((a % m) x (b % m)) % m
 111 % n
*/

#include <iostream>

int ones(unsigned long long n) {
    unsigned long long m = 1;
    int digits = 1;
    while (1) { // totally depending on correct input
        if (m % n == 0) {
            return digits;
        }
        m = (m*10 + 1) % n; // next number append 1
        digits++;
    }
    return -1; // guaranteed not happening by the problem
}

int main() {
    unsigned long long n;
    while (scanf("%llu", &n) != EOF) {
        printf("%d\n", ones(n));
    }
    return 0;
}
