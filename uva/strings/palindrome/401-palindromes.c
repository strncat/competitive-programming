#include <stdio.h>
#include <string.h>

/* 401 - Palindromes
 Sample Input
 NOTAPALINDROME
 ISAPALINILAPASI
 2A3MEAS
 ATOYOTA
 Sample Output
 
 NOTAPALINDROME -- is not a palindrome.
 
 ISAPALINILAPASI -- is a regular palindrome.
 
 2A3MEAS -- is a mirrored string.
 
 ATOYOTA -- is a mirrored palindrome.
*/

char reverse[256];

int main() {
    
    int i, mid, length, palindrome, mirrored;
    char s[1000];
    
    reverse['A'] = 'A';  reverse['B'] = '-';  reverse['C'] = '-';  reverse['D'] = '-';
    reverse['E'] = '3';  reverse['F'] = '-';  reverse['G'] = '-';  reverse['H'] = 'H';
    reverse['I'] = 'I';  reverse['J'] = 'L'; reverse['K'] = '-';  reverse['L'] = 'J';
    reverse['M'] = 'M';  reverse['N'] = '-';  reverse['O'] = 'O'; reverse['P'] = '-';
    reverse['Q'] = '-';   reverse['R'] = '-';  reverse['S'] = '2'; reverse['T'] = 'T';
    reverse['U'] = 'U';  reverse['V'] = 'V'; reverse['W'] = 'W'; reverse['X'] = 'X';
    reverse['Y'] = 'Y';  reverse['Z'] = '5'; reverse['1'] = '1'; reverse['2'] = 'S';
    reverse['3'] = 'E';  reverse['4'] = '-';  reverse['5'] = 'Z'; reverse['6'] = '-';
    reverse['7'] = '-';   reverse['8'] = '8'; reverse['9'] = '-';
    
    /* O (zero) and 0 (the letter) are considered the same character and therefore ONLY the letter "0" is a valid character. */

    while (scanf("%s", s) == 1) {
        
        length = (int) strlen(s);
        mid = length / 2;
        
        palindrome = 1;
        mirrored = 1;
        for (i = 0; i <= mid; i++) {
            if (s[i] != s[length - 1 - i])
                palindrome = 0;
            
            if (s[i] != reverse[s[length - 1 - i]])
                mirrored = 0;
        }
        
        if (palindrome && mirrored)
            printf("%s -- is a mirrored palindrome.\n\n", s);
        else if (palindrome)
            printf("%s -- is a regular palindrome.\n\n", s);
        else if (mirrored)
            printf("%s -- is a mirrored string.\n\n", s);
        else
            printf("%s -- is not a palindrome.\n\n", s);
    }
    
    
    return 0;
}