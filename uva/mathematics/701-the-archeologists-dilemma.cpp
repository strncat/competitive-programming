//
//  701 - The Archeologists' Dilemma
//  100 days challenge
//
//  Created by FB on 9/22/17.
//  Copyright © 2017 FB. All rights reserved.
//

/*
 Okay so I couldn't figure out this one on my own but at least now I understand what I got wrong
 We have an integer N
 We need to find 2^E
 2^E has two parts:
  (1) the prefix which should exactly match N
  (2) the rest of the digits in 2^E which we call the lost digits or T. the number of lost digits should be
      greater than the number of digits in N

 Example we have N = 10
 Powers of 2 are:
 i=0  1
 i=1  2
 i=2  4
 ...
 i=10 1,024
 i=11 2,048
 ...
 i=20 1,048,576

 for N = 10, the total number of digits needs to be at least 5 (digits in 10 + lost digits (at least 3))

 First: 10,000 <= 2^E
 we can re-write this as N * 10^T <= 2^E
 Second: 2^E < 11,000 why? because remember the prefix must match N, so the number we're looking for must start with 10
 The next interval we can try is when T+1 where 100,000 <= 2^E < 110,000 and so on

 Now we have N * 10^T <= 2^E < (N+1) * 10^T
 We want to find E, so we take apply log

 lg(N * 10^T) <= E * lg2 < lg((N+1) * 10^T)
 lg(N) + Tlg(10) <= E < lg(N+1) + Tlg(10)

 Remember we are given N and we can calculate T initialy as the number of digits in N + 1
*/

#include <iostream>
#include <math.h>
#include <algorithm>

int main() {
    //freopen("example.in" , "r" , stdin);
    //freopen("example.out" , "w" , stdout);

    long int N;
    while (scanf("%ld", &N) != EOF) {

        int T = 0; // lost digits
        long temp = N;
        while (temp > 0) {
            T++;
            temp /= 10;
        }
        T++; // since the lost digits > digits in N

        bool match = false;
        int E = 0;
        while (1) {
            double left = log2(N) + T * log2(10);
            double right =  log2(N+1) + T * log2(10);
            // E must be greater than or equal to left but less than right
            // E must also be an integer so we can try ceil(left)
            // if that doesn't work we try a new T
            E = ceil(left);
            if (ceil(left) < right) { match = true; break; }
            T++; // when do we stop searching?
        }
        if (match) {
            printf("%d\n", E); // power of 2
        } else {
            printf("no power of 2\n");
        }
    }
    return 0;
}

