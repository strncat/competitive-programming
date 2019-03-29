#include <stdio.h>
/* UVa - [492 - Pig-Latin]
 Sample Input
 This is the input.
 He is a boy.
 
 Object123oriented,..,.Programming
 000000000
 aaaaaaaaaaaa
 Aaaaaaaaaaaa
 computerprogrammingII
 cse-1204 Computer programming II
 ACM programming contest was held on 10th November, 2001 at BUET.
 an a eye An A Eye Bee BEE Dhaka-1205 1st last.
 Sample Output
 hisTay isay hetay inputay.
 eHay isay aay oybay.
 
 Objectay123orienteday,..,.rogrammingPay
 000000000
 aaaaaaaaaaaaay
 Aaaaaaaaaaaaay
 omputerprogrammingIIcay
 secay-1204 omputerCay rogrammingpay IIay
 ACMay rogrammingpay ontestcay asway eldhay onay 10htay ovemberNay, 2001 atay UETBay.
 anay aay eyeay Anay Aay Eyeay eeBay EEBay hakaDay-1205 1tsay astlay.
 */

int is_vowel(char c) {
    
    if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'O' || c == 'o' || c == 'U' || c == 'u')
        return 1;
    
    return 0;
}

int is_letter(char c) {
    
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return 1;
    
    return 0;
}

int main() {
    
    char c, skip_c;
    int append = 0, new_word = 1, skip = 0;
    
    while (scanf("%c", &c) != EOF) {
        
        if (new_word) { /* begining of a new word */
            
            new_word = 0;
            if (is_letter(c)) { /* word begins with a letter */
                
                append = 1; /* append ay anyways */
                if (!is_vowel(c)) { /* word begins with a consonant */
                    
                    skip = 1; /* skip first letter to be added at the end */
                    skip_c = c;
                    continue;
                }
            }
        }
        
        if (is_letter(c) == 0) { /* end of a word */
            
            new_word = 1;
            if (append) {
                
                if (skip) { /* before append, add the skipped letter */
                    printf("%c", skip_c);
                    skip = 0;
                }
                printf("ay");
                append = 0;
            }
        }
        printf("%c", c);
    }
    
    return 0;
}

