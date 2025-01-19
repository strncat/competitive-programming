//
//
//  Project Euler
//
//  Created by FB on 01/14/25.
//  Problem 36: Double-base Palindromes https://projecteuler.net/problem=36
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <unordered_map>
#include <functional>
#include <utility>


int is_palindrome(int n, int base) {
    int reversed = 0;
    int num = n;
    while (num > 0) {
        reversed = (reversed * base) + (num % base);
        num = num / base;
    }
    return (reversed == n);
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    int sum = 0;
    for (int i = 1; i < 1000000; i++) {
        if (is_palindrome(i, 10)) {
            // now check base2
            if (is_palindrome(i, 2)) {
                sum += i;
            }
        }
    }
    printf("sum = %d\n", sum);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}

/* the extremely naive solution which also works is here

int generate_base2(int num, int *a) {
    int n = 0;
    while (num > 0) {
        a[n++] = num%2;
        num /= 2;
    }
    return n;
}

int generate_digits(int num, int *digits) {
    int n = num;
    int count = 0;
    while (n > 0) {
        digits[count++] = n%10;
        n /= 10;
    }
    return count;
}

bool is_palindrome(int *a, int n) { // O(n) method to find if a number is palindrome
    int j = n - 1;
    int i = 0;
    while (i < j) {
        if (a[i++] != a[j--]) {
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    int base10[10] = {0}, n = 0;
    int base2[20] = {0};
    int sum = 0;
    for (int i = 1; i < 1000000; i++) {
        n = generate_digits(i, base10);
        if (is_palindrome(base10, n)) {
            //printf("%d is palindrome in base 10\n", i);
            // now check base2
            n = generate_base2(i, base2);
            if (is_palindrome(base2, n)) {
                //printf("it's also palindrome in base 2\n");
                sum += i;
            }
        }
    }
    printf("sum = %d\n", sum);
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
    return 0;
}

*/
