#include <stdio.h>
#include <string.h>

/* 10235 - Simply Emirp
 Sample Input
 17
 18
 19
 179
 199
 727
 Sample Output
 17 is emirp.
 18 is not prime.
 19 is prime.
 179 is emirp.
 199 is emirp.
 727 is prime.
*/

#define N 1000010 /* maximum word is 20 letters of Zs => total = 1040 */

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

int reverse(int n) {
    
    int reversed = 0;
    
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return reversed;
}

int main() {

    int number, reversed;
    
    primes();
    
    while (scanf("%d", &number) == 1) {
       
        if (prime[number]) {
            
            reversed = reverse(number);
            
            if (prime[reversed] && reversed != number)
                printf("%d is emirp.\n", number);
            else
                printf("%d is prime.\n", number);
        }
        else
            printf("%d is not prime.\n", number);
    }
    return 0;
}