#include <stdio.h>

/* 543 - Goldbach's Conjecture
   http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=484
   6 <= n < 10,000,000
 8        8 = 3 + 5
 20       20 = 3 + 17
 42       42 = 5 + 37
 */

int isPrime(long int n) {
    
    int i;
    for(i = 2 ; i*i <= n ;i++)
        if(n%i == 0) 
            return 0;
    return 1;
}

int main() {
    
    long int n, i;
    int flag;
    
    while (scanf("%ld", &n) == 1) {
        
        if (n == 0)
            break;
        
        flag = 0;
        
        for(i=3; i < n ; i++) 
            if(isPrime(i) == 1 && isPrime(n-i)) {
                printf("%ld = %ld + %ld\n", n, i, (n-i));
                flag = 1;
                break;
            }
        
        if(!flag)
            printf("Goldbach's conjecture is wrong.\n");
        
    }
    
    return 0;
}


