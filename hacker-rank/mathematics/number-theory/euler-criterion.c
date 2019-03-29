//
//  HackerRank Euler's Criterion:
//  Given A and M is there a solution to A ≡ X^2 (mod M)?
//  In number theory, an integer q is called a "quadratic residue" modulo n if it is congruent to a "perfect square" modulo n
//  Euler's criterion is a formula for determining whether an integer is a quadratic residue modulo a prime.
//  You take A^((p-1)/2) % p, if it equals 1 then A is a quadratic residue module a prime number
//  Example take p = 7 and A = 4 is A a quadratic residue mod 7? is there an X such that 4 ≡ X^2 (mod 7)
//  The answer is YES, take x = 2 x^2 = 4 ≡ 4 (mod 7)
//
//
//  Created by FB on 2/1/15.
//  Copyright (c) 2015 nemo. All rights reserved.
//

#include <stdio.h>
#include <math.h>
long int mod_binary(long int a, long int e, long int m) { // O(n) a^e mod m = ((a % m) (a % m) .. (a % m)) %m
    if (e == 1) {
        return a % m;
    } else if (e == 0) {
        return 1;
    } else {
        long int result = mod_binary(a, e / 2, m);
        if (e % 2 == 1) {
            long int temp = (result * result) % m;
            temp *= (a % m);
            temp %= m;
            return temp;
        } else {
            return (result * result) % m;
        }
    }
}

int main() {
    int cases, a, m;
    
    scanf("%d", &cases);
    while (cases--) {
        scanf("%d %d", &a, &m);
        long long result = mod_binary(a, ((m - 1)/2), m);
        if (result == 1 || a == 0 || a == 2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
        
    }
    return 0;
}
