#include <stdio.h>
#include <string.h>

/* 10924 - Prime Words
 Sample Input
 UFRN
 contest
 AcM
 Sample Output
 It is a prime word.
 It is not a prime word.
 It is not a prime word.
*/

#define N 1200 /* maximum word is 20 letters of Zs => total = 1040 */

int prime[N];

void primes() {
    
    int i, j;
    
    prime[1] = 1; /* The only trick in the problem */
    for (i = 2; i < N; i++)
        prime[i] = 1;
    
    for (i = 2; i <= N/2; i++)
        for (j = 2; j <= N/i; j++)
            prime[i*j] = 0;
}

int main() {

    char s[22];
    int i, length, sum, table[256], counter = 1;
    
    primes();
    
    for (i = 97; i < 123; i++) /* from a to z it is 1 to 26 */
        table[i] = counter++;
    
    for (i = 65; i < 91; i++) /* from A to Z it is 27 to 52 */
        table[i] = counter++;
    
    while (scanf("%s", s) == 1) {
       
        length = (int) strlen(s);
        sum = 0;
        
        for (i = 0; i < length; i++) /* sum the values according to the table built */
            sum += table[s[i]];
        
        if (prime[sum])
            printf("It is a prime word.\n");
        else
            printf("It is not a prime word.\n");
    }
    return 0;
}

