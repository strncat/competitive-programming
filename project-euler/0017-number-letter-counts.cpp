//
//
//  Project Euler
//
//  Created by FB on 8/04/24.
//  17 Number Letter Counts https://projecteuler.net/problem=17
//
//

#include <iostream>
#include <math.h>
#include <algorithm>
#define N 500

std::string ones[11] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};
std::string teens[11] = {"", "eleven", "twelve",
    "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
std::string tens[11] = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety", "hundred"};

int ones_to_letters(int n) {
    int sum = 0;
    std::cout << ones[n];
    sum += ones[n].size();
    return sum;
}

int tens_to_letters(int n) {
    int sum = 0;
    std::cout << tens[n/10];
    sum += tens[n/10].size();
    int r = n%10;
    if (r > 0) {
        std::cout << " ";
        sum += ones_to_letters(r);
    }
    return sum;
}

int number_to_letters(int n) {
    int sum = 0;

    if (n <= 10) {
        sum += ones_to_letters(n);
        
    } else if (n <= 19) {
        std::cout << teens[n-10];
        sum += teens[n-10].size();
        
    } else if (n < 100) {
        sum += tens_to_letters(n);
        
    } else if (n < 1000) {
        int d = n/100;
        sum += ones_to_letters(d);
        std::cout << " hundred";
        sum += 7;
        
        int r = n%100;
        if (r > 19) {
            std::cout << " and ";
            sum += 3;
            std::cout << tens[r/10];
            sum += tens[r/10].size();
            
            int ones = r%10;
            if (ones > 0) {
                std::cout << "-";
                sum += ones_to_letters(ones);
            }
        } else if (r >= 11 && r <= 19) {
            std::cout << " and ";
            sum += 3;
            std::cout << teens[r-10];
            sum += teens[r-10].size();

        } else if (r > 0 && r <= 10) {
            std::cout << " and ";
            sum += 3;
            sum += ones_to_letters(r);
        }
    } else if (n == 1000) {
        std::cout << "one thousand";
        sum += 11;
    }
    
    return sum;
}

int main(int argc, const char * argv[]) {
    clock_t begin, end;
    double time_spent;
    begin = clock();
    
    unsigned long long sum = 0;

    for (int i = 1; i <= 1000; i++) {
        std::cout << i << ": ";
        sum += number_to_letters(i);
        std::cout << std::endl;
    }
    
    printf("total letters = %llu\n", sum);
    
    end = clock();
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("time spent = %f\n", time_spent);
        
    return 0;
}
//
